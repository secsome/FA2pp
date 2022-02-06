#pragma once

#include "FA2PP.h"

#include "XCC/mix_file.h"

class CMixFile
{
public:
    // I'm not sure about its exact size now...
    static constexpr reference<Cmix_file, 0x8204F0, 2> Array{}; 
    // All loaded mix files!
    // The index 0 is reversed for special usage, so in most ID places, the real array pos is ID - 1

    static int __cdecl Open(const char* pName, int nParentMix) { JMP_STD(0x525470); }
    static bool __cdecl HasFile(const char* pName, int nMix) { JMP_STD(0x525670); }
    static bool __cdecl ExtractFile(const char* pName, const char* pPath, int nMix) { JMP_STD(0x5257D0) }
    static bool __cdecl LoadSHP(const char* pName, int nMix) { JMP_STD(0x525C50); }
};