//
// Created by david on 13-10-19.
//

#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H

#include <cstdint>
#include <string>

struct Memory {
public:
    unsigned int size;
    /**
     * A constructor
     * Stores values as uint16_t, so double bytes
     * @param memory Initial memory
     * @param size Memory Size in bytes
     */
    explicit Memory(char * memory, unsigned int size);

    uint16_t getInstruction(unsigned int index);
private:
    char * memory;
};


#endif //CHIP8_MEMORY_H
