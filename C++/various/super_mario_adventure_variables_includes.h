
#include <SDL2/SDL.h> // sudo apt install libsdl2-dev                   used for graphics etc
#include <SDL2/SDL_image.h> // sudo apt install libsdl2-image-dev       used for showing pictures etc
#include <SDL2/SDL_mixer.h> // sudo apt-get install libsdl2-mixer-dev   used for mp3
#include <iostream>
#include <chrono> // time
#include <thread> // is used to use an extra cpu-thread, so that you can do asynchronous programming. 
#include <atomic> // async, see atomic-bool explanation below
#include <vector>
#include <string>

const int WIDTH = 1920;                                             // Width of the window
const int HEIGHT = 1080;                                            // Height of the window
const int PLAYER_WIDTH = WIDTH / 20;                                // Player width
const int PLAYER_HEIGHT = HEIGHT / 20;                              // Player height
int BADGUY_WIDTH = WIDTH / 20;                                      // BadGuy width
int BADGUY_HEIGHT = HEIGHT / 20;                                    // BadGuy height
int playerActualPositionX = 50;                                     // Player starting X position
int playerActualPositionY = HEIGHT - HEIGHT / 5 - PLAYER_HEIGHT;    // Player starting X position
int badGuyActualPositionX = WIDTH / 3;                              // BadGuy starting X position
int badGuyActualPositionY = HEIGHT - HEIGHT / 5 - BADGUY_HEIGHT;    // BadGuy starting Y position (on the ground)
float playerPositionY;
float playerPositionX;
float maxSpeed = 5.0;// m/s
int millisecondsToSleep = 25;
float timer = millisecondsToSleep / 1000.0;
float runTime = 0.0;
float fallTime = 0.0;
const float gravity = 9.82; // m/s2
const float acceleration = 60.0;
float jumpSpeed = 8.0; // m/s

std::atomic_bool isJumping(false); // atomic bool makes sure the false/true condition is updated directly so that two functions/threads wont see it as false simultaneously
std::atomic_bool isRunningRight(false);
std::atomic_bool isRunningLeft(false);
bool killed(false);

std::string pathToMp3File = "/home/tomcarl/TamiAlQuida.github.io/C++/various/maro-jump-sound-effect_1.mp3";
std::string pathToMario = "/home/tomcarl/TamiAlQuida.github.io/C++/various/player.png";
std::string pathToBadGuy = "/home/tomcarl/TamiAlQuida.github.io/C++/various/badGuy.png";
std::string pathToBigBadGuy = "/home/tomcarl/TamiAlQuida.github.io/C++/various/bigBadGuy.png";
std::string pathToLoad = pathToBadGuy;