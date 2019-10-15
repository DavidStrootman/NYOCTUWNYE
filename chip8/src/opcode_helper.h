//
// Created by David on 11-4-2019.
//
// Thanks Wouter https://github.com/Fusion86
//

#define X ((opcode >> 8) & 0x0F)
#define Y ((opcode >> 4) & 0x0F)
#define N (opcode & 0x0F)
#define NNN (opcode & 0x0FFF)
#define KK (opcode & 0xFF)