#pragma once

#include "FA2PP.h"

class GlobalVars
{
public:

    static const char* ExePath() // Where FA2.exe locates
    {
        return reinterpret_cast<char*>(0x72A738);
    }

    static const char* MapPath() // Where current map locates 
    {
        return reinterpret_cast<char*>(0x72A530);
    }

    static const char* FilePath() // Where mix files locates
    {
        return reinterpret_cast<char*>(0x72A634);
    }

    
    class INIFiles
    {
#include "INI.h"
    public:
        static DWORD Rules() // rulesmd.ini / rules.ini
        {
            return 0x7EDDDC;
        }

        static DWORD FAData() // FAData.ini
        {
            return 0x7ED61C;
        }

    };

};