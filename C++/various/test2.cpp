#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>
#include <iostream>

int main() {
    Display* display = XOpenDisplay(NULL);
    if (display == NULL) {
        std::cerr << "Unable to open X display\n";
        return 1;
    }

    // Get the keycode for the 'w' key
    KeyCode w_key = XKeysymToKeycode(display, XStringToKeysym("w"));
    if (w_key == 0) {
        std::cerr << "Unable to get keycode for 'w'\n";
        return 1;
    }

    while (true) {
        // Press 'w'
        XTestFakeKeyEvent(display, w_key, True, CurrentTime);
        XFlush(display);
        std::cout << "Pressed 'w'\n";
        sleep(2);  // Hold for 2 seconds

        // Release 'w'
        XTestFakeKeyEvent(display, w_key, False, CurrentTime);
        XFlush(display);
        std::cout << "Released 'w'\n";
        sleep(2);  // Release for 2 seconds
    }

    XCloseDisplay(display);
    return 0;
}