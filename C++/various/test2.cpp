#include <iostream>
#include <chrono>
#include <thread>

std::string keyboardIn;
float height = 0.0;
int millisecondsToSleep = 100;
float timer = millisecondsToSleep / 1000.0; // Allocate memory and assign value
float fallTime = 0.0;
const float gravity = 9.82; // m/s2
float jumpSpeed = 7.5; // m/s

void movePosition(std::string keyboardIn) {
    std::cin >> keyboardIn;
    if (keyboardIn != "w" && keyboardIn != "a" && keyboardIn != "s" && keyboardIn != "d") {
        std::cout << "enter w,a,s or d" << "\n" << "\n";
    }

    if (keyboardIn == "w") {
        while (height >= 0) {
            fallTime += timer; // Dereference pointer to get value
            height = jumpSpeed * fallTime - gravity * fallTime * fallTime / 2;
            if (height < 0) {
                height = 0;
            }

            std::cout << "Height: " << height << "\n";
            std::cout << "Fall Time: " << fallTime << "\n" << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));

            if (height <= 0) {
                height = 0;
                fallTime = 0;
                break;
            }
        }
    }
}

void falling() {
    while (height > 0) {
        fallTime += timer;
        height = jumpSpeed * fallTime - gravity * fallTime * fallTime / 2;
        if (height < 0) {
            height = 0;
        }

        std::cout << "Height: " << height << "\n";
        std::cout << "Fall Time: " << fallTime << "\n" << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
    }

    height = 0;
    fallTime = 0;
}

int main() {
    while (true) {
        movePosition(keyboardIn);
        //falling();
    }
    return 0;
}
