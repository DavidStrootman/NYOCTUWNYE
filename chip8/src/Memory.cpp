//
// Created by david on 13-10-19.
//

#include <cstring>
#include <iostream>
#include "Memory.h"

Memory::Memory(const unsigned char * memory, unsigned int size): size( size / 2 ) {
    // Zero-initialize memory member
    std::memset(this->memory, 0, this->size);

    // Shift two chars into one uint16_t
    unsigned int j = 0;
    for (unsigned int i = 0; i < this->size; ++i) {
        this->memory[i] = memory[j] << 8 | memory[j + 1];
        j += 2;
    }
}

/**
 * Get instruction from index
 * @param index The index of the instruction to return
 * @return uint16_t instruction
 */
uint16_t Memory::getOpcode(unsigned int index) {
    uint16_t instruction = 0;
//    instruction = stoi(std::to_string(memory[index]) + std::to_string(memory[index + 1]));

    return instruction;
}
