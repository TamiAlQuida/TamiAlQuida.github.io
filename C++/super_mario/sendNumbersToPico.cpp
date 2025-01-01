#include <iostream>
#include <fstream>
#include <unistd.h>  // For sleep function

int main() {
    // Open the serial port for writing
    std::ofstream serialPort("/dev/ttyACM0");

    // Check if the port is open
    if (!serialPort.is_open()) {
        std::cerr << "Failed to open /dev/ttyACM0" << std::endl;
        return 1;
    }

    int number = 1;

    // Loop to send numbers
    while (true) {
        // Send the current number followed by a newline
        serialPort << number << std::endl;

        // Print to console for debugging/confirmation
        std::cout << "Sent: " << number << std::endl;

        // Increment the number
        number++;

        // Flush the output to make sure data is sent immediately
        serialPort.flush();

        // Wait for 1 second before sending the next number
        sleep(1);
    }

    // Close the serial port (though this code will never reach here)
    serialPort.close();

    return 0;
}
