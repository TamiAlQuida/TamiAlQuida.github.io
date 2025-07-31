cmake_minimum_required(VERSION 3.12)

# Set the board type
set(PICO_BOARD pico)

include(pico_sdk_import.cmake)

set(CMAKE_CXX_STANDARD 17)

project(i2c_oled_1306)

pico_sdk_init()

# Create an executable for the project
add_executable(${PROJECT_NAME}
    src/i2c_oled_1306.cpp
    src/ssd1306.c
)

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_gpio
    hardware_i2c
)

# Enable USB output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
# Disable UART output
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# sudo screen /dev/ttyACM0

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})