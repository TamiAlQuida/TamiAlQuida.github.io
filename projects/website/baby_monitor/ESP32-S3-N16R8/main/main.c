// ESP32-S3-N16R8 Baby Monitor - Simple I2S Audio Streaming
// Uses HTTP GET streaming for audio data

// cd ~/esp-idf && . export.sh && cd
// ~/TamiAlQuida.github.io/projects/website/baby_monitor/ESP32-S3-N16R8 &&
// idf.py build && idf.py -p /dev/ttyUSB0 flash monitor

#include "driver/i2s_std.h"
i2s_chan_handle_t rx_chan_handle = NULL;

#include "esp_event.h"
#include "esp_http_server.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_timer.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include "nvs_flash.h"

// WiFi
#define WIFI_SSID "BabyMonitor_5GHz"
#define WIFI_PASSWORD "TamiQuida2025"
#define WIFI_AUTH_WPA2_PSK 3

// I2S Configuration
#define I2S_PORT I2S_NUM_0
#define SAMPLE_RATE 16000
#define DMA_BUF_COUNT 8
#define DMA_BUF_LEN 512
#define TAG "baby_monitor"

static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data);
// Global variables
static EventGroupHandle_t s_wifi_event_group = NULL;
#define WIFI_CONNECTED_BIT BIT0
static httpd_handle_t server = NULL;
static uint8_t audio_buffer[DMA_BUF_LEN];

// I2S buffers

// HTTP audio streaming handler
static esp_err_t audio_stream_cb(httpd_req_t *req) {
  static int64_t last_frame_time = 0;
  static int samples_since_update = 0;

  // Reset if no frames for 5 seconds
  if (samples_since_update > (SAMPLE_RATE * 5) / SAMPLE_RATE) {
    last_frame_time = 0;
    samples_since_update = 0;
  }

  // Get current time

  // Read from I2S continuous stream
  size_t bytes_read = 0;
  i2s_channel_read(rx_chan_handle, audio_buffer, DMA_BUF_LEN, &bytes_read,
                   1000);
  size_t to_read = bytes_read;

  if (to_read > 0) {
    samples_since_update = 0;

    // Set response headers for audio streaming
    httpd_resp_set_type(req, "audio/webm");
    httpd_resp_set_hdr(req, "Cache-Control", "no-cache");
    httpd_resp_set_hdr(req, "Connection", "keep-alive");
    httpd_resp_send_chunk(req, (const char *)audio_buffer, to_read);
  } else {
    // Send empty chunk to keep connection alive
    if (last_frame_time == 0) {
      httpd_resp_set_type(req, "audio/webm");
      httpd_resp_set_hdr(req, "Cache-Control", "no-cache");
      httpd_resp_set_hdr(req, "Connection", "keep-alive");
      httpd_resp_send_chunk(req, NULL, 0);
    }
  }

  samples_since_update++;
  return ESP_OK;
}

// WiFi init
static void wifi_init(void) {
  ESP_ERROR_CHECK(esp_netif_init());
  ESP_ERROR_CHECK(esp_event_loop_create_default());
  esp_netif_create_default_wifi_sta();

  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&cfg));

  esp_event_handler_instance_t instance_got_ip;
  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL,
      &instance_got_ip));

  wifi_config_t wifi_config = {
      .sta =
          {
              .ssid = WIFI_SSID,
              .password = WIFI_PASSWORD,

              .threshold.authmode = WIFI_AUTH_WPA2_PSK,
          },
  };
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
  ESP_ERROR_CHECK(esp_wifi_start());

  ESP_LOGI(TAG, "WiFi init done!");
}

// WiFi event handler
static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data) {
  if (event_id == IP_EVENT_STA_GOT_IP) {
    ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
    ESP_LOGI(TAG, "Connected! IP: " IPSTR, IP2STR(&event->ip_info.ip));
    xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
  }
}

