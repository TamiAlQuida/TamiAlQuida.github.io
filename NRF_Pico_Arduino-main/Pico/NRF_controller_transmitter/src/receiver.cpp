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

    sleep_ms(100);
    cyw43_arch_gpio_put(led_pin, true);

    NRF24 nrf = NRF24(spi1,9,8);
    nrf.config((uint8_t*)"gyroc",2,10); // Name=gyroc, channel=2,messagSize=10

    nrf.modeRX(); // <------ Set as Receiver.

    char message[11];
    uint16_t counter = 0;

    while(1)  
    {
        if(nrf.newMessage())
        {
            nrf.getMessage((uint8_t*)&message);
            std::cout << message << std::endl;
            cyw43_arch_gpio_put(led_pin, false);
        }
        else
        {
            cyw43_arch_gpio_put(led_pin, true);
        }
        //sleep_ms(5);
    }
return 0;
}