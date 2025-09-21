#include <iostream>
#include <cstdlib> // For system()

int main() {
    // Example: Record a 10-second video and save it to "test.h264"
    // Note: Construct the command string dynamically if you need to change parameters
    std::string command = "rpicam-vid -t 10000 -o test.h264";

    std::cout << "Executing command: " << command << std::endl;
    int result = system(command.c_str()); // Execute the command

    if (result == 0) {
        std::cout << "Video capture successful." << std::endl;
    } else {
        std::cerr << "Video capture failed." << std::endl;
    }

    return 0;
}

//https://www.raspberrypi.com/documentation/computers/camera_software.html
//sudo rpicam-vid -t 0 -n --codec libav --libav-format mpegts -o tcp://0.0.0.0:81?listen=1
//vlc tcp://100.78.223.99:81/stream1
