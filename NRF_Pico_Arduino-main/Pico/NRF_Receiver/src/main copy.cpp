#include "pico/stdlib.h"
#include <iostream>
#include "NRF24.h"
#include "stdio.h"
#include "pico/cyw43_arch.h"
#include <cstring>
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"


// Function to initialize GPIO pins
void initialize_GPIO()
{
    // Initialize GPIO pin 25
    //gpio_init(25);
    gpio_init(26);
    // Set GPIO pin 25 as an output
    //gpio_set_dir(25, GPIO_OUT);
    // Set GPIO pin 25 to low (turn off)
    //gpio_put(25, true);
    // Set GPIO pin 26 as pwm
    gpio_set_function(26, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(26);
    pwm_config config = pwm_get_default_config();
    
    // Set PWM frequency to 50 Hz (20ms period)
    float divider = clock_get_hz(clk_sys) / (50.0f * 65535.0f);
    pwm_config_set_clkdiv(&config, divider);
    pwm_config_set_wrap(&config, 65535);
    pwm_init(slice_num, &config, true);
}


// Function to set servo position
void set_servo_position(uint gpio, float degree) {
    // Convert 0-180 degrees to 500-2500 microseconds
    float pulsewidth = 500.0f + degree * (2000.0f / 180.0f);
    // Convert microseconds to PWM counts
    uint16_t counts = (uint16_t)(pulsewidth / 20000.0f * 65535.0f);
    pwm_set_gpio_level(gpio, counts);
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

                // Convert left_speed (0-255) to servo angle (0-180 degrees)
                float servo_angle = (float)left_speed * (180.0f / 255.0f);
                set_servo_position(26, servo_angle);

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
