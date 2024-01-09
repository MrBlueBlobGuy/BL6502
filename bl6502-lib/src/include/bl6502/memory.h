#pragma once

typedef unsigned int u32;
typedef unsigned char BYTE;
typedef unsigned short WORD;


struct Mem{
    constexpr static u32 MAX_MEM = 1024 * 64;
    BYTE Data[MAX_MEM];

    void initialise();
    BYTE operator[](u32 Address) const;
    BYTE& operator[](u32 Address);
    void WriteWord(u32& cycles, WORD Data, u32 Address);
};

