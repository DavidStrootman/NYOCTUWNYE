//
// Created by David Strootman on 9-4-2019.
//

#ifndef CHIP8_CHIP8_H
#define CHIP8_CHIP8_H

#include <iostream>
#include <string.h>

#include "opcode_helper.h"
#include "NotImplementedException.h"

class chip8 {
    private:
        unsigned char gfx[64 * 32]; // Temporary display
        unsigned short pc; // Program counter (First 512/0x200 bytes are reserved for Chip8)
        unsigned short opcode; // Current opcode

        unsigned char V[16]; // Registers
        unsigned short I; // Index Register

        unsigned short stack[16] = {}; // Stack
        unsigned short sp; // Stack pointer

        unsigned char memory[4096] = {};


        unsigned char delay_timer;
        unsigned char sound_timer;

        unsigned char chip8_fontset[80] =
        {
            0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
            0x20, 0x60, 0x20, 0x20, 0x70, // 1
            0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
            0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
            0x90, 0x90, 0xF0, 0x10, 0x10, // 4
            0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
            0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
            0xF0, 0x10, 0x20, 0x40, 0x40, // 7
            0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
            0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
            0xF0, 0x90, 0xF0, 0x90, 0x90, // A
            0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
            0xF0, 0x80, 0x80, 0x80, 0xF0, // C
            0xE0, 0x90, 0x90, 0x90, 0xE0, // D
            0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
            0xF0, 0x80, 0xF0, 0x80, 0x80  // F
        };

        void timer_loop();
    public:
        bool draw_flag;

        chip8();

        void initialize();
        void emulateCycle();


};


#endif //CHIP8_CHIP8_H
