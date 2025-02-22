#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

const int WIDTH = 1920;                                             // Width of the window
const int HEIGHT = 1080;                                            // Height of the window

std::string pathToMario = "/home/tomcarl/TamiAlQuida.github.io/C++/various/player.png";
std::string pathToBadGuy = "/home/tomcarl/TamiAlQuida.github.io/C++/various/badGuy.png";
std::string pathToBigBadGuy = "/home/tomcarl/TamiAlQuida.github.io/C++/various/bigBadGuy.png";

int counter;

class createCharacter
{
private:
    
public:
    std::string name = "character";
    int number1;
    int characterType;
    int pretendNumber = 7;
    createCharacter(int number);     // call constructor
    static void createObjectsFromClass(std::vector<createCharacter>& characters, int number);// Static member function to create objects
};


createCharacter::createCharacter(int number) // define constructor
{
    name += std::to_string(counter);
    counter++;
    characterType = rand() % 3;
    number1 = number;
    std::cout << "Character Name: " << name << ", counter. " << counter << ", "  << ", caracterType: " << characterType << ", " << number << std::endl;

    if (characterType == 0)
    {
        int characterHeight = WIDTH / 20;
        int characterWidth = HEIGHT / 20;
        std::cout << "imagepath:" << pathToMario << std::endl;
        //std::cout << "characterHeight" << characterHeight << std::endl;
        //std::cout << "characterWidth" << characterWidth << "\n" << std::endl;
    }
    else if (characterType == 1)
    {
        int characterHeight = WIDTH / 20;
        int characterWidth = HEIGHT / 20;
        std::cout << "imagepath:" << pathToBadGuy << std::endl;
        //std::cout << "characterHeight" << characterHeight << std::endl;
        //std::cout << "characterWidth" << characterWidth << "\n" << std::endl;
    }
    else if (characterType == 2)
    {
        int characterHeight = WIDTH / 10;
        int characterWidth = HEIGHT / 10;
        std::cout << "imagepath:" << pathToBigBadGuy << std::endl;
        //std::cout << "characterHeight" << characterHeight << std::endl;
        //std::cout << "characterWidth" << characterWidth << "\n" << std::endl;
    }
    
}

void createCharacter::createObjectsFromClass(std::vector<createCharacter>& characters, int number) {
    characters.emplace_back(number);
}


int main () {
    std::vector<createCharacter> characters;

    while (true)
    {
        createCharacter::createObjectsFromClass(characters, 12);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
};