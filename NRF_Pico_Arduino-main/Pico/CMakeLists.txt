cmake_minimum_required(VERSION 3.12)

# Set the board type
set(PICO_BOARD pico_w)

include(pico_sdk_import.cmake)

set(CMAKE_CXX_STANDARD 17)

project(NRF_Projects)

pico_sdk_init()

# Function to add a project
function(add_nrf_project NAME)
    add_executable(${NAME}
        ${NAME}/src/main.cpp
        ${NAME}/src/NRF24.cpp
        #${NAME}/src/hm11.h
    )

    target_include_directories(${NAME} PUBLIC
        ${NAME}/inc
    )

    target_link_libraries(${NAME}
        pico_stdlib
        pico_cyw43_arch_none
        hardware_spi
        hardware_uart
    )

    #pico_add_extra_outputs(${NAME})
    pico_add_uf2_output(${NAME})

    # Enable usb output, disable uart output
    pico_enable_stdio_usb(${NAME} 1)
    pico_enable_stdio_uart(${NAME} 0)
endfunction()

# Add the three projects
add_nrf_project(NRF_Receiver)
add_nrf_project(NRF_Transmitter)
add_nrf_project(controller_transmitter)
