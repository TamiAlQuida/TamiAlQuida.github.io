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

        cout << listOfChairs[i].chairName << "\n";
        cout << listOfChairs[i].inhabitants << "\n" << "\n";
    }
};

int main() {
    addingToAList();
};
