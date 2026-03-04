// ESP32-S3-N16R8 Baby Monitor (sound only) using INMP441 as microphone. This
// will be connected to the I2S interface of the ESP32-S3-N16R8. The
// ESP32-S3-N16R8 will be connected to
// /home/tomcarl/TamiAlQuida.github.io/projects/website/NextJS/home/app/surveillance/page.tsx

// esp-idf master  ✗ . ./export.sh

// https://documentation.espressif.com/esp32-s3_datasheet_en.pdf

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include <driver/i2s.h>

// =============================================================================
// Configuration — adjust these to match your setup
// =============================================================================

// WiFi credentials
const char *WIFI_SSID = "YOUR_SSID";
const char *WIFI_PASSWORD = "YOUR_PASSWORD";

// I2S pin assignments for INMP441
#define I2S_SCK_PIN 42 // Serial Clock (BCLK)
#define I2S_WS_PIN 2   // Word Select (LRCLK)
#define I2S_SD_PIN 41  // Serial Data (DOUT from mic)

// Audio parameters
#define SAMPLE_RATE 16000 // 16 kHz — good for voice
#define BITS_PER_SAMPLE I2S_BITS_PER_SAMPLE_16BIT
#define I2S_PORT I2S_NUM_0
#define DMA_BUF_COUNT 8
#define DMA_BUF_LEN 512

// WebSocket server port
#define WS_PORT 81

// Buffer size for reading I2S samples (in bytes)
// 512 samples * 2 bytes per sample = 1024 bytes per frame
#define I2S_READ_BUF_SIZE (DMA_BUF_LEN * sizeof(int16_t))

// =============================================================================
// Globals
// =============================================================================

AsyncWebServer server(WS_PORT);
AsyncWebSocket ws("/ws");

int16_t i2sReadBuffer[DMA_BUF_LEN];

// =============================================================================
// I2S Setup
// =============================================================================

void setupI2S() {
  Serial.println("[I2S] Configuring INMP441 microphone...");

  const i2s_config_t i2s_config = {
      .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
      .sample_rate = SAMPLE_RATE,
      .bits_per_sample = BITS_PER_SAMPLE,
      .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT, // INMP441 L/R pin = GND
      .communication_format = I2S_COMM_FORMAT_STAND_I2S,
      .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
      .dma_buf_count = DMA_BUF_COUNT,
      .dma_buf_len = DMA_BUF_LEN,
      .use_apll = false,
      .tx_desc_auto_clear = false,
      .fixed_mclk = 0,
  };

  const i2s_pin_config_t pin_config = {
      .bck_io_num = I2S_SCK_PIN,
      .ws_io_num = I2S_WS_PIN,
      .data_out_num = I2S_PIN_NO_CHANGE, // Not transmitting
      .data_in_num = I2S_SD_PIN,
  };

  esp_err_t err;

  err = i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
  if (err != ESP_OK) {
    Serial.printf("[I2S] ERROR: Driver install failed: %d\n", err);
    return;
  }

  err = i2s_set_pin(I2S_PORT, &pin_config);
  if (err != ESP_OK) {
    Serial.printf("[I2S] ERROR: Pin config failed: %d\n", err);
    return;
  }

  // Clear any garbage in the DMA buffers
  i2s_zero_dma_buffer(I2S_PORT);

  Serial.printf("[I2S] Configured: %d Hz, %d-bit, mono\n", SAMPLE_RATE, 16);
}

// =============================================================================
// WiFi Setup
// =============================================================================

void setupWiFi() {
  Serial.printf("[WiFi] Connecting to %s", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  WiFi.setSleep(false); // Disable WiFi sleep for low-latency streaming

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    attempts++;
    if (attempts > 40) { // 20 second timeout
      Serial.println("\n[WiFi] ERROR: Connection failed! Restarting...");
      ESP.restart();
    }
  }

  Serial.printf("\n[WiFi] Connected! IP: %s\n",
                WiFi.localIP().toString().c_str());
}

// =============================================================================
// WebSocket Events
// =============================================================================

void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client,
                      AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
  case WS_EVT_CONNECT:
    Serial.printf("[WS] Client #%u connected from %s\n", client->id(),
                  client->remoteIP().toString().c_str());
    break;

  case WS_EVT_DISCONNECT:
    Serial.printf("[WS] Client #%u disconnected\n", client->id());
    break;

  case WS_EVT_ERROR:
    Serial.printf("[WS] Client #%u error\n", client->id());
    break;

  case WS_EVT_PONG:
    break;

  case WS_EVT_DATA:
    // We don't expect incoming data from browser, but log it for debugging
    Serial.printf("[WS] Received %u bytes from client #%u\n", len,
                  client->id());
    break;
  }
}

// =============================================================================
// WebSocket Server Setup
// =============================================================================

void setupWebSocket() {
  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);

  // Simple health-check endpoint
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain",
                  "ESP32-S3 Baby Monitor\n"
                  "WebSocket: ws://<this-ip>:81/ws\n"
                  "Sample Rate: " +
                      String(SAMPLE_RATE) +
                      " Hz\n"
                      "Bit Depth: 16-bit\n"
                      "Channels: Mono");
  });

  server.begin();
  Serial.printf("[WS] Server started on port %d\n", WS_PORT);
}

// =============================================================================
// Arduino Setup & Loop
// =============================================================================

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("=========================================");
  Serial.println("  ESP32-S3 Baby Monitor — Starting Up");
  Serial.println("=========================================");

  setupWiFi();
  setupI2S();
  setupWebSocket();

  Serial.println("[READY] Baby monitor is running!");
  Serial.printf("[READY] Connect to: ws://%s:%d/ws\n",
                WiFi.localIP().toString().c_str(), WS_PORT);
}

void loop() {
  // Clean up disconnected WebSocket clients periodically
  ws.cleanupClients();

  // Only stream if there are connected clients
  if (ws.count() == 0) {
    delay(10);
    return;
  }

  // Read audio samples from I2S (INMP441)
  size_t bytesRead = 0;
  esp_err_t err = i2s_read(I2S_PORT, i2sReadBuffer, I2S_READ_BUF_SIZE,
                           &bytesRead, portMAX_DELAY);

  if (err != ESP_OK) {
    Serial.printf("[I2S] Read error: %d\n", err);
    return;
  }

  if (bytesRead > 0) {
    // Send raw PCM audio as binary WebSocket frame to all clients
    ws.binaryAll((uint8_t *)i2sReadBuffer, bytesRead);
  }
}
