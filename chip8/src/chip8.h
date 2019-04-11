//
// Created by David Strootman on 9-4-2019.
//

#ifndef CHIP8_CHIP8_H
#define CHIP8_CHIP8_H

#include <iostream>

class chip8 {
    private:
        unsigned short pc;
        unsigned short opcode;
        unsigned char V[16];
        unsigned short I;
    public:
        chip8();
        void chip8::initialize();
        void chip8::emulateCycle();


};


#endif //CHIP8_CHIP8_H
