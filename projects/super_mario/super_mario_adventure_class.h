
#include "super_mario_adventure_variables_includes.h"

int counter;

class createCharacter
{
private:
    
public:
    std::string name = "character";
    int characterType;
    static bool isAlive;
    createCharacter();                                          // call constructor
    static void killCharacter();
};

// Define and initialize the static member outside the class
bool createCharacter::isAlive = true;

createCharacter::createCharacter() // define constructor
{
    name += std::to_string(counter);
    counter++;
    characterType = rand() % 3;
    isAlive = true;
    std::cout << "Character Name: " << name << ", counter: " << counter << ", caracterType: " << characterType << ", isAlive: " << isAlive << std::endl;

    if (characterType == 0)
    {
        BADGUY_WIDTH = WIDTH / 20;                             // BadGuy width (same as player for simplicity)
        BADGUY_HEIGHT = HEIGHT / 20;                           // BadGuy height (same as player for simplicity)
        pathToLoad = pathToMario;
        std::cout << "imagepath:" << pathToMario << std::endl;

    }
    else if (characterType == 1)
    {
        BADGUY_WIDTH = WIDTH / 20;                             // BadGuy width (same as player for simplicity)
        BADGUY_HEIGHT = HEIGHT / 20;                           // BadGuy height (same as player for simplicity)
        pathToLoad = pathToBadGuy;
        std::cout << "imagepath:" << pathToBadGuy << std::endl;
    }
    else if (characterType == 2)
    {
        BADGUY_WIDTH = WIDTH / 10;                             // BadGuy width (same as player for simplicity)
        BADGUY_HEIGHT = HEIGHT / 10;                           // BadGuy height (same as player for simplicity)
        pathToLoad = pathToBigBadGuy;
        std::cout << "imagepath:" << pathToBigBadGuy << std::endl;
    }
}

void createCharacter::killCharacter() // define function
{
    std::cout << "killCharacter" << std::endl;
    std::cout << "isAlive=" << isAlive << std::endl;
    isAlive = false;
    std::cout << "isAlive=" << isAlive << std::endl;
}