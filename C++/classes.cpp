#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

const int amountOfChairs = 20;

class SkiChair {
    // A class that contains data about ski chairs
    public:
        string chairName;
        int inhabitants;
};

SkiChair listOfChairs[amountOfChairs]; //creates a list full of objects made from the class

void addingToAList () {

    //loop through the list and add values to the objects + print + sleep
    for (int i = 0; i < amountOfChairs; i++)
    {   //add values to object
        listOfChairs[i].chairName = "chair" + to_string(i);
        int random = rand() % 5;
        listOfChairs[i].inhabitants = random;
        //print the values
        cout << listOfChairs[i].chairName << "\n";
        cout << listOfChairs[i].inhabitants << "\n" << "\n";
        for (int i = 0; amountOfChairs < amountOfChairs; i++)
        {
            int totalInhabitants =+ listOfChairs[i].inhabitants;
            int avgInhabitants = totalInhabitants / amountOfChairs;
        }
        
        cout << avgInhabitants << "\n";

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
