#pragma once

#include "FA2PP.h"

class GlobalVar
{
public:
    static CString ExePath() // Where FA2.exe locates
    {
        return reinterpret_cast<char*>(0x72A738);
    }

    static CString RegPath() // Where Reg sets 
    {
        return reinterpret_cast<char*>(0x72A530);
    }

    static CString FilePath() // Where setting sets
    {
        return reinterpret_cast<char*>(0x72A634);
    }

};