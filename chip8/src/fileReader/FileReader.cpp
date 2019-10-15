//
// Created by david on 11-10-19.
//

#include <cstring>
#include "FileReader.h"

void FileReader::readFileIntoBuffer(std::ifstream &inFile, unsigned char (&buffer)[MEMORY_SIZE]) {
    // for now allow only one program to be loaded into memory
    // clear memory
    std::memset(buffer, 0, MEMORY_SIZE);

    unsigned char ch;
    unsigned int i = 0;

    while (inFile.good()) {
        // get next char from file
        ch = inFile.get();
        // load new char into buffer
        buffer[i] = ch;
        i++;
    }
}
