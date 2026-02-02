#include <chrono>
#include <iostream>
#include <thread>

int fakeClock[3] = {22, 0, 0}; // Set initial time

int *fakeClockPtr = fakeClock;
int sleepTime = 1;

void changeClock() {
  std::cout << "Clock: " << fakeClockPtr[0] << ":" << fakeClockPtr[1] << ":"
            << fakeClockPtr[2] << "\n";
  if (fakeClockPtr[0] == 23 && fakeClockPtr[1] == 59 &&
      fakeClockPtr[2] == 60 - sleepTime) {
    fakeClockPtr[0] = 0;
    fakeClockPtr[1] = 0;
    fakeClockPtr[2] = 0;
  }

  else if (fakeClockPtr[1] == 59 && fakeClockPtr[2] == 60 - sleepTime) {
    fakeClockPtr[0] += 1;
    fakeClockPtr[1] = 0;
    fakeClockPtr[2] = 0;
  }

  else if (fakeClockPtr[2] == 60 - sleepTime) {
    fakeClockPtr[1] += 1;
    fakeClockPtr[2] = 0;
  }

  else {
    fakeClockPtr[2] += sleepTime;
  }

  std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime * 1000));
}

int main() {
  std::cout << "Hello, world!\n";

  while (true) {
    changeClock();
  }
}