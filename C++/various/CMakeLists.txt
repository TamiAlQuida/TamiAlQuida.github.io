cmake_minimum_required(VERSION 3.10)

# Project name
project(MySDLProgram)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Source files
set(SOURCES test_2.cpp)

# Create the executable
add_executable(my_sdl_program ${SOURCES})

# Link the SDL2 library
target_link_libraries(my_sdl_program ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY})