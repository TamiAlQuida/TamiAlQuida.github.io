#include "pico/stdlib.h"
#include <iostream>
#include "NRF24.h"
#include "stdio.h"
#include "pico/cyw43_arch.h"
#include <cstring>
#include "hardware/gpio.h"

int main()
{
    // Initialize modules
    stdio_init_all(); 
    cyw43_arch_init(); // Initialize WiFi chip for using the onboard LED    

    const int led_pin = CYW43_WL_GPIO_LED_PIN;

    sleep_ms(100);
    cyw43_arch_gpio_put(led_pin, true);

    NRF24 nrf = NRF24(spi1,9,8); // GP8, physical pin 11 // GP9, physical pin 12
    nrf.config((uint8_t*)"gyroc",2,7); // Name=gyroc, channel=2, messageSize=7

    nrf.modeRX(); // <------ Set as Receiver.

    char message[8]; // 7 bytes for data (6 digits + null terminator) + 1 extra for safety

    while(1)  
    {
        if(nrf.newMessage())
        {
            nrf.getMessage((uint8_t*)&message);
            message[7] = '\0'; // Ensure null-termination
            
            // Check if the message is exactly 6 digits + null terminator
            if (strlen(message) == 6 && strspn(message, "0123456789") == 6) {
                std::cout << message << std::endl;
                cyw43_arch_gpio_put(led_pin, false);
            } else {
                // Invalid message, flush the buffer
                while(nrf.newMessage()) {
                    nrf.getMessage((uint8_t*)&message); // Flush the buffer
                }
                cyw43_arch_gpio_put(led_pin, true);
            }
        }
        else
        {
            cyw43_arch_gpio_put(led_pin, true);
        }
    }
    return 0;
}