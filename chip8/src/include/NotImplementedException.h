//
// Created by David Strootman on 14-4-2019.
//

#ifndef CHIP8_NOTIMPLEMENTEDEXCEPTION_H
#define CHIP8_NOTIMPLEMENTEDEXCEPTION_H

#include <iostream>


class NotImplementedException : public std::logic_error
{
    public:
        NotImplementedException() : std::logic_error("Function not yet implemented") { };
};


#endif //CHIP8_NOTIMPLEMENTEDEXCEPTION_H
