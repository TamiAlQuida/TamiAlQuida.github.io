#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

const int WIDTH = 1920;                                             // Width of the window
const int HEIGHT = 1080;                                            // Height of the window

int main() {
    while (true) {
        std::cout << "Hello World" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}