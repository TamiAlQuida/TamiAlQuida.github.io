#include "pico/stdlib.h"
#include <iostream>
#include "NRF24.h"
#include "stdio.h"
#include "pico/cyw43_arch.h"
#include <cstring>
#include "hardware/gpio.h"
#include "hardware/pwm.h"


// Function to initialize GPIO pins
void initialize_GPIO()
{
    // Initialize GPIO pin 25
    gpio_init(25);
    gpio_init(26);
    // Set GPIO pin 25 as an output
    gpio_set_dir(25, GPIO_OUT);
    // Set GPIO pin 25 to low (turn off)
    gpio_put(25, true);
    // Set GPIO pin 26 as pwm
    pwm_config config = pwm_get_default_config();
    pwm_init(pwm_gpio_to_slice_num(26), &config, true);
}


int main()
{
    // Initialize modules
    stdio_init_all(); 
    cyw43_arch_init(); // Initialize WiFi chip for using the onboard LED

    initialize_GPIO();

    const int led_pin = CYW43_WL_GPIO_LED_PIN;

    sleep_ms(100);
    cyw43_arch_gpio_put(led_pin, true);

    NRF24 nrf = NRF24(spi1,9,8); // GP8, physical pin 11 // GP9, physical pin 12
    nrf.config((uint8_t*)"gyroc",2,7); // Name=gyroc, channel=2, messageSize=7

    nrf.modeRX(); // <------ Set as Receiver.

    char message[8]; // 7 bytes for data (6 digits + null terminator) + 1 extra for safety

    int left_speed = 0;
    int right_speed = 0;

    while(1)  
    {
        if(nrf.newMessage())
        {
            nrf.getMessage((uint8_t*)&message);
            message[7] = '\0'; // Ensure null-termination
            
            // Check if the message is exactly 6 digits + null terminator
            if (strlen(message) == 6 && strspn(message, "0123456789") == 6) {
                //std::cout << message << std::endl;
                char left_str[4] = {message[0], message[1], message[2], '\0'};
                char right_str[4] = {message[3], message[4], message[5], '\0'};
                left_speed = atoi(left_str);
                right_speed = atoi(right_str);

                printf("%d %d\n", left_speed, right_speed);

                // Set PWM duty cycle for left motor (GPIO 26)
                pwm_set_gpio_level(26, left_speed * 257); // Scale 0-255 to 0-65535

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
