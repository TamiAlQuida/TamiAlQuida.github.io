#include <SDL2/SDL.h> //sudo apt install libsdl2-dev
#include <SDL2/SDL_image.h> //sudo apt install libsdl2-image-dev  
#include <iostream>

const int WIDTH = 1200;  // Width of the window
const int HEIGHT = 800; // Height of the window
const int PLAYER_WIDTH = WIDTH / 10; // Height of the window
const int PLAYER_HEIGHT = HEIGHT / 10; // Height of the window
int PLAYER_POSITION_X = WIDTH / 2 - PLAYER_WIDTH / 2; // Height of the window
int PLAYER_POSITION_Y = HEIGHT / 2 - PLAYER_HEIGHT / 2; // Height of the window

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

    return true;
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
            } else if (e.type == SDL_KEYDOWN) {
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
                }
            }
        }

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

    // Destroy window and renderer
    SDL_DestroyTexture(playerTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
