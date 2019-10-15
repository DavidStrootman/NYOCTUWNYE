#include "includes/globals.h"

#include "fileReader/FileReader.h"
#include "dumpBuffer.cpp"
#include <SDL.h>
#include "chip8.h"

int main(int argc, char **argv) {
    unsigned char buffer[MEMORY_SIZE];

    std::ifstream rom = std::ifstream("../pong.rom", std::ios::in | std::ios::binary);

    FileReader::readFileIntoBuffer(rom, buffer);

    SDL_Window * screen = nullptr;

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    //TODO: implement front-end
    // Create an application window with the following settings:
//    screen = SDL_CreateWindow(
//            "An SDL2 window",                  // window title
//            SDL_WINDOWPOS_UNDEFINED,           // initial x position
//            SDL_WINDOWPOS_UNDEFINED,           // initial y position
//            64,                               // width, in pixels
//            32,                               // height, in pixels
//            SDL_WINDOW_OPENGL                  // flags - see below
//    );


    chip8 chip8(screen);
    chip8.initialize();
    chip8.loadProgram(buffer, MEMORY_SIZE);
    chip8.run();

    return 0;
}