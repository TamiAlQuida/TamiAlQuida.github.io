#pragma once
#include "../src/main.h"
#include "pico/stdlib.h"
#include <cstdio>
extern int setClock[];
extern int sleepTime;
extern int *fakeClock;
extern int activitionHours[];
extern int activitionMinutes[];
extern int activitionSeconds[];
extern const int activitionHoursSize;
extern const int activitionMinutesSize;
extern const int activitionSecondsSize;

void changeClock() {
  printf("Clock: %02d:%02d:%02d\n", fakeClock[0], fakeClock[1], fakeClock[2]);
  if (fakeClock[0] == 23 && fakeClock[1] == 59 &&
      fakeClock[2] == 60 - sleepTime) {
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

bool checkArray(int arr[], int size, int value) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      return true;
    }
  }
  return false;
}