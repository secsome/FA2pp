#pragma once

#include "../FA2Copy.h"
#include "FA2PP.h"
#include "../Macro.h"

class NOVTABLE CFA2Logger
{
public:
    static int WriteLog(const char* pMessage)
    {
        if (FA2Copy::isFA2CLoggerInitialized)
            return WriteLog(firstParam, pMessage);
        return -1;
    }
    static const int firstParam = 6192288;

private:
    static int __cdecl WriteLog(int pConstant, const char* pMessage)
    {
        JMP_THIS(0x4135B0);
    }
};

DEFINE_HOOK(41F8D1, CFA2Logger_Initialized, 5)
{
    FA2Copy::isFA2CLoggerInitialized = TRUE;
    return 0;
}

//DEFINE_HOOK(4135B0, CFA2Logger_WriteLogStart, 5)
//{
//    GET_STACK(UINT32, pCallerAddress, 0x0);
//    GET_STACK(DWORD, pLoggerFirstParam, 0x4);
//    logger::Debug(__FUNCTION__" Caller = 0x%8X Const = %d\n", pCallerAddress, pLoggerFirstParam);
//    return 0;
//}