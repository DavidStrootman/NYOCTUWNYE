//
// Created by david on 11-10-19.
//

#ifndef CHIP8_DISASSEMBLER_H
#define CHIP8_DISASSEMBLER_H

#include "../Memory.h"

//TODO: Use Disassembler and Memory
class Disassembler {
private:
    Memory memory;
    int opCodeToInstruction(uint16_t * buffer);
public:
    explicit Disassembler(Memory memory);
    void disassemble(std::ofstream& outFile);
};


#endif //CHIP8_DISASSEMBLER_H
