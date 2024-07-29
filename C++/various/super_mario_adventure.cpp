#include <SDL2/SDL.h> // sudo apt install libsdl2-dev               used for graphics etc
#include <SDL2/SDL_image.h> // sudo apt install libsdl2-image-dev   used for showing pictures etc
#include <SDL2/SDL_mixer.h> //  sudo apt-get install libsdl2-mixer-dev   used for mp3
#include <iostream>
#include <chrono> // time
#include <thread> // is used to use an extra cpu-thread, so that you can do asynchronous programming. 
#include <atomic> // async, see atomic-bool explanation below

const int WIDTH = 1920;  // Width of the window
const int HEIGHT = 1080; // Height of the window
const int PLAYER_WIDTH = WIDTH / 20; // Height of the window
const int PLAYER_HEIGHT = HEIGHT / 20; // Height of the window
int PLAYER_POSITION_X = WIDTH / 2 - PLAYER_WIDTH / 2; // Height of the window
int PLAYER_POSITION_Y = HEIGHT / 2 - PLAYER_HEIGHT / 2; // Height of the window

std::string pathToMp3File = "/home/tomcarl/TamiAlQuida.github.io/C++/various/maro-jump-sound-effect_1.mp3";

float playerPositionY;
float playerPositionX;
float maxSpeed = 5.0;// m/s
int millisecondsToSleep = 25;
float timer = millisecondsToSleep / 1000.0;
float fallTime = 0.0;
float runTime = 0.0;
const float gravity = 9.82; // m/s2
const float acceleration = 60.0;
float jumpSpeed = 8.0; // m/s

std::atomic_bool isJumping(false); // atomic bool makes sure the false/true condition is updated directly so that two functions/threads wont see it as false simultaneously
std::atomic_bool isRunningRight(false);
std::atomic_bool isRunningLeft(false);

Mix_Chunk* jumpSound = nullptr; // CHECK WHY THIS IS NOT IN THE LOOP

SDL_Texture* loadTexture(const std::string &path, SDL_Renderer* renderer) {
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
    } else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr) {
            std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

bool initializeGraphics(SDL_Window** window, SDL_Renderer** renderer, SDL_Texture** playerTexture) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // Create a window
    *window = SDL_CreateWindow("Mothafucka", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!(*window)) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // Create a renderer
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (!(*renderer)) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    // Load the player texture
    *playerTexture = loadTexture("/home/tomcarl/TamiAlQuida.github.io/C++/various/player.png", *renderer);
    if (!(*playerTexture)) {
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }
    
    // Load MP3 file
    jumpSound = Mix_LoadWAV(pathToMp3File.c_str());
    if (!jumpSound) {
        std::cerr << "Failed to load jump sound effect: " << Mix_GetError() << std::endl;
        SDL_DestroyTexture(*playerTexture);
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        Mix_CloseAudio();
        SDL_Quit();
        return false;
    }

    return true;
}

void refreshScreen (SDL_Renderer* renderer, SDL_Texture* playerTexture) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    // Draw background/sky (baby blue)
    SDL_SetRenderDrawColor(renderer, 60, 206, 247, 0xFF);
    SDL_Rect leftHalf = {0, 0, WIDTH, HEIGHT};
    SDL_RenderFillRect(renderer, &leftHalf);

    // Draw ground (brown)
    SDL_SetRenderDrawColor(renderer, 154, 56, 18, 0xFF);
    SDL_Rect rightHalf = {0, HEIGHT - HEIGHT / 5, WIDTH, HEIGHT - HEIGHT / 5};
    SDL_RenderFillRect(renderer, &rightHalf);

    // Draw player (PNG)
    SDL_Rect player = {PLAYER_POSITION_X, PLAYER_POSITION_Y, PLAYER_WIDTH, PLAYER_HEIGHT};
    SDL_RenderCopy(renderer, playerTexture, NULL, &player);
    
    // Update screen
    SDL_RenderPresent(renderer);
}

