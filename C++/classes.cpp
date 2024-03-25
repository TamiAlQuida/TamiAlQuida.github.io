#include <iostream>
using namespace std;

string skiChairs[2][2] = {
    {"8", "9"},
    {"0", "1"}
};

class SkiChair {
    // A class that contains data about ski chairs
    public:
        string chairName;
        int inhabitants;
};

void addingToAList () {
    cout << "hello world" << "\n";
    //return 0;
};

int main() {
    addingToAList();
    SkiChair chairNum1;
    chairNum1.chairName = "chair1";
    chairNum1.inhabitants = 6;

    cout << chairNum1.chairName << "\n";
    cout << chairNum1.inhabitants << "\n";
    cout << skiChairs[3][3] << "\n";
};
