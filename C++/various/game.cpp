#include <iostream>
using namespace std;

string keyboardIn;
int coordinates[5][5] = {
{0, 0, 0, 0 ,0},
{0, 0, 0, 0 ,0},
{0, 0, 1, 0 ,0},
{0, 0, 0, 0 ,0},
{0, 0, 0, 0 ,0}
};
const char* namesOfRooms[5][5] = {
{"Open sea", "River lands", "Swamp", "Mangroove" ,"Tree top kingdom"},
{"1000 islands", "Red frog beach", "Jungle", "Thick jungle" ,"Coconut tree forest"},
{"Grasslands peninsula", "Flower garden", "Entrance (cave in the ground)", "Dessert" ,"Beach by a lake"},
{"Grassland horizon", "Grasslans hills", "Steep hill", "Canyon lands" ,"Scourching mountains"},
{"Top of the world", "Snowy mountains", "Mountain wall", "Rocky mountains" ,"Volcano"}
};

void movePosition (string keyboardIn) {
    //Ask for input
    cin >> keyboardIn;
    
    //check if correct form of input, tell otherwise
    if (keyboardIn != "w" && keyboardIn != "a" && keyboardIn != "s" && keyboardIn != "d" && keyboardIn != "W" && keyboardIn != "A" && keyboardIn != "S" && keyboardIn != "D")
    {
        cout << "enter w,a,s or d"<< "\n" << "\n";
    };
    
    //if correct input do below
    if (keyboardIn == "w" || keyboardIn == "W")
        {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (coordinates[i][j] == 1 && coordinates[0][j] != 1)
                {
                    coordinates[i][j] = 0;
                    coordinates[i-1][j] = 1;
                    cout << i << j;
                    cout << "\n" << "\n";
                }
            }
        }
    };

    if (keyboardIn == "a" || keyboardIn == "A")
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (coordinates[i][j] == 1== 1 && coordinates[i][0] != 1)
                {
                    coordinates[i][j] = 0;
                    coordinates[i][j-1] = 1;
                    cout << i << j;
                    cout << "\n" << "\n";                        
                }
            }
        }
    };

    if (keyboardIn == "s" || keyboardIn == "S")
    {
        for (int i = 0; i < 5; i++)
        {
            bool outerBreak = false;
            for (int j = 0; j < 5; j++)
            {
                if (coordinates[i][j] == 1 && coordinates[4][j] != 1)
                {
                    coordinates[i][j] = 0;
                    coordinates[i+1][j] = 1;
                    outerBreak = true;
                    cout << i << j;
                    cout << "\n" << "\n";                                 
                    break;
                }
            }
            if (outerBreak) 
            {
                break;
            }                    
        }
    };

    if (keyboardIn == "d" || keyboardIn == "D")
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (coordinates[i][j] == 1 && coordinates[i][4] != 1)
                {
                    coordinates[i][j] = 0;
                    coordinates[i][j+1] = 1;
                    cout << i << j;
                    cout << "\n" << "\n";                        
                    break;
                }
            }
        }
    };
}

void printMatrix () {
    for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << coordinates[i][j] << " ";
            }
        
        cout << "\n";
        }
    cout << "\n";
}

void printLocation () {
    for (int i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if (coordinates[i][j] == 1)
            {
                cout << namesOfRooms[i][j] << "\n";
                break;
            }
        }
    }
}


int main () {

    cout << "Welcome, fellow traveler. Press W/A/S/D + Enter" << "\n";

    while (true)
    {
        movePosition(keyboardIn);
        printMatrix();
        printLocation();
    }
};