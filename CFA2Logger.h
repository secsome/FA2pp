#pragma once

// Don't use this one for now...

#include "FA2PP.h"

class CFA2Logger
{
public:
    static bool isInitialized;

/*
    static int WriteLog(const char* pFormat, ...)
    {
        va_list args;
        va_start(args, pFormat);
        char buffer[1024];
        vsprintf_s(buffer, 1024, pFormat, args);
        va_end(pFormat);
        return SafeWriteLog(buffer);
    }
*/

private:
    static int __cdecl WriteLog(int pConstant, const char* pMessage)
    {
        JMP_THIS(0x4135B0);
    }

    static int SafeWriteLog(const char* pMessage)
    {
        if (isInitialized)
            return WriteLog(firstParam, pMessage);
        return -1;
    }

    static const int firstParam = 6192288;
};

bool CFA2Logger::isInitialized = false;

DEFINE_HOOK(41F8D1, CFA2Logger_Initialized, 5)
{
    CFA2Logger::isInitialized = true;
    return 0;
}

//DEFINE_HOOK(4135B0, CFA2Logger_WriteLogStart, 5)
//{
//    GET_STACK(UINT32, pCallerAddress, 0x0);
//    GET_STACK(DWORD, pLoggerFirstParam, 0x4);
//    logger::Debug(__FUNCTION__" Caller = 0x%8X Const = %d\n", pCallerAddress, pLoggerFirstParam);
//    return 0;
//}