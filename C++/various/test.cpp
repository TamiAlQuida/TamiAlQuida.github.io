#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

string keyboardIn;
float height;
int millisecondsToSleep = 100;
float timer = millisecondsToSleep / 1000;
float fallTime;
const int gravity = 9.82;


void movePosition (string keyboardIn) {

    cin >> keyboardIn;
    if (keyboardIn != "w" && keyboardIn != "a" && keyboardIn != "s" && keyboardIn != "d")
    {
        cout << "enter w,a,s or d"<< "\n" << "\n";
    };

    if (keyboardIn == "w") {
        height += 100;
        timer = 0.1;
        cout << height << "\n";
    };
}


void falling () {

    while (height > 0)
    {
        fallTime += timer;
        height -= gravity * fallTime;
        if (height < 0)
        {
            height = 0;
        }
        
        cout << height << "\n";
        cout << fallTime << "\n" <<"\n";
        this_thread::sleep_for(chrono::milliseconds(millisecondsToSleep));
    }
    
    height = 0;
    fallTime = 0;    
}


int main () {

    while (true)
    {
        movePosition(keyboardIn);
        falling();        
    }
};