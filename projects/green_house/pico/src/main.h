#pragma once
#include "../clock/clock.h"
#include "../display/src/font.h"
#include "../display/src/i2c_oled_1306.h"
#include "../display/src/ssd1306.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>

extern const uint LED_PIN;
extern const uint RELAY_PIN;
extern const uint BUTTON_OUT_PIN;
extern const uint BUTTON_IN_PIN;
extern const uint BUTTON2_OUT_PIN;
extern const uint BUTTON2_IN_PIN;
extern const uint BUTTON3_OUT_PIN;
extern const uint BUTTON3_IN_PIN;
extern int chooseNumber;
extern int setClockMode; // Variable to indicate if clock setting mode is active

extern char timeString[9];  // Buffer for "HH:MM:SS\0"
extern char dateString[11]; // Buffer for "DD/MM/YYYY\0"
extern int *fakeClock;
extern int *fakeDate;

void setupPico() {
  stdio_init_all();
  gpio_init(LED_PIN);
  gpio_init(RELAY_PIN);
  gpio_init(BUTTON_OUT_PIN);
  gpio_init(BUTTON_IN_PIN);
  gpio_init(BUTTON2_OUT_PIN);
  gpio_init(BUTTON2_IN_PIN);
  gpio_init(BUTTON3_OUT_PIN);
  gpio_init(BUTTON3_IN_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  gpio_set_dir(RELAY_PIN, GPIO_OUT);
  gpio_set_dir(BUTTON_OUT_PIN, GPIO_OUT);
  gpio_set_dir(BUTTON_IN_PIN, GPIO_IN);
  gpio_set_dir(BUTTON2_OUT_PIN, GPIO_OUT);
  gpio_set_dir(BUTTON2_IN_PIN, GPIO_IN);
  gpio_set_dir(BUTTON3_OUT_PIN, GPIO_OUT);
  gpio_set_dir(BUTTON3_IN_PIN, GPIO_IN);
  gpio_pull_down(BUTTON_IN_PIN);  // so it reads 0 when OUT is low or floating
  gpio_pull_down(BUTTON2_IN_PIN); // so it reads 0 when OUT is low or floating
  gpio_pull_down(BUTTON3_IN_PIN); // so it reads 0 when OUT is low or floating
  sleep_ms(100);
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

void printOnScreen() {
  sprintf(timeString, "%02d:%02d:%02d", fakeClock[0], fakeClock[1],
          fakeClock[2]);
  sprintf(dateString, "%02d/%02d/%04d", fakeDate[0], fakeDate[1], fakeDate[2]);
  ssd1306_clear(&oled);
  drawTest(&oled, timeString, dateString);
  ssd1306_show(&oled);
}

void activatRelay() {
  if (checkArray(activitionSeconds, activitionSecondsSize, fakeClock[2])) {
    gpio_put(LED_PIN, 1);
    gpio_put(RELAY_PIN, 1);
  } else {
    gpio_put(LED_PIN, 0);
    gpio_put(RELAY_PIN, 0);
  }
}

void adjustClock() {
  if (gpio_get(BUTTON_IN_PIN)) {
    setClockMode = 1;
    sleep_ms(500);
    int chooseNumber = 0;
    while (setClockMode == 1) {

      if (gpio_get(BUTTON_IN_PIN)) {
        setClockMode = 0;
      }
      if (gpio_get(BUTTON2_IN_PIN)) {
        if (chooseNumber == 0) {
          fakeClock[chooseNumber] =
              (fakeClock[chooseNumber] + 1) % 24; // Increment hour
          printOnScreen();
          sleep_ms(250);
          sprintf(timeString, "  :%02d:%02d", fakeClock[1], fakeClock[2]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(250);
        } else if (chooseNumber == 1) {
          fakeClock[chooseNumber] =
              (fakeClock[chooseNumber] + 1) % 60; // Increment minute or second
          printOnScreen();
          sleep_ms(63);
          sprintf(timeString, "%02d:  :%02d", fakeClock[0], fakeClock[2]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(62);
        } else if (chooseNumber == 2) {
          fakeClock[chooseNumber] =
              (fakeClock[chooseNumber] + 1) % 60; // Increment minute or second
          printOnScreen();
          sleep_ms(63);
          sprintf(timeString, "%02d:%02d:  ", fakeClock[0], fakeClock[1]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(62);
        } else if (chooseNumber == 3) {
          fakeDate[0] = (fakeDate[0] + 1) % 32; // Increment day
          printOnScreen();
          sleep_ms(250);
          sprintf(dateString, "  /%02d/%04d", fakeDate[1], fakeDate[2]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(250);
        } else if (chooseNumber == 4) {
          fakeDate[1] = (fakeDate[1] + 1) % 13; // Increment month
          printOnScreen();
          sleep_ms(250);
          sprintf(dateString, "%02d/  /%04d", fakeDate[0], fakeDate[2]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(250);
        } else if (chooseNumber == 5) {
          fakeDate[2]++; // Increment year
          printOnScreen();
          sleep_ms(250);
          sprintf(dateString, "%02d/%02d/    ", fakeDate[0], fakeDate[1]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(250);
        }
      }
      if (gpio_get(BUTTON3_IN_PIN)) {
        chooseNumber =
            (chooseNumber + 1) % 6; // Cycle through hour, minute, second
        printf("Choose number: %d\n", chooseNumber);
        sleep_ms(500);
      }
      if (!gpio_get(BUTTON_IN_PIN) && !gpio_get(BUTTON2_IN_PIN) &&
          !gpio_get(BUTTON3_IN_PIN)) {
        if (chooseNumber == 0) {
          printOnScreen();
          sleep_ms(250);
          sprintf(timeString, "  :%02d:%02d", fakeClock[1], fakeClock[2]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(250);
        } else if (chooseNumber == 1) {
          printOnScreen();
          sleep_ms(250);
          sprintf(timeString, "%02d:  :%02d", fakeClock[0], fakeClock[2]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(250);
        } else if (chooseNumber == 2) {
          printOnScreen();
          sleep_ms(250);
          sprintf(timeString, "%02d:%02d:  ", fakeClock[0], fakeClock[1]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(250);
        } else if (chooseNumber == 3) {
          printOnScreen();
          sleep_ms(250);
          sprintf(dateString, "  /%02d/%04d", fakeDate[1], fakeDate[2]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(250);
        } else if (chooseNumber == 4) {
          printOnScreen();
          sleep_ms(250);
          sprintf(dateString, "%02d/  /%04d", fakeDate[0], fakeDate[2]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(250);
        } else if (chooseNumber == 5) {
          printOnScreen();
          sleep_ms(250);
          sprintf(dateString, "%02d/%02d/    ", fakeDate[0], fakeDate[1]);
          ssd1306_clear(&oled);
          drawTest(&oled, timeString, dateString);
          ssd1306_show(&oled);
          sleep_ms(250);
        }
      }
      sleep_ms(10);
    }
  }
}

// void buttonPressed() {
//         gpio_put(LED_PIN, 2);
//         gpio_put(RELAY_PIN, 2);
//         printf("button pressed\n"); // print out to console
//         sleep_ms(100);
//         gpio_put(LED_PIN, 0);
//         gpio_put(RELAY_PIN, 0);
//         printf("LED off\n");
//         sleep_ms(100);
//     }
// }
