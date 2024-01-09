#include "bl6502/memory.h"

BYTE& Mem::operator[](u32 Address)
{
    return Data[Address];
}

BYTE Mem::operator[](u32 Address) const
{
        return Data[Address];
}

void Mem::initialise(){
    for(u32 i = 0; i < MAX_MEM; i++){
        Data[i] = 0;
    }
}

void Mem::WriteWord(u32& cycles , WORD Value, u32 Address){
    // 6502 IS LITTLE ENDIAN!!!!!!!!
    // 6502 IS LITTLE ENDIAN!!!!!!!!
    // 6502 IS LITTLE ENDIAN!!!!!!!!
    Data[Address] = Value & 0xFF;
    Data[Address + 1] = (Value >> 8);
    cycles -= 2;
}