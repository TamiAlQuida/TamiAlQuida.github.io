// program for a raspberry pi pico

#include "main.h"

int setClock[3] = {22, 0, 0};   // Set initial time
int setDate[3] = {30, 6, 2026}; // Set initial date (DD, MM, YYYY)
int sleepTime = 1;

int activitionHours[] = {0};                 // Set initial activation hours
int activitionMinutes[] = {0};               // Set initial activation minutes
int activitionSeconds[] = {2, 4, 7, 10, 12}; // Set initial activation seconds
const int activitionHoursSize =
    sizeof(activitionHours) / sizeof(activitionHours[0]);
const int activitionMinutesSize =
    sizeof(activitionMinutes) / sizeof(activitionMinutes[0]);
const int activitionSecondsSize =
    sizeof(activitionSeconds) / sizeof(activitionSeconds[0]);

const uint LED_PIN = 25;
const uint RELAY_PIN = 0;
const uint BUTTON_OUT_PIN = 2;
const uint BUTTON_IN_PIN = 3;
const uint BUTTON2_OUT_PIN = 4;
const uint BUTTON2_IN_PIN = 5;
const uint BUTTON3_OUT_PIN = 6;
const uint BUTTON3_IN_PIN = 7;

int chooseNumber = 0; // Variable to choose number for clock setting
int setClockMode = 0;

char timeString[9];  // Buffer for "HH:MM:SS\0"
char dateString[11]; // Buffer for "DD/MM/YYYY\0"
int *fakeClock = setClock;
int *fakeDate = setDate;

int main() {
  setupPico();
  setupOled();
  gpio_put(LED_PIN, 1);
  gpio_put(BUTTON_OUT_PIN, 1);
  gpio_put(BUTTON2_OUT_PIN, 1);
  gpio_put(BUTTON3_OUT_PIN, 1);
  sleep_ms(1000);
  while (true) {
    printOnScreen();
    changeClock();
    activatRelay();
    adjustClock();
  }
}