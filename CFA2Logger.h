#pragma once

// Don't use this one for now...

#include "FA2PP.h"

class CFA2Logger
{
public:
    /*static void WriteLog(const char* pMessage)
    {
        
    }*/

    static void* __cdecl WriteLog(void* pFileHandle, const char* pMessage)
    {
        JMP_STD(0x4135B0);
    }

    void Clear_sub_413350()
    {
        JMP_THIS(0x413350);
    }

    void Flush()
    {
        JMP_THIS(0x4391C0);
    }

private:
    static const void* FileHandle = 0x5E7CA0; // basic_ios*
};

//DEFINE_HOOK(4135B0, CFA2Logger_WriteLogStart, 5)
//{
//    GET_STACK(UINT32, pCallerAddress, 0x0);
//    GET_STACK(DWORD, pLoggerFirstParam, 0x4);
//    logger::Debug(__FUNCTION__" Caller = 0x%8X Const = %d\n", pCallerAddress, pLoggerFirstParam);
//    return 0;
//}