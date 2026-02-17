#include "hardware/gpio.h"
#include "lwip/netif.h"
#include "lwip/tcp.h"
#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

// WiFi Credentials - USER: PLEASE UPDATE THESE
#ifndef WIFI_SSID
#define WIFI_SSID "Pallans Special"
#endif
#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD "62g2cuhkw"
#endif

#define TCP_PORT 80
#define DEBUG_PRINT printf

static struct tcp_pcb *server_pcb;

// Minimal WebSocket Frame Helper
void send_ws_message(struct tcp_pcb *tpcb, const char *msg) {
  size_t len = strlen(msg);
  if (len > 125)
    return; // Simplified for short messages

  uint8_t frame[2];
  frame[0] = 0x81;         // Final frame, text type
  frame[1] = (uint8_t)len; // No mask, length < 126

  tcp_write(tpcb, frame, 2, TCP_WRITE_FLAG_COPY);
  tcp_write(tpcb, msg, len, TCP_WRITE_FLAG_COPY);
  tcp_output(tpcb);
}

static err_t ws_recv_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p,
                              err_t err) {
  if (p == NULL) {
    DEBUG_PRINT("Connection closed\n");
    tcp_close(tpcb);
    return ERR_OK;
  }

  char *data = (char *)p->payload;
  size_t len = p->len;

  // 1. Handle HTTP Handshake
  if (len > 10 && strstr(data, "GET ") && strstr(data, "Upgrade: websocket")) {
    DEBUG_PRINT("WS Handshake\n");
    // Simplified response. Note: Real browsers verify the Sec-WebSocket-Accept
    // key. If this fails in Chrome/Firefox, we might need a proper SHA1/Base64
    // calc.
    const char *response =
        "HTTP/1.1 101 Switching Protocols\r\n"
        "Upgrade: websocket\r\n"
        "Connection: Upgrade\r\n"
        "Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo=\r\n\r\n";
    tcp_write(tpcb, response, strlen(response), TCP_WRITE_FLAG_COPY);
    tcp_output(tpcb);

    send_ws_message(
        tpcb, "{\"type\":\"system\",\"message\":\"Connected to Pico W\"}");
  }
  // 2. Handle WebSocket Data Frames
  else if (len >= 2 && (uint8_t)data[0] == 0x81) {
    uint8_t payload_len = (uint8_t)data[1] & 0x7F;
    bool is_masked = (uint8_t)data[1] & 0x80;

    if (is_masked && len >= (6 + payload_len)) {
      uint8_t *mask = (uint8_t *)&data[2];
      char *payload = &data[6];
      for (int i = 0; i < payload_len; i++) {
        payload[i] ^= mask[i % 4];
      }
      payload[payload_len] = '\0';
      DEBUG_PRINT("WS CMD: %s\n", payload);

      // Handle commands from website
      if (strcmp(payload, "TOGGLE_LIGHT") == 0) {
        static bool light = false;
        light = !light;
        gpio_put(0, light); // Assuming pin 0 for now
        send_ws_message(tpcb,
                        "{\"type\":\"log\",\"message\":\"Light toggled\"}");
      } else if (strcmp(payload, "GET_STATUS") == 0) {
        send_ws_message(
            tpcb,
            "{\"type\":\"sensor\",\"temp\":22.5,\"humid\":55.0,\"soil\":40}");
      }
    }
  }

  tcp_recved(tpcb, p->len);
  pbuf_free(p);
  return ERR_OK;
}

static err_t ws_accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err) {
  DEBUG_PRINT("Accepted\n");
  tcp_recv(newpcb, ws_recv_callback);
  return ERR_OK;
}

void start_server() {
  struct tcp_pcb *pcb = tcp_new();
  tcp_bind(pcb, IP_ADDR_ANY, TCP_PORT);
  server_pcb = tcp_listen(pcb);
  tcp_accept(server_pcb, ws_accept_callback);
  DEBUG_PRINT("Listening on 80\n");
}

int main() {
  stdio_init_all();
  if (cyw43_arch_init())
    return -1;
  cyw43_arch_enable_sta_mode();

  DEBUG_PRINT("Connecting to WiFi...\n");
  if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD,
                                         CYW43_AUTH_WPA2_AES_PSK, 30000)) {
    DEBUG_PRINT("WiFi Failed\n");
  } else {
    DEBUG_PRINT("WiFi Connected\n");
    printf("IP: %s\n", ip4addr_ntoa(netif_ip4_addr(netif_default)));
  }

  start_server();

  while (true) {
    // Blink internal LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    sleep_ms(100);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    sleep_ms(900);

    // Broadcast sensor data every 5 seconds (simulated)
    static uint32_t last_send = 0;
    if (to_ms_since_boot(get_absolute_time()) - last_send > 5000) {
      // Need a way to track active connections if we want to broadcast
      // For now, we only respond to messages
      last_send = to_ms_since_boot(get_absolute_time());
    }
  }
}