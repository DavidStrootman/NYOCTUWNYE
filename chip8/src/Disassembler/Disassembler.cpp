//
// Created by david on 11-10-19.
//

#include "Disassembler.h"

Disassembler::Disassembler(Memory memory): memory( memory ) {}

void Disassembler::disassemble(std::ofstream& outFile)
{
    //TODO: implement Disassembler::disassemble
    uint16_t opCode;
    int result;

    for (int i = 0; i < this->memory.size; ++i) {

    }
}

int Disassembler::opCodeToInstruction(uint16_t *buffer) {
    //TODO: implement Disassembler::opCodeToInstruction
}