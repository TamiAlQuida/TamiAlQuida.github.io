
#include <chrono>
#include <thread>
#include <vector>
#include <string>

const int WIDTH = 1920;                                             // Width of the window
const int HEIGHT = 1080;                                            // Height of the window

const int PLAYER_WIDTH = WIDTH / 20;                                // Player width
const int PLAYER_HEIGHT = HEIGHT / 20;                              // Player height
int BADGUY_WIDTH = PLAYER_WIDTH;                              // BadGuy width (same as player for simplicity)
int BADGUY_HEIGHT = PLAYER_HEIGHT;                            // BadGuy height (same as player for simplicity)
int playerActualPositionX = 50;                                     // Player starting X position
int playerActualPositionY = HEIGHT - HEIGHT / 5 - PLAYER_HEIGHT;    // Player starting X position
int badGuyActualPositionX = WIDTH / 3;                              // BadGuy starting X position
int badGuyActualPositionY = HEIGHT - HEIGHT / 5 - BADGUY_HEIGHT;    // BadGuy starting Y position (on the ground)


std::string pathToMp3File = "/home/tomcarl/TamiAlQuida.github.io/C++/various/maro-jump-sound-effect_1.mp3";
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
    std::cout << "Character Name: " << name << ", counter: " << counter << ", "  << ", caracterType: " << characterType << ", " << number << std::endl;

    if (characterType == 0)
    {
        BADGUY_WIDTH = WIDTH / 20;                             // BadGuy width (same as player for simplicity)
        BADGUY_HEIGHT = HEIGHT / 20;                           // BadGuy height (same as player for simplicity)
        pathToBadGuy = "/home/tomcarl/TamiAlQuida.github.io/C++/various/player.png";
        std::cout << "imagepath:" << pathToMario << std::endl;

    }
    else if (characterType == 1)
    {
        BADGUY_WIDTH = WIDTH / 20;                             // BadGuy width (same as player for simplicity)
        BADGUY_HEIGHT = HEIGHT / 20;                           // BadGuy height (same as player for simplicity)
        pathToBadGuy = "/home/tomcarl/TamiAlQuida.github.io/C++/various/badGuy.png";
        std::cout << "imagepath:" << pathToBadGuy << std::endl;
    }
    else if (characterType == 2)
    {
        BADGUY_WIDTH = WIDTH / 10;                             // BadGuy width (same as player for simplicity)
        BADGUY_HEIGHT = HEIGHT / 10;                           // BadGuy height (same as player for simplicity)
        pathToBadGuy = "/home/tomcarl/TamiAlQuida.github.io/C++/various/bigBadGuy.png";
        std::cout << "imagepath:" << pathToBigBadGuy << std::endl;
    }
    
}




    
