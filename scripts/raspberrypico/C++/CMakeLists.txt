set(PROJECT blink) #change name to whatever you C++ file is called 

# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

set(PICO_BOARD pico_w)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of project and C/C++   standards
project(${PROJECT} C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

# Tell CMake where to find the executable source file
add_executable(${PROJECT} ${PROJECT}.cpp)

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT} 
    pico_stdlib 
    pico_cyw43_arch_none
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT})

# Enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT} 1)
pico_enable_stdio_uart(${PROJECT} 0)