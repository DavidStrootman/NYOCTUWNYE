//
// Created by David Strootman on 9-4-2019.
//

#ifndef CHIP8_CHIP8_H
#define CHIP8_CHIP8_H

#include <iostream>
#include <string.h>
#include "include/opcode_helper.h"

class chip8 {
    private:

        unsigned char gfx[64 * 32]; // Temporary display
        unsigned short pc; // Program counter (First 512/0x200 bytes are reserved for Chip8)
        unsigned short opcode; // Current opcode

        unsigned char V[16]; // Registers
        unsigned short I; // Index Register

        unsigned short stack[16]; // Stack
        unsigned short sp; // Stack pointer

        unsigned char memory[4096];
    public:
        chip8();
        void chip8::initialize();
        void chip8::emulateCycle();


};


#endif //CHIP8_CHIP8_H
