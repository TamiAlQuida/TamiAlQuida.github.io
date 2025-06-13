#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "functions.h"
#include "../display/src/font.h"
#include "../display/src/ssd1306.h"
#include "../display/src/i2c_oled_1306.h"



int setClock[3] = {22, 0, 0}; // Set initial time
int sleepTime = 1;

int activitionHours[] = {0}; // Set initial activation hours
int activitionMinutes[] = {0}; // Set initial activation minutes
int activitionSeconds[] = {2, 4, 7, 10, 12}; // Set initial activation seconds
const int activitionHoursSize = sizeof(activitionHours) / sizeof(activitionHours[0]);
const int activitionMinutesSize = sizeof(activitionMinutes) / sizeof(activitionMinutes[0]);
const int activitionSecondsSize = sizeof(activitionSeconds) / sizeof(activitionSeconds[0]);

const uint LED_PIN = 25;
const uint RELAY_PIN = 0;

int* fakeClock = setClock;

int main() {
    setup();
    setupOled();
    gpio_put(LED_PIN, 1);
    sleep_ms(5000);
    while (true) {
        ssd1306_clear(&oled);
		drawTest(&oled, "Yiiihaaa");
        ssd1306_show(&oled);
        changeClock();
        if (checkArray(activitionSeconds, activitionSecondsSize, fakeClock[2]))
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