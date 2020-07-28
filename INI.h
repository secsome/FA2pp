#pragma once

#include "FA2PP.h"





// INIPair
struct CStringPair
{
    CString Key;
    CString Value;

    __thiscall CStringPair(LPCSTR* pKey, LPCSTR* pValue)
    {
        JMP_THIS(0x407D50);
    }

    CStringPair(LPCSTR* pKey)
    {
        auto lpDefaultValue = reinterpret_cast<LPCSTR>(0x5D4498);
        CStringPair(pKey, &lpDefaultValue);
    }

    __thiscall ~CStringPair()
    {
        JMP_THIS(0x4032E0);
    }
};