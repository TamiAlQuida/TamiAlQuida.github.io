#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pico/cyw43_arch.h"
#include "tusb.h"

int main() {
    stdio_init_all();
    cyw43_arch_init(); // Initialize WiFi chip for using the onboard LED
    
    const int led_pin = CYW43_WL_GPIO_LED_PIN;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    sleep_ms(1000);

    char buffer[7]; // 6 characters + null terminator
    int buffer_index = 0;
    
    while (true) {
        if (tud_cdc_available()) {
            char c = tud_cdc_read_char();
            if (c == '\n' || c == '\r') {
                buffer[buffer_index] = '\0';
                if (buffer_index == 6) {
                    int left_x = atoi(buffer);
                    int left_y = atoi(buffer + 3);

                    printf("Received: Left Joystick X: %d, Y: %d\n", left_x, left_y);

                    // Toggle LED based on received values
                    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, (left_x + left_y) % 2);
                }
                buffer_index = 0;
            } else if (buffer_index < 6) {
                buffer[buffer_index++] = c;
            }
        }
        tud_task(); // TinyUSB device task
        sleep_ms(10); // Small delay to prevent overwhelming the CPU
    }

    return 0;
}