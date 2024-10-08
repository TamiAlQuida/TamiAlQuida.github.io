#include <iostream>
#include <fstream>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctime>
#include <stdlib.h>
#include <iomanip>   // For std::setw and std::setfill
#include <sstream>   // For std::ostringstream
#include <thread>

#define CENTER 128
#define BLIND 6
#define MAX_EMERGENCY_DELAY 1000

std::string button_presses[] = {
    "square", "x", "circle", "triangle", "L1", "R1", "L2", "R2",
    "share", "pause", "L3", "R3", "playstation", "touchpad"
};

std::string button_values[] = {"up", "down"};

std::string absolutes[] = {
    "left joystick left/right", "left joystick up/down", 
    "right joystick left/right", "L2 analog", "R2 analog", 
    "right joystick up/down", "", "", "", "", "", "", "", "", 
    "leftpad left/right", "leftpad up/down"
};

int left_joystick[2] = {CENTER, CENTER};
int right_joystick[2] = {CENTER, CENTER};


void update_left_joystick_position(input_event &event) {
    if (event.code == 0) { // left joystick, x-axis (left/right)
        left_joystick[0] = event.value;
    } else if (event.code == 1) { // left joystick, y-axis (up/down)
        left_joystick[1] = event.value;
    }
}

void update_right_joystick_position(input_event &event) {
    if (event.code == 2) { // right joystick, x-axis (left/right)
        right_joystick[0] = event.value;
    } else if (event.code == 5) { // right joystick, y-axis (up/down)
        right_joystick[1] = event.value;
    }
}

std::string formatToThreeDigits(int number) {
    std::ostringstream ss;
    ss << std::setfill('0') << std::setw(3) << number;
    return ss.str();
}

int main() {
    int fd;
    for (int i = 0; i < 20; i++){
        std::string device = "/dev/input/event" + std::to_string(i); 
        fd = open(device.c_str(), O_RDONLY);
        if (fd < 0) {
            std::cerr << "Error: Could not open input device " << device << std::endl;
        }
        else {
            std::cout << "Successfully opened " << device << std::endl;
            break;
        }
    }

    // Open the serial port for writing
    std::ofstream serialPort("/dev/ttyACM1");

    // Check if the port is open
    if (!serialPort.is_open()) {
        std::cerr << "Failed to open /dev/ttyACM1" << std::endl;
        return 1;
    }

    input_event event;
//    while (read(fd, &event, sizeof(input_event)) > 0) {
                
//        //Identify event 
//        //std::cout << "Event: " << std::endl
//        //        << "type=" << event.type
//        //          << ", code=" << event.code
//        //          << ", value=" << event.value
//        //          << ", time=" << event.time.tv_sec << "." << event.time.tv_usec
//        //          << std::endl;;
//
//
//        // Format the numbers to always contain 3 digits
//        std::string sendPackage1 = formatToThreeDigits(left_joystick[0]);
//        std::string sendPackage2 = formatToThreeDigits(left_joystick[1]);
//    
//        // Combine the formatted strings
//        std::string sendPackageComplete = sendPackage1 + sendPackage2;
//        serialPort << sendPackageComplete;
//        std::cout << sendPackageComplete << std::endl;
//        serialPort.flush();
//
//        if (event.type == EV_ABS && event.code >= 0 && event.code <= 17) {
//            std::string action = absolutes[event.code];
//            int value = event.value;
//
//            if (event.code == 0 || event.code == 1) { // left joystick
//                update_left_joystick_position(event);
//            } else if (event.code == 2 || event.code == 5) { // right joystick
//                update_right_joystick_position(event);
//            }
//        }
//    }

    int counter_x = 0;
    int counter_y = 0;
    while (true) {
        std::string message = formatToThreeDigits(counter_x) + formatToThreeDigits(counter_y);
        std::cout << "Sending: " << message << std::endl;
        serialPort << message;
        serialPort.flush();

        counter_x = (counter_x + 1) % 1000;
        if (counter_x == 0) {
            counter_y = (counter_y + 1) % 1000;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    close(fd);
    serialPort.close();
    return 0;
}