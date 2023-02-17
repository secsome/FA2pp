#pragma once

#include "FA2PP.h"

#include "XCC/mix_file.h"

class CMixFile
{
public:
    static constexpr reference<unsigned int, 0x884030> ArraySize{};
    static constexpr reference<Cmix_file, 0x820538, 2000> Array{};

    static bool __cdecl Close(int nMix) { JMP_STD(0x525790); }
    static int __cdecl Open(const char* pName, int nParentMix) { JMP_STD(0x525470); }
    static bool __cdecl HasFile(const char* pName, int nMix) { JMP_STD(0x525670); }
    static bool __cdecl ExtractFile(const char* pName, const char* pPath, int nMix) { JMP_STD(0x5257D0) }
    static bool __cdecl LoadSHP(const char* pName, int nMix) { JMP_STD(0x525C50); }
};