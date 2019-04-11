//
// Created by David Strootman on 9-4-2019.
//

#include "chip8.h"

chip8::chip8()
{
    pc = 0x200; // First 512 bytes are reserved for Chip8
    opcode = 0; // Current opcode
    I = 0; // Index Register
}

void chip8::initialize()
{
    // Clear display
    // Clear stack
    // Clear registers V0-VF
    // Clear memory

    // Load fontset
    for (int i = 0; i < 80; ++i)
        memory[i] = chip8_fontset[i];

    // Reset timers
}
void chip8::emulateCycle()
{
    opcode = memory[pc] << 8 | memory[pc + 1];
    char compReg1 = 0x00;
    char compReg2 = 0x00;
    char compByte = 0x00;

    // Decode opcode
    switch (opcode & 0xF000) {
        case 0x0000:
            switch (opcode & 0x000F) {
                case 0x0000: // Return from a subroutine.
                    break;
                case 0x000E: // CLS
                    break;
                default:
                    std::cout << "Unknown opcode: " << opcode << "\n";
            }
            break;
        case 0x1000: // JP addr
            break;
        case 0x2000: // CALL addr
            break;
        case 0x3000: // SE Vx, byte
            // Shift first half of left byte to first half of right byte and nibble everything left of that half.
            compReg1 = (opcode & 0x0F00) >> 8;
            // nibble left byte
            compByte = opcode & 0x00FF;

            if (compReg1 == compByte) {
                pc += 2;
            }
            break;
        case 0x4000: // SNE Vx, byte
            // Shift selected half of byte to right and nibble rest.
            compReg1 = (opcode & 0x0F00) >> 8;
            // nibble left byte
            compByte = opcode & 0x00FF;

            if (compReg1 != compByte) {
                pc += 2;
            }
            break;
        case 0x5000: // SE Vx, Vy
            // Nibble all but selected half of byte and shift to right.
            compReg1 = (opcode & 0x0F00) >> 8;
            compReg2 = (opcode & 0x00F0) >> 4;

            if (compReg1 == compReg2) {
                pc += 2;
            }

            break;
        case 0x6000: // LD Vx, byte
            break;
        case 0x7000: // ADD Vx, byte
            break;
        case 0x8000: // LD Vx, Vy
            switch (opcode & 0x000F) {
                case 0x0000: // LD Vx, Vy
                    break;
                case 0x0001: // OR Vx, Vy
                    break;
                case 0x0002: // AND Vx, Vy
                    break;
                case 0x0003: // XOR Vx, Vy
                    break;
                case 0x0004: // ADD Vx, Vy
                    break;
                case 0x0005: // SUB Vx, Vy
                    break;
                case 0x0006: // SHR Vx {, Vy}
                    break;
                case 0x0007: // SUBN Vx, Vy
                    break;
                case 0x000E: // SHL Vx {, Vy}
                    break;

                default:
                    std::cout << "Unknown opcode: " << opcode << "\n";
            }
            break;
        case 0x9000: // SNE Vx, Vy
            break;
        case 0xA000: // LD I, addr
            I = opcode & 0x0FFF;

            pc += 2;
            break;
        case 0xB000: // JP V0, addr
            break;
        case 0xC000: // RND Vx, byte
            break;
        case 0xD000: // DRW Vx, Vy, nibble
            break;
        case 0xE000:
            switch (opcode & 0x000F) {
                case 0x000E: // SKP Vx
                    break;
                case 0x0001: // SKNP Vx

                default:
                    std::cout << "Unknown opcode: " << opcode << "\n";
            }
            break;
        case 0xF000:
            switch (opcode & 0x00F0) {
                case 0x0000:
                    switch (opcode & 0x000F) {
                        case 0x0007: // LD Vx, DT
                            break;
                        case 0x000A: // LD Vx, K
                            break;

                        default:
                            std::cout << "Unknown opcode: " << opcode << "\n";
                    }
                case 0x0010:
                    switch (opcode & 0x000F) {
                        case 0x0005: // LD DT, Vx
                            break;
                        case 0x0008: // LD ST, Vx
                            break;
                        case 0x000E: // ADD I, Vx
                            break;

                        default:
                            std::cout << "Unknown opcode: " << opcode << "\n";
                    }
                case 0x0020: // LD F, Vx
                    break;
                case 0x0030: // LD B, Vx
                    break;
                case 0x0050: // LD [I], Vx
                    break;
                case 0x0060: // LD Vx, [I]
                    break;

                default:
                    std::cout << "Unknown opcode: " << opcode << "\n";
            }

        default:
            std::cout << "Unknown opcode: " << opcode << "\n";
    }
}