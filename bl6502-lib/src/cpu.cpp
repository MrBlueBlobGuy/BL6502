#include "bl6502/cpu.h"

void CPU::Reset(Mem& mem){
        PC = 0xFFFC;
        C = D = Z = I = B = V = N = 0;
        SP = 0x00FF;
        A = X = Y = 0;

        mem.initialise();
}

BYTE CPU::FetchByte(u32& Cycles, Mem mem){
        BYTE Data = mem[PC];
        PC++;
        Cycles--;
        return Data;
}

WORD CPU::FetchWord(u32& Cycles, Mem mem){
        // 6502 IS LITTLE ENDIAN!!!!!!!!
        // 6502 IS LITTLE ENDIAN!!!!!!!!
        // 6502 IS LITTLE ENDIAN!!!!!!!!
        WORD Data = mem[PC];
        PC++;
        Data |= (mem[PC] << 8);
        PC++;
        Cycles -= 2;
        return Data;
}

BYTE CPU::ReadByte(u32& Cycles, BYTE Address, Mem mem){
        BYTE Data = mem[Address];
        Cycles--;
        return Data;
}

void CPU::LDA_SET_STATUS(){
        Z = (A == 0);
        N = (A & 0b10000000) > 0;
}

void CPU::Execute(u32 Cycles, Mem mem){
        while(Cycles > 0){
            BYTE ins  = FetchByte(Cycles, mem);

            switch (ins)
            {
                case INS_LDA_IM:
                {
                    BYTE value = FetchByte( Cycles, mem );
                    A = value;
                    LDA_SET_STATUS();
                }break;
                case INS_LDA_ZP:
                {
                    BYTE ZeroPageAddress = FetchByte( Cycles, mem );
                    A = ReadByte( Cycles, ZeroPageAddress, mem );
                    LDA_SET_STATUS();
                }break;
                case INS_LDA_ZPX:
                {
                    BYTE ZeroPageAddress = FetchByte( Cycles, mem );
                    ZeroPageAddress += X;
                    Cycles--;
                    A = ReadByte( Cycles, ZeroPageAddress, mem );
                    LDA_SET_STATUS();
                }break;
                case INS_JSR:
                {
                    WORD SubAddr = FetchWord( Cycles, mem );
                    mem.WriteWord( Cycles, PC - 1, SP);
                    SP -= 2;
                    PC = SubAddr;
                    Cycles--;
                }break;
                default:
                {
                    std::cout << "Instruction not handled " << std::hex << (int)ins << std::endl;
                }
            }
        }
    }