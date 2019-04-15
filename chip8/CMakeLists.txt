# cmake_minimum_required(VERSION <specify CMake version here>)
project(chip8)

set(CMAKE_CXX_STANDARD 14)

add_executable(chip8 src/main.cpp src/chip8.cpp src/include/chip8.h src/include/opcode_helper.h src/include/NotImplementedException.h src/Timer.cpp src/include/Timer.h)