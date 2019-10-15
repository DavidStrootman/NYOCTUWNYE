//
// Created by david on 13-10-19.
//

#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H

#include <cstdint>
#include <string>
#include "includes/globals.h"

struct Memory {
public:
    unsigned int size;
    uint16_t memory[MEMORY_SIZE / 2];

    /**
     * A constructor
     * Stores values as uint16_t, so double bytes
     * @param memory Initial memory
     * @param size Memory Size in bytes
     */
    explicit Memory(const unsigned char * memory, unsigned int size);

    uint16_t getOpcode(unsigned int index);
private:
};


#endif //CHIP8_MEMORY_H
