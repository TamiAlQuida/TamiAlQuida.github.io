#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/gpio.h"

int main() {
    stdio_init_all();
    cyw43_arch_init(); // Initialize WiFi chip for using the onboard LED
    
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    sleep_ms(1000);




    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        gpio_put(0, 0);
        printf("LED off\n");
        sleep_ms(5000);
        gpio_put(0, 1);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        printf("LED on\n");
        sleep_ms(5000);
    }
}