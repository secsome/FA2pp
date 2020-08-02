#pragma once

#include "FA2PP.h"

// INIPair , CsfPair(?)
struct CStringPair
{
    CString Key;
    CString Value;

    __thiscall CStringPair(LPCSTR pKey, LPCSTR pValue)
    {
        Key = pKey;
        Value = pValue;
    }

    CStringPair() {}

    __thiscall ~CStringPair()
    {
        Key.~CString();
        Value.~CString();
    }
};


// Sample from Basic->EndofGame
LPCSTR GetValue(DWORD pFileAddress, LPCSTR lpSection, LPCSTR lpKey)
{
    CString pSection = lpSection;
    CString pKey = lpKey;


    LPCSTR lpResult = "DEBUG Return";
    
    return lpResult;
}