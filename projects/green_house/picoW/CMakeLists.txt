cmake_minimum_required(VERSION 3.12)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Set the board type
set(PICO_BOARD pico_w)

# Use prebuilt pioasm to skip building it from source
add_executable(pioasm IMPORTED GLOBAL)
set_property(TARGET pioasm PROPERTY IMPORTED_LOCATION /usr/local/bin/pioasm)


include(pico_sdk_import.cmake)

set(CMAKE_CXX_STANDARD 17)

project(main)

pico_sdk_init()

# Create an executable for the project
add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    pico_cyw43_arch_lwip_threadsafe_background
    hardware_gpio
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Enable USB output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
# Disable UART output
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# sudo screen /dev/ttyACM0

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})