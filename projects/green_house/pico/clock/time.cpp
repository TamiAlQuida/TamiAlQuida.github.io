#include <iostream>
#include <chrono>
#include <thread>

int fakeClock[3] = {22, 0, 0}; // Set initial time

int* fakeClock = fakeClock;
int sleepTime = 1;

void changeClock() {
    std::cout<<"Clock: "<<fakeClock[0]<<":"<<fakeClock[1]<<":"<<fakeClock[2]<<"\n";
        if (fakeClock[0] == 23 && fakeClock[1] == 59 && fakeClock[2] == 60 - sleepTime)
        {
            fakeClock[0] = 0;
            fakeClock[1] = 0;
            fakeClock[2] = 0;
        }
        
        else if (fakeClock[1] == 59 && fakeClock[2] == 60 - sleepTime)
        {
            fakeClock[0] += 1;
            fakeClock[1] = 0;
            fakeClock[2] = 0;
        }

        else if (fakeClock[2] == 60 - sleepTime)
        {
            fakeClock[1] += 1;
            fakeClock[2] = 0;
        }

        else
        {
            fakeClock[2] += sleepTime;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime *1000));
}

int main() {
    std::cout<<"Hello, world!\n";

    while (true) {
        changeClock();
    }
}