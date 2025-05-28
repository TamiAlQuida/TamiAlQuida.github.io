#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

int setClock[3] = {22, 0, 0}; // Set initial time

const uint LED_PIN = 25;
const uint RELAY_PIN = 0;

int* fakeClock = setClock;
int sleepTime = 1;
int activitionHours[] = {0}; // Set initial activation hours
int activitionMinutes[] = {0}; // Set initial activation minutes
int activitionSeconds[] = {0}; // Set initial activation seconds


void setup() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_init(RELAY_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(RELAY_PIN, GPIO_OUT);
    sleep_ms(1000);
}

void test_relay() {
    for (int i = 0; i < 5; i++) {
        gpio_put(LED_PIN, 1);
        gpio_put(RELAY_PIN, 1);
        printf("LED on\n");
        sleep_ms(100);
        gpio_put(LED_PIN, 0);
        gpio_put(RELAY_PIN, 0);
        printf("LED off\n");
        sleep_ms(100);
    }
}

void changeClock() {
    printf("Clock: %02d:%02d:%02d\n", fakeClock[0], fakeClock[1], fakeClock[2]);
    if (fakeClock[0] == 23 && fakeClock[1] == 59 && fakeClock[2] == 60 - sleepTime) {
        fakeClock[0] = 0;
        fakeClock[1] = 0;
        fakeClock[2] = 0;
    } else if (fakeClock[1] == 59 && fakeClock[2] == 60 - sleepTime) {
        fakeClock[0]++;
        fakeClock[1] = 0;
        fakeClock[2] = 0;
    } else if (fakeClock[2] == 60 - sleepTime) {
        fakeClock[1]++;
        fakeClock[2] = 0;
    } else {
        fakeClock[2] += sleepTime;
    }
    sleep_ms(sleepTime * 1000);
}


int main() {
    setup();
    gpio_put(LED_PIN, 1);
    sleep_ms(5000);
    while (true) {
        changeClock();
        if (fakeClock [2] == 10 or fakeClock [1] == 1 )
        {
            gpio_put(LED_PIN, 1);
            gpio_put(RELAY_PIN, 1);
        }
        else {
            gpio_put(LED_PIN, 0);
            gpio_put(RELAY_PIN, 0);
        }
        
    }
}