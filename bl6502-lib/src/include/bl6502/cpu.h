#pragma once

typedef unsigned char BYTE;
typedef unsigned short WORD;

typedef unsigned int u32;

#include "memory.h"
#include <iostream>


struct CPU{

    WORD PC;                            // Program Counter
    WORD SP;                            // Stack Pointer

    BYTE A, X, Y;                       // Registers
                                        /*
                                            A: Accumulator
                                            X: Index Register X
                                            Y: Index Register Y
                                        */

    BYTE C : 1;                         // Status Register
    BYTE Z : 1;                         // Status Register
    BYTE I : 1;                         // Status Register
    BYTE D : 1;                         // Status Register
    BYTE B : 1;                         // Status Register
    BYTE V : 1;                         // Status Register
    BYTE N : 1;                         // Status Register

    void Reset(Mem& mem);
    BYTE FetchByte(u32& Cycles, Mem mem);


    // OPCODES
    constexpr static BYTE 
        INS_LDA_IM = 0xA9,
        INS_LDA_ZP = 0xA5,
        INS_LDA_ZPX = 0xB5,
        INS_JSR = 0x20;


    WORD FetchWord(u32& Cycles, Mem mem);

    BYTE ReadByte(u32& Cycles, BYTE Address, Mem mem);

    void LDA_SET_STATUS();

    void Execute(u32 Cycles, Mem mem);
};