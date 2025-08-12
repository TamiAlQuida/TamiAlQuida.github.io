#include <iostream>
#include <fcntl.h>   // For open()
#include <unistd.h>  // For close()
#include <linux/input.h>  // For input events
#include <cstring>    // For memset
#include <cstdlib>    // For exit()

int main() {
    // Replace 'event10' with the correct event file (bash: evtest)
    const char* device_path = "/dev/input/event11";
    int fd = open(device_path, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        std::cerr << "Failed to open input device: " << device_path << std::endl;
        return 1;
    }

    // Buffer to store input events
    struct input_event ev;
    while (true) {
        int bytes_read = read(fd, &ev, sizeof(ev));
        if (bytes_read == sizeof(ev)) {
            // Process the event
            if (ev.type == EV_KEY) {
                std::cout << "Button Pressed: " << ev.code << " (Value: " << ev.value << ")" << std::endl;
            } else if (ev.type == EV_ABS) {
                std::cout << "Axis Changed: " << ev.code << " (Value: " << ev.value << ")" << std::endl;
            }
        }
    }

    close(fd);
    return 0;
}

//#include <libevdev/libevdev.h> //sudo apt install libevdev-dev
//#include <iostream>
//#include <fcntl.h>
//#include <unistd.h>
//
//int main() {
//    const char* device_path = "/dev/input/event12"; // Replace with your device path (bash: evtest)
//    int fd = open(device_path, O_RDWR);
//    if (fd == -1) {
//        std::cerr << "Failed to open device: " << device_path << std::endl;
//        return 1;
//    }
//
//    struct libevdev* dev = libevdev_new();
//    if (libevdev_set_fd(dev, fd) < 0) {
//        std::cerr << "Failed to set fd" << std::endl;
//        return 1;
//    }
//
//    while (true) {
//        int events;
//        if ((events = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_BLOCKING)) == LIBEVDEV_READ_STATUS_SUCCESS) {
//            struct input_event* ev = libevdev_event_get_event(dev, events);
//            if (ev->type == EV_KEY) {
//                std::cout << "Button: " << ev->code << " Value: " << ev->value << std::endl;
//            }
//        }
//    }
//
//    libevdev_unref(dev);
//    close(fd);
//    return 0;
//}

