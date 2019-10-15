//
// Created by david on 11-10-19.
//

#ifndef CHIP8_DUMPBUFFER_CPP
#define CHIP8_DUMPBUFFER_CPP

#include <iostream>
#include <iomanip>

template<typename array_t>
static array_t dumpBuffer(array_t array[], unsigned uSize) {
    for (unsigned int i = 0; i < uSize; ++i) {
        if (i % 8 == 0 && i != 0 && i % 16 != 0) {
            std::cout << " ";
        }
        if (i % 16 == 0 && i != 0) {
            std::cout << std::endl;
        }

        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(array[i]) << " ";
    }
    std::cout << std::endl;
}

#endif //CHIP8_DUMPBUFFER_CPP
