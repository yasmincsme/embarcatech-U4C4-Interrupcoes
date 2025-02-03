cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(embarcatech-U4C4-Interrupcoes C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(embarcatech-U4C4-Interrupcoes embarcatech-U4C4-Interrupcoes.c matrix.c)

# Set program name and version
pico_set_program_name(embarcatech-U4C4-Interrupcoes "embarcatech-U4C4-Interrupcoes")
pico_set_program_version(embarcatech-U4C4-Interrupcoes "0.1")

# Enable stdio over UART and USB
pico_enable_stdio_uart(embarcatech-U4C4-Interrupcoes 1)
pico_enable_stdio_usb(embarcatech-U4C4-Interrupcoes 1)

# Generate PIO header from the .pio file
file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)
pico_generate_pio_header(embarcatech-U4C4-Interrupcoes ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

# Add the standard library and hardware libraries to the build
target_link_libraries(embarcatech-U4C4-Interrupcoes
    pico_stdlib
    hardware_pio
    pico_multicore
)

# Add the standard include files and generated PIO header directory to the build
target_include_directories(embarcatech-U4C4-Interrupcoes PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/generated
)

target_include_directories(embarcatech-U4C4-Interrupcoes PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries (if needed)
# target_link_libraries(embarcatech-U4C4-Interrupcoes ...)

# Add extra outputs (e.g., .uf2, .hex)
pico_add_extra_outputs(embarcatech-U4C4-Interrupcoes)
