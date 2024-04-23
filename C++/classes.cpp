#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

const int amountOfChairs = 20;
int totalInhabitants = 0;

class SkiChair {
    // A class that contains data about ski chairs
    public:
        string chairName;
        int inhabitants;
};

SkiChair listOfChairs[amountOfChairs]; //creates a list full of objects made from the class

void addingToAList () {

    //loop through the list and empty chair at the top, add values to the objects + print + sleep
    for (int i = 0; i < amountOfChairs; i++)
    {   
        //empty the last chair
        if (i < 19)
        {
            totalInhabitants -= listOfChairs[i+1].inhabitants;
            listOfChairs[i+1].inhabitants = 0;
        }

        else if (i == 19)
        {
            totalInhabitants -= listOfChairs[0].inhabitants;
            listOfChairs[0].inhabitants = 0;
        }

        //add values to object /fill first chair and name it
        listOfChairs[i].chairName = "chair" + to_string(i);
        int random = rand() % 5;
        listOfChairs[i].inhabitants = random;
        //print the values
        cout << listOfChairs[i].chairName << "\n";
        cout << listOfChairs[i].inhabitants << "\n";
        
        totalInhabitants += listOfChairs[i].inhabitants;
        cout << totalInhabitants<< "\n" << "\n";

        //sleep
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
};

int main() {
    while (true)
    {
        addingToAList();
    }
};
