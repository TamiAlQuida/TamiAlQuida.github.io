cmake_minimum_required(VERSION 3.10)

# Project name
project(super_mario_adventure)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Source files
set(SOURCES super_mario_adventure.cpp)

# Create the executable
add_executable(super_mario_adventure ${SOURCES})

# Link the SDL2 library
target_link_libraries(super_mario_adventure ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY})