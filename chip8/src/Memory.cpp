//
// Created by david on 13-10-19.
//

#include "memory.h"

Memory::Memory(char * memory, unsigned int size): memory( memory ), size( size / 2 ) {
}

/**
 *
 * @param index
 * @return
 */
uint16_t Memory::getInstruction(unsigned int index) {
    uint16_t instruction;
    if (index <= size) {
        instruction = memory[index] << 8 | memory[index + 1];
    }
//    instruction = stoi(std::to_string(memory[index]) + std::to_string(memory[index + 1]));

    return instruction;
}
