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
    cout << "hello world" << "\n";
    //return 0;
};

int main() {
    addingToAList();
    SkiChair chairNum1;
    chairNum1.chairName = "chairX";
    chairNum1.inhabitants = 6;

    cout << chairNum1.chairName << "\n";
    cout << chairNum1.inhabitants << "\n";
    SkiChair listOfChairs[numberOfChairs];
    //listOfChairs[0].chairName = "Chair0";
    //listOfChairs[1].chairName = "Chair1";
    //cout << listOfChairs[0].chairName << "\n";
    //cout << listOfChairs[1].chairName << "\n";

    for (int i = 0; i < numberOfChairs; i++)
    {
        listOfChairs[i].chairName = "chair" + to_string(i);
    }
    

    for (int i = 0; i < numberOfChairs; i++)
    {
        cout << listOfChairs[i].chairName << "\n";
    }

    cout << listOfChairs[0].chairName << "\n";
    cout << listOfChairs[1].chairName << "\n";
    
};