void jump(SDL_Renderer* renderer, SDL_Texture* playerTexture) {
    isJumping = true;
    Mix_PlayChannel(-1, jumpSound, 0);
    while (isJumping) {
        fallTime += timer;
        playerPositionY = jumpSpeed * fallTime - gravity * fallTime * fallTime / 2;
        PLAYER_POSITION_Y = HEIGHT - HEIGHT / 5 - playerPositionY * 100;
        refreshScreen(renderer, playerTexture);
        std::cout << "Height: " << playerPositionY << "\n";
        std::cout << "Fall Time: " << fallTime << "\n" << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
        if (playerPositionY <= 0) {
            playerPositionY = 0;
            fallTime = 0;
            break;
        }
    }
    isJumping = false;
}

void runRight(SDL_Renderer* renderer, SDL_Texture* playerTexture) {
    isRunningRight = true;
    while (isRunningRight) {
        if (playerPositionX <= maxSpeed)
        {
            playerPositionX = 0.1;
            runTime += timer;
            playerPositionX = playerPositionX * acceleration * runTime;
            PLAYER_POSITION_X = PLAYER_POSITION_X + playerPositionX * 10;
            refreshScreen(renderer, playerTexture);
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
        }
        else if (playerPositionX >= maxSpeed)
        {
            PLAYER_POSITION_X = PLAYER_POSITION_X + maxSpeed * 10;
            refreshScreen(renderer, playerTexture);
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
        }        
    }
    runTime = 0;
    playerPositionX = 0;
}

void runLeft(SDL_Renderer* renderer, SDL_Texture* playerTexture) {
    isRunningLeft = true;
    while (isRunningLeft) {
        if (playerPositionX <= maxSpeed)
        {
            playerPositionX = 0.1;
            runTime += timer;
            playerPositionX = playerPositionX * acceleration * runTime;
            PLAYER_POSITION_X = PLAYER_POSITION_X - playerPositionX * 10;
            refreshScreen(renderer, playerTexture);
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
        }
        else if (playerPositionX >= maxSpeed)
        {
            PLAYER_POSITION_X = PLAYER_POSITION_X - maxSpeed * 10;
            refreshScreen(renderer, playerTexture);
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
        }
    
    }
    runTime = 0;
    playerPositionX = 0;
}



int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* playerTexture = nullptr;

    if (!initializeGraphics(&window, &renderer, &playerTexture)) {
        return 1;
    }

    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

    // Main loop
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } 
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    case SDLK_UP:
                        std::cout << "up key pressed" << std::endl;
                        PLAYER_POSITION_Y -= PLAYER_HEIGHT;
                        break;
                    case SDLK_DOWN:
                        std::cout << "down key pressed" << std::endl;
                        PLAYER_POSITION_Y += PLAYER_HEIGHT;
                        break;
                    case SDLK_RIGHT:
                        std::cout << "right key pressed" << std::endl;
                        PLAYER_POSITION_X += PLAYER_WIDTH;
                        break;
                    case SDLK_LEFT:
                        std::cout << "left key pressed" << std::endl;
                        PLAYER_POSITION_X -= PLAYER_WIDTH;
                        break;
                    case SDLK_w:
                        std::cout << "w key pressed" << std::endl;
                        if (!isJumping) {
                            std::thread jumpThread(jump, renderer, playerTexture);
                            jumpThread.detach();
                        }
                        break;
                    case SDLK_d:
                        std::cout << "d key pressed" << std::endl;
                        if (playerPositionX < maxSpeed && !isRunningRight) {
                            std::thread runThread(runRight, renderer, playerTexture);
                            runThread.detach();
                        }
                        break;
                    case SDLK_a:
                        std::cout << "a key pressed" << std::endl;
                        if (playerPositionX < maxSpeed && !isRunningLeft) {
                            std::thread runThread(runLeft, renderer, playerTexture);
                            runThread.detach();
                        }
                        break;
                }
            }
            else if (e.type == SDL_KEYUP) {
                switch (e.key.keysym.sym) {
                    case SDLK_d:
                    std::cout << "d up" << std::endl;
                    isRunningRight = false;
                    case SDLK_a:
                    std::cout << "a up" << std::endl;
                    isRunningLeft = false;
                }
            }
        }

        refreshScreen(renderer, playerTexture);
    }

    // Destroy window and renderer
    SDL_DestroyTexture(playerTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_FreeChunk(jumpSound);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