// I2S init
static void i2s_init(void) {
  ESP_LOGI(TAG, "Configuring I2S Standard Driver...");

  i2s_chan_config_t chan_cfg =
      I2S_CHANNEL_DEFAULT_CONFIG(I2S_PORT, I2S_ROLE_MASTER);
  ESP_ERROR_CHECK(i2s_new_channel(&chan_cfg, NULL, &rx_chan_handle));

  i2s_std_config_t std_cfg = {
      .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(SAMPLE_RATE),
      .slot_cfg = I2S_STD_PHILIPS_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_16BIT,
                                                      I2S_SLOT_MODE_MONO),
      .gpio_cfg =
          {
              .mclk = I2S_GPIO_UNUSED, // INMP441 doesn't need MCLK
              .bclk = GPIO_NUM_4,      // Replace with your BCLK pin
              .ws = GPIO_NUM_5,        // Replace with your WS (L/R) pin
              .dout = I2S_GPIO_UNUSED,
              .din = GPIO_NUM_6, // Replace with your DATA IN pin
              .invert_flags =
                  {
                      .mclk_inv = false,
                      .bclk_inv = false,
                      .ws_inv = false,
                  },
          },
  };

  ESP_ERROR_CHECK(i2s_channel_init_std_mode(rx_chan_handle, &std_cfg));
  ESP_ERROR_CHECK(i2s_channel_enable(rx_chan_handle));

  ESP_LOGI(TAG, "I2S configured: %d Hz, 16-bit, mono", SAMPLE_RATE);
}

// Initialize HTTP server
static void http_server_init(void) {
  ESP_LOGI(TAG, "Starting HTTP server...");

  httpd_config_t config = HTTPD_DEFAULT_CONFIG();

  // Initialize NVS
  ESP_ERROR_CHECK(nvs_flash_init());

  // Create default WiFi STA netif
  ESP_ERROR_CHECK(esp_netif_init());
  ESP_ERROR_CHECK(esp_event_loop_create_default());
  esp_netif_create_default_wifi_sta();

  // Register event handlers
  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL, NULL));

  // WiFi configuration
  wifi_config_t wifi_config = {
      .sta =
          {
              .ssid = WIFI_SSID,
              .password = WIFI_PASSWORD,

              .threshold.authmode = WIFI_AUTH_WPA2_PSK,
          },
  };

  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
  ESP_ERROR_CHECK(esp_wifi_start());

  ESP_LOGI(TAG, "WiFi init done!");

  // Initialize I2S
  i2s_init();

  // Set up HTTP URI handlers
  httpd_uri_t audio_uri = {.uri = "/audio",
                           .method = HTTP_GET | HTTP_OPTIONS,
                           .handler = audio_stream_cb,
                           .user_ctx = NULL};

  // Start HTTP server
  ESP_ERROR_CHECK(httpd_start(&server, &config));
  httpd_register_uri_handler(server, &audio_uri);

  ESP_LOGI(TAG, "HTTP server started!");
  ESP_LOGI(TAG, "Get audio data at: http://%s/audio", "127.0.0.1");
  ESP_LOGI(TAG, "Stream configured.");
}

// Event handler
static void event_handler(void *arg, esp_event_base_t event_base,
                          int32_t event_id, void *event_data) {
  if (event_id == IP_EVENT_STA_GOT_IP) {
    ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
    ESP_LOGI(TAG, "WiFi got IP: " IPSTR, IP2STR(&event->ip_info.ip));
    // Start HTTP server after WiFi connection
    http_server_init();
  }
}

// Main function
void app_main(void) {
  ESP_LOGI(TAG, "Starting Baby Monitor...");

  // Initialize NVS
  ESP_ERROR_CHECK(nvs_flash_init());

  // Create default event loop
  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      IP_EVENT, IP_EVENT_STA_GOT_IP, event_handler, NULL, NULL));

  // Initialize network interfaces
  ESP_ERROR_CHECK(esp_netif_init());
  ESP_ERROR_CHECK(esp_event_loop_create_default());

  // Create WiFi sta instance
  esp_netif_create_default_wifi_sta();

  // Initialize WiFi
  wifi_init();

  // Start HTTP server
  http_server_init();

  ESP_LOGI(TAG, "Baby Monitor is running!");
}
