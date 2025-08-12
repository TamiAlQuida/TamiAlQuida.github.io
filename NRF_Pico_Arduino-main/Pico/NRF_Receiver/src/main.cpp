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
    // Initialize GPIO
    gpio_init(21);
    gpio_init(22);
    gpio_init(26);

    // Set GPIO as output
    gpio_set_dir(21, GPIO_OUT);
    
    // Set GPIO as pwm
    gpio_set_function(22, GPIO_FUNC_PWM);
    gpio_set_function(26, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(22);
    uint slice_num2 = pwm_gpio_to_slice_num(26);
    pwm_config config_servo = pwm_get_default_config();
    pwm_config config_DC_motor = pwm_get_default_config();
    
    // Set PWM frequency
    float divider_servo = clock_get_hz(clk_sys) / (50.0f * 65535.0f);
    float divider_DC_motor = clock_get_hz(clk_sys) / (100.0f * 65535.0f);
    pwm_config_set_clkdiv(&config_servo, divider_servo);
    pwm_config_set_clkdiv(&config_DC_motor, divider_DC_motor);
    pwm_config_set_wrap(&config_servo, 65535);
    pwm_config_set_wrap(&config_DC_motor, 65535);
    pwm_init(slice_num, &config_servo, true);
    pwm_init(slice_num2, &config_DC_motor, true);
}


// Function to set servo position
void set_servo_position(uint gpio, float left_right) {
    
    // Adjust these values based on your specific servo
    const uint16_t min_pulse_us = 1000;  // Minimum pulse width in microseconds
    const uint16_t max_pulse_us = 2000; // Maximum pulse width in microseconds
    
    // Convert angle to PWM duty cycle
    uint16_t pulse_width = (uint16_t)(min_pulse_us + (left_right / 255.0f) * (max_pulse_us - min_pulse_us));
    uint16_t counts = (pulse_width * 65535) / 10000; //Should be 20000, but it wasnt working, so i had to divide it by 2
    
    pwm_set_gpio_level(gpio, counts);
}

// Function to set motor speed
void set_motor_speed(uint gpio, float speed) {
    // Convert 0-255 to 0-65535
    uint16_t counts = (uint16_t)((speed / 255.0f) * 65535.0f);
    pwm_set_gpio_level(gpio, counts);
}


int main()
{
    // Initialize modules
    stdio_init_all(); 
    cyw43_arch_init(); // Initialize WiFi chip for using the onboard LED

    initialize_GPIO();

    gpio_put(21, true);

    const int led_pin = CYW43_WL_GPIO_LED_PIN;

    sleep_ms(100);
    cyw43_arch_gpio_put(led_pin, true);

    NRF24 nrf = NRF24(spi1,9,8); // GP8, physical pin 11 // GP9, physical pin 12
    nrf.config((uint8_t*)"gyroc",2,7); // Name=gyroc, channel=2, messageSize=7

    nrf.modeRX(); // <------ Set as Receiver.

    char message[8]; // 7 bytes for data (6 digits + null terminator) + 1 extra for safety

    int left_right = 0;
    int speed = 0;

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
                left_right = atoi(left_str);
                speed = atoi(right_str);

                printf("%d %d\n", left_right, speed);

                // Set pulse width for servo and motor
                set_servo_position(26, left_right);
                set_motor_speed(22, speed);

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
        //Should be a sleep about here somewhere.
    }
    return 0;
}
