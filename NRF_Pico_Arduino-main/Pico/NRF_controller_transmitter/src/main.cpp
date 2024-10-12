#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "tusb.h"
#include "NRF24.h"

// Global variable to store the 6-digit string
char current_value[7] = "000000"; // 6 digits + null terminator

void update_value() {
    if (tud_cdc_available() >= 6) {
        // Clear the current_value buffer before reading
        memset(current_value, 0, sizeof(current_value));
        
        // Read exactly 6 bytes
        uint8_t count = tud_cdc_read(current_value, 6);
        
        // Ensure null-termination
        current_value[6] = '\0';
        
        // Print the raw received string for debugging
        //printf("%s\n", current_value);
        //
        //int left_x = atoi(current_value);
        //int left_y = atoi(current_value + 3);
//
        //printf("%d %d\n", left_x, left_y);

        // Toggle LED based on received values
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    }
}


int main() {
    stdio_init_all();
    cyw43_arch_init(); // Initialize WiFi chip for using the onboard LED
    
    const int led_pin = CYW43_WL_GPIO_LED_PIN;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    sleep_ms(1000);

    NRF24 nrf = NRF24(spi1,9,8);
    nrf.config((uint8_t*)"gyroc",2,7); // Name=gyroc, channel=2,messagSize=24

    nrf.modeTX(); // <---- Set as transmitter.


    while (true) {
        update_value();
        tud_task(); // TinyUSB device task
        nrf.sendMessage((uint8_t*) current_value);
        sleep_us(500); // Small delay to prevent overwhelming the CPU
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    }

    return 0;
}