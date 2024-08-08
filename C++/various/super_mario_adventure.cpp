
#include "super_mario_adventure_class.h" // includes a class + function and some search paths, other variables and all the needed #include

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

bool initializeGraphics(SDL_Window** window, SDL_Renderer** renderer, SDL_Texture** playerTexture, SDL_Texture** badGuyTexture) {
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
    *playerTexture = loadTexture(pathToMario, *renderer);
    if (!(*playerTexture)) {
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    // Load bad guy texture
    *badGuyTexture = loadTexture(pathToBadGuy, *renderer);
    if (!(*badGuyTexture)) {
        SDL_DestroyTexture(*playerTexture);
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
        SDL_DestroyTexture(*badGuyTexture);
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        Mix_CloseAudio();
        SDL_Quit();
        return false;
    }

    return true;
}

void refreshScreen (SDL_Renderer* renderer, SDL_Texture* playerTexture, SDL_Texture* badGuyTexture) {
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
    SDL_Rect player = {playerActualPositionX, playerActualPositionY, PLAYER_WIDTH, PLAYER_HEIGHT};
    SDL_RenderCopy(renderer, playerTexture, NULL, &player);

    // Draw BadGuy (PNG)
    SDL_Rect badGuy = {badGuyActualPositionX, badGuyActualPositionY, BADGUY_WIDTH, BADGUY_HEIGHT};
    SDL_RenderCopy(renderer, badGuyTexture, NULL, &badGuy);
    
    // Update screen
    SDL_RenderPresent(renderer);
}

void jump() {
    isJumping = true;
    Mix_PlayChannel(-1, jumpSound, 0);
    while (isJumping) {
        fallTime += timer;
        playerPositionY = jumpSpeed * fallTime - gravity * fallTime * fallTime / 2;
        if (playerPositionY <= 0) {
            playerPositionY = 0;
            fallTime = 0;
            playerActualPositionY = HEIGHT - HEIGHT / 5 - PLAYER_HEIGHT - playerPositionY * 100;
            break;
        }
        playerActualPositionY = HEIGHT - HEIGHT / 5 - PLAYER_HEIGHT - playerPositionY * 100;
        //std::cout << "Height: " << playerPositionY << "\n";
        //std::cout << "Fall Time: " << fallTime << "\n" << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
    }
    if (isJumping = true)
    {
        isJumping = false;
    }    
}

void runRight() {
    isRunningRight = true;
    while (isRunningRight) {
        if (playerPositionX <= maxSpeed)
        {
            playerPositionX = 0.1;
            runTime += timer;
            playerPositionX = playerPositionX * acceleration * runTime;
            playerActualPositionX = playerActualPositionX + playerPositionX * 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
        }
        else if (playerPositionX >= maxSpeed)
        {
            playerActualPositionX = playerActualPositionX + maxSpeed * 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
        }        
    }
    runTime = 0;
    playerPositionX = 0;
}

void runLeft() {
    isRunningLeft = true;
    while (isRunningLeft) {
        if (playerPositionX <= maxSpeed)
        {
            playerPositionX = 0.1;
            runTime += timer;
            playerPositionX = playerPositionX * acceleration * runTime;
            playerActualPositionX = playerActualPositionX - playerPositionX * 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
        }
        else if (playerPositionX >= maxSpeed)
        {
            playerActualPositionX = playerActualPositionX - maxSpeed * 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
        }
    
    }
    runTime = 0;
    playerPositionX = 0;
}

void runLeftBadGuy() {
    while (true)
    {
        if (badGuyActualPositionX > 0)
        {
            badGuyActualPositionX -= 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsToSleep));
        }
        
        else
        {
            badGuyActualPositionX = WIDTH;
        }        
    }    
}

void startBadGuyRunLeftThread() { //needs to be defined here for some reason so "case" can understand it
    std::thread badGuyRunLeftThread(runLeftBadGuy);
    badGuyRunLeftThread.detach();
}

bool chechForCollision() {

    if ((playerActualPositionY <= badGuyActualPositionY - BADGUY_HEIGHT*2/3 && playerActualPositionY >= badGuyActualPositionY - BADGUY_HEIGHT) &&
        !(playerActualPositionX - badGuyActualPositionX < -75 || playerActualPositionX - badGuyActualPositionX > 50)) // kill enemy)
    {
        std::cout << "You killed him" << std::endl;
        killed = true;
        return false;
    }

    if (playerActualPositionY >= badGuyActualPositionY - BADGUY_HEIGHT*2/3 &&
        !(playerActualPositionX - badGuyActualPositionX < -75 || playerActualPositionX - badGuyActualPositionX > 50)) // die if walk into enemy
    {
        std::cout << "GAME OVER" << std::endl;

        return true;
    }

    return false;
}

int main() {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* playerTexture = nullptr;
    SDL_Texture* badGuyTexture = nullptr;

    if (!initializeGraphics(&window, &renderer, &playerTexture, &badGuyTexture)) {
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
                    case SDLK_DOWN:
                        std::cout << "down key pressed" << std::endl;
                        playerActualPositionY += PLAYER_HEIGHT;
                        break;
                    case SDLK_e:
                        killed = false;
                        createCharacter();
                        badGuyTexture = loadTexture(pathToLoad, renderer);
                        createCharacter::killCharacter();
                        break;
                    case SDLK_r:
                        startBadGuyRunLeftThread();
                        break;
                    case SDLK_UP: //(no break, so it falls through to the next case)
                    case SDLK_w:
                        std::cout << "w key pressed" << std::endl;
                        if (!isJumping) {
                            std::thread jumpThread(jump);
                            jumpThread.detach();
                        }
                        break;
                    case SDLK_RIGHT: //(no break, so it falls through to the next case)
                    case SDLK_d:
                        std::cout << "d key pressed" << std::endl;
                        if (playerPositionX < maxSpeed && !isRunningRight) {
                            std::thread runThread(runRight);
                            runThread.detach();
                        }
                        break;
                    case SDLK_LEFT: //(no break, so it falls through to the next case)
                    case SDLK_a:
                        std::cout << "a key pressed" << std::endl;
                        if (playerPositionX < maxSpeed && !isRunningLeft) {
                            std::thread runThread(runLeft);
                            runThread.detach();
                        }
                        break;
                }
            }
            else if (e.type == SDL_KEYUP) {
                switch (e.key.keysym.sym) {
                    case SDLK_RIGHT: //(no break, so it falls through to the next case)
                    case SDLK_d:
                    std::cout << "d up" << std::endl;
                    if (isRunningRight = true)
                    {
                        isRunningRight = false;
                    }
                    break;
                    case SDLK_LEFT: //(no break, so it falls through to the next case)
                    case SDLK_a:
                    std::cout << "a up" << std::endl;
                    if (isRunningLeft = true)
                    {
                        isRunningLeft = false;
                    }
                    break;
                }
            }
        }
        
        if (chechForCollision() && !killed)
        {
            quit = true;
        }
        else if (chechForCollision() && killed)
        {
            //quit = true;
            SDL_DestroyTexture(badGuyTexture);
        }

        
        refreshScreen(renderer, playerTexture, badGuyTexture);

    }

    // Destroy window and renderer
    SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(badGuyTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_FreeChunk(jumpSound);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}