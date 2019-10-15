//
// Created by david on 11-10-19.
//

#ifndef CHIP8_FILEREADER_H
#define CHIP8_FILEREADER_H

#include <iostream>
#include <fstream>
#include "../includes/globals.h"

class FileReader {
private:
public:
    /**
     * A constructor
     * @param inFile The file to load into buffer
     * @param memory Memory to store file in. Passed by reference.
     */
    static void readFileIntoBuffer(std::ifstream &inFile, unsigned char (&buffer)[MEMORY_SIZE]);
};


#endif //CHIP8_FILEREADER_H
