#include <iostream>
using namespace std;

int numberOfChairs = 20;

class SkiChair {
    // A class that contains data about ski chairs
    public:
        string chairName;
        int inhabitants;
};

void addingToAList () {
    SkiChair listOfChairs[numberOfChairs];

    for (int i = 0; i < numberOfChairs; i++)
    {
        listOfChairs[i].chairName = "chair" + to_string(i);
        int random = rand() % 4;
        listOfChairs[i].inhabitants = random;
    }
    
    for (int i = 0; i < numberOfChairs; i++)
    {
        cout << listOfChairs[i].chairName << "\n";
        cout << listOfChairs[i].inhabitants << "\n" << "\n";
    }
};

int main() {
    SkiChair chairNum1;
    chairNum1.chairName = "chairX";
    chairNum1.inhabitants = 6;

    cout << chairNum1.chairName << "\n";
    cout << chairNum1.inhabitants << "\n";
    addingToAList();
    cout << listOfChairs[0].chairName << "\n";
};
