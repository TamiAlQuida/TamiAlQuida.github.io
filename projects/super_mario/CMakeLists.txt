cmake_minimum_required(VERSION 3.10)

# Project name
project(super_mario_adventure)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Manually set SDL2_mixer variables
set(SDL2_MIXER_INCLUDE_DIR /usr/lib/x86_64-linux-gnu/libSDL2.so)  # Change this to your actual include path
set(SDL2_MIXER_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so)  # Change this to your actual library path, needed because ${SDL2_MIXER_LIBRARY} wont be found by cmake
set(SDL2_IMAGE_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2_image.so)  # Change this to your actual library path, needed because ${SDL2_MIXER_LIBRARY} wont be found by cmake

# Source files
set(SOURCES super_mario_adventure.cpp)

# Create the executable
add_executable(super_mario_adventure ${SOURCES})

# Link the SDL2 and SDL2_mixer libraries
target_link_libraries(super_mario_adventure ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY} /usr/lib/x86_64-linux-gnu/libX11.so)
