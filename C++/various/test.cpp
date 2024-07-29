#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

string keyboardIn;
float playerPositionY;
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
        playerPositionY += 100;
        timer = 0.1;
        cout << playerPositionY << "\n";
    };
}


void falling () {

    while (playerPositionY > 0)
    {
        fallTime += timer;
        playerPositionY -= gravity * fallTime;
        if (playerPositionY < 0)
        {
            playerPositionY = 0;
        }
        
        cout << playerPositionY << "\n";
        cout << fallTime << "\n" <<"\n";
        this_thread::sleep_for(chrono::milliseconds(millisecondsToSleep));
    }
    
    playerPositionY = 0;
    fallTime = 0;    
}


int main () {

    while (true)
    {
        movePosition(keyboardIn);
        falling();        
    }
};