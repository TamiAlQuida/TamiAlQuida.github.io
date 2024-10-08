#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pico/cyw43_arch.h"

#define UART_ID uart0
#define BAUD_RATE 9600
#define UART_TX_PIN 0
#define UART_RX_PIN 1

void setup_uart() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

int main() {
    stdio_init_all();
    setup_uart();
    cyw43_arch_init(); // Initialize WiFi chip for using the onboard LED
    
    const int led_pin = CYW43_WL_GPIO_LED_PIN;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    sleep_ms(1000);

    char buffer[7]; // 6 characters + null terminator
    
    while (true) {
        if (uart_is_readable(UART_ID)) {
            uart_read_blocking(UART_ID, (uint8_t*)buffer, 6);
            buffer[6] = '\0'; // Null-terminate the string

            int left_x = atoi(buffer);
            int left_y = atoi(buffer + 3);

            printf("Received: Left Joystick X: %d, Y: %d\n", left_x, left_y);

            // Clear any remaining data in the UART buffer
            while (uart_is_readable(UART_ID)) {
                uart_getc(UART_ID);
            }
        }
        sleep_ms(10); // Small delay to prevent overwhelming the CPU
    }

    return 0;
}