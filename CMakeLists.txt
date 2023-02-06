cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(BOARD pico-w)


# Initialize the SDK
pico_sdk_init()

project(radio-panel)
add_executable(radio-panel Main.cpp)

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )

target_link_libraries(radio-panel pico_stdlib pico_cyw43_arch_none)

# create map/bin/hex file etc.
pico_add_extra_outputs(radio-panel)