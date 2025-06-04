cmake_minimum_required(VERSION 3.12)

# Set the board type
set(PICO_BOARD pico_w)

include(pico_sdk_import.cmake)

set(CMAKE_CXX_STANDARD 17)

project(NRF_cpp)

pico_sdk_init()
 
add_executable(NRF_Receiver
src/main.cpp
src/NRF24.cpp
#src/hm11.h
)

target_include_directories(NRF_Receiver PUBLIC
inc
)

target_link_libraries(NRF_Receiver
pico_stdlib
pico_cyw43_arch_none
hardware_spi
hardware_uart
)

pico_add_extra_outputs(NRF_Receiver)

# Enable usb output, disable uart output
pico_enable_stdio_usb(NRF_Receiver 1)
pico_enable_stdio_uart(NRF_Receiver 0)

