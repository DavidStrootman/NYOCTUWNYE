# cmake_minimum_required(VERSION <specify CMake version here>)
project(chip8)

set(CMAKE_CXX_STANDARD 14)

add_executable(chip8 main.cpp src/chip8.cpp src/chip8.h)