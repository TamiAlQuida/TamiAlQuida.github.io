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
{"0", "0", "0", "0" ,"0"},
{"0", "0", "Djungle", "0" ,"0"},
{"0", "Flower garden", "Entrance (cave in the ground)", "Beach by a lake" ,"0"},
{"0", "0", "Steep hill", "0" ,"0"},
{"0", "0", "Mountain wall", "0" ,"0"}
};

void movePosition (string keyboardIn) {
    //Ask for input
    cin >> keyboardIn;
    
    //check if correct form of input, tell otherwise
    if (keyboardIn != "w" && keyboardIn != "a" && keyboardIn != "s" && keyboardIn != "d")
    {
        cout << "enter w,a,s or d"<< "\n" << "\n";
    };
    
    //if correct input do below
    if (keyboardIn == "w")
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

    if (keyboardIn == "a")
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

    if (keyboardIn == "s")
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

    if (keyboardIn == "d")
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