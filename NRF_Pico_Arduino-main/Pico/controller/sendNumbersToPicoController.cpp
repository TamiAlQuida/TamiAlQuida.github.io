
#include <iostream>
#include <fstream>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <iomanip>   // For std::setw and std::setfill
#include <sstream>   // For std::ostringstream
#include <chrono>
#include <thread>


#define CENTER 128


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
    std::ofstream serialPort("/dev/ttyACM0");

    // Check if the port is open
    if (!serialPort.is_open()) {
        std::cerr << "Failed to open /dev/ttyACM0" << std::endl;
        return 1;
    }

    input_event event;
    while (read(fd, &event, sizeof(input_event)) > 0) {
        
        //Identify event 
        //std::cout << "Event: " << std::endl
        //        << "type=" << event.type
        //          << ", code=" << event.code
        //          << ", value=" << event.value
        //          << ", time=" << event.time.tv_sec << "." << event.time.tv_usec
        //          << std::endl;;


        if (event.type == EV_ABS && (event.code == 0 || event.code == 1)) {
            update_left_joystick_position(event);

            // Format the numbers to always contain 3 digits
            std::string sendPackage1 = formatToThreeDigits(left_joystick[0]);
            std::string sendPackage2 = formatToThreeDigits(left_joystick[1]);
    
            // Combine the formatted strings
            std::string sendPackageComplete = sendPackage1 + sendPackage2;
            serialPort << sendPackageComplete << std::endl;  // Add newline
            std::cout << "Sent: " << sendPackageComplete << std::endl;
            serialPort.flush();
        }
        
    }

    close(fd);
    serialPort.close();
    return 0;
}