#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const uint LED_PIN = 25;
const uint RELAY_PIN = 1;


int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_init(RELAY_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(RELAY_PIN, GPIO_OUT);

    sleep_ms(1000);

    while (true) {
        gpio_put(LED_PIN, 1);
        gpio_put(RELAY_PIN, 1);
        printf("LED on\n");
        sleep_ms(5000);
        gpio_put(LED_PIN, 0);
        gpio_put(RELAY_PIN, 0);
        printf("LED off\n");
        sleep_ms(5000);
    }
}