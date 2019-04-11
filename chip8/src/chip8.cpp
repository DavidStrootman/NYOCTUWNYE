//
// Created by David Strootman on 9-4-2019.
//
// Most of the comments in this file come from Cowgod's Chip-8 Technical reference
//

#include "chip8.h"

chip8::chip8() : gfx(), V(), stack(), memory()
{
    pc = 0x200; // Program counter (First 512/0x200 bytes are reserved for Chip8)
    opcode = 0; // Current opcode

    I = 0; // Index Register
    sp = 0; // Stack pointer
}

void chip8::initialize()
{
    // TODO: Clear display
    // TODO: Clear stack
    // TODO: Clear registers V0-VF
    // TODO: Clear memory

    // TODO: Load fontset
    for (int i = 0; i < 80; ++i)
        memory[i] = chip8_fontset[i];

    // TODO: Reset timers
}
void chip8::emulateCycle()
{
    opcode = memory[pc] << 8 | memory[pc + 1];
    char reg1 = 0x00;
    char reg2 = 0x00;
    char byte1 = 0x00;

    // Decode opcode
    switch (opcode & 0xF000) {
        case 0x0000:
            switch (opcode & 0x000F) {
                case 0x0000:
                    /*
                     * 00E0 - CLS
                     * Clear the display.
                     */
                    memset(gfx, 0, sizeof(gfx));
                    break;

                case 0x000E:

                    /*
                     * 00EE - RET
                     * Return from a subroutine.
                     *
                     * The interpreter sets the program counter to the address at the top of the stack, then subtracts 1 from the stack pointer.
                     */
                    pc = stack[sp--] + 1;
                    break;

                default:
                    std::cout << "Unknown opcode: " << opcode << "\n";
            }
            break;

        case 0x1000:
            /*
             * 1nnn - JP addr
             * Jump to location nnn.
             * The interpreter sets the program counter to nnn.
             */
            pc = NNN;
            break;

        case 0x2000:
            /*
             * 2nnn - CALL addr
             * Call subroutine at nnn.
             *
             * The interpreter increments the stack pointer, then puts the current PC on the top of the stack. The PC is then set to nnn.
             */
            stack[sp] = pc;
            ++sp;
            pc = NNN;
            break;

        case 0x3000:
            /*
             * 3xkk - SE Vx, byte
             * Skip next instruction if Vx = kk.
             *
             * The interpreter compares register Vx to kk, and if they are equal, increments the program counter by 2.
             */
            reg1 = (opcode & 0x0F00) >> 8;
            byte1 = KK;

            if (reg1 == byte1) {
                pc += 2;
            }
            pc += 2;
            break;

        case 0x4000:
            /*
             * 4xkk - SNE Vx, byte
             * Skip next instruction if Vx != kk.
             *
             * The interpreter compares register Vx to kk, and if they are not equal, increments the program counter by 2.
             */
            reg1 = (opcode & 0x0F00) >> 8;
            byte1 = opcode & 0x00FF;

            if (reg1 != byte1) {
                pc += 2;
            }
            pc += 2;
            break;

        case 0x5000:
            /*
             * 5xy0 - SE Vx, Vy
             * Skip next instruction if Vx = Vy.
             *
             * The interpreter compares register Vx to register Vy, and if they are equal, increments the program counter by 2.
             */

            if (X == Y) {
                pc += 2;
            }
            pc += 2;
            break;

        case 0x6000:
            /*
             * 6xkk - LD Vx, byte
             * Set Vx = kk.
             *
             * The interpreter puts the value kk into register Vx.
             */
            reg1 = (opcode & 0x0F00) >> 2;
            V[reg1] = opcode & 0x00FF;
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