#include <iostream>
#include <chrono>
#include <thread>

int setClock[3] = {22, 0, 0};

int main() {
    std::cout<<"Hello, world!\n";

    int* clock = setClock;
    int sleepTime = 5;

    while (true) {
        std::cout<<"Clock: "<<clock[0]<<":"<<clock[1]<<":"<<clock[2]<<"\n";
        if (clock[0] == 23 && clock[1] == 59 && clock[2] == 60 - sleepTime)
        {
            clock[0] = 0;
            clock[1] = 0;
            clock[2] = 0;
        }
        
        else if (clock[1] == 59 && clock[2] == 60 - sleepTime)
        {
            clock[0] += 1;
            clock[1] = 0;
            clock[2] = 0;
        }

        else if (clock[2] == 60 - sleepTime)
        {
            clock[1] += 1;
            clock[2] = 0;
        }

        else
        {
            clock[2] += sleepTime;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime *1000));
    }
}