#include "pico/stdlib.h"
#include <iostream>
#include "NRF24.h"
#include "stdio.h"
#include "pico/cyw43_arch.h"

int main()
{
    // Initialize modules
    stdio_init_all(); 
    cyw43_arch_init(); // Initialize WiFi chip for using the onboard LED

    const int led_pin = CYW43_WL_GPIO_LED_PIN;
    cyw43_arch_gpio_put(led_pin, true);

    sleep_ms(100); // give time for things to settle.

    NRF24 nrf = NRF24(spi1,9,8);
    nrf.config((uint8_t*)"gyroc",2,24); // Name=gyroc, channel=2,messagSize=24

    nrf.modeTX(); // <---- Set as transmitter.

    char message[7];
    uint16_t counter = 0;

    while(1)  
    {
        //sprintf(message, "%d", counter++); // Use snprintf with padding
        std::string message = std::to_string(counter++);
        std::cout << message << std::endl;
        nrf.sendMessage((uint8_t*)message.c_str());

        cyw43_arch_gpio_put(led_pin, !cyw43_arch_gpio_get(led_pin)); // Toggle LED after sending
        sleep_ms(20); // Changed to 20ms to allow receiver to check twice
    } 
    return 0;
}