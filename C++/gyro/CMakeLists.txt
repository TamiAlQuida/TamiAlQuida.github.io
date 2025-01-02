cmake_minimum_required(VERSION 3.13)

# Set the board type
set(PICO_BOARD pico_w)

include(pico_sdk_import.cmake)

project(mpu_6050)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Create an executable for the project
add_executable(mpu_6050
    mpu_6050.cpp
)

# Link the necessary libraries
target_link_libraries(
    mpu_6050 
    pico_stdlib 
    hardware_i2c)

# Enable USB output
pico_enable_stdio_usb(mpu_6050 1)
# Disable UART output
pico_enable_stdio_uart(mpu_6050 0)

# sudo screen /dev/ttyACM0

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(mpu_6050)