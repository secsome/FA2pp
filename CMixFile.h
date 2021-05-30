#pragma once

#include "FA2PP.h"

#include "XCC/mix_file.h"

class CMixFile
{
public:
    static bool __cdecl HasFile(const char* pName, Cmix_file* pmix) { JMP_STD(0x525670); }
    static bool __cdecl ExtractFile(const char* pName, const char* pPath, Cmix_file* pMix) { JMP_STD(0x5257D0) }

};