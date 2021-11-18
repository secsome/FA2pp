#pragma once

// The whole class is cursed.
// Just understand that you can call CFA2Logger::Write is enough.
// - secsome 2021/11/18

#include "FA2PP.h"

class CFA2Logger
{
public:
    static void __cdecl Write(const char* pFormat, ...)
    {
        va_list args;
        va_start(args, pFormat);
        char buffer[0x400];
        vsprintf_s(buffer, pFormat, args);
        Log(buffer);
        va_end(pFormat);
    }

private:
    static CFA2Logger* __cdecl WriteLog(CFA2Logger* pFileHandle, const char* pMessage)
    {
        JMP_STD(0x4135B0);
    }

    void Clear_sub_413350(int unknown)
    {
        JMP_THIS(0x413350);
    }

    void Flush()
    {
        JMP_THIS(0x4391C0);
    }

    void sub_439240(int a2, bool a4)
    {
        JMP_THIS(0x439240);
    }

    static void Log(const char* pMessage)
    {
        auto ptr = WriteLog((CFA2Logger*)0x5E7CA0, pMessage);
        ptr->Clear_sub_413350(10);
        ptr->Flush();
        int v3 = 0;
        int v4;
        int*& p = *reinterpret_cast<int**>(0x5E7CA0);
        v4 = p[1];
        if (((unsigned __int8)*(char**)((char*)&p + v4 + 4) & 6) == 0
            && (*(int(__thiscall**)(DWORD))(**(DWORD**)((char*)(0x5E7CC8) + v4) + 44))(*(int*)((char*)(0x5E7CC8)
                + v4)) == -1)
        {
            v3 = 4;
        }
        if (v3)
        {
            CFA2Logger* q = (CFA2Logger*)((char*)&p + p[1]);
            q->sub_439240(
                v3 | *(unsigned int*)((char*)&p + p[1] + 4),
                0);
        }
    }
};

//DEFINE_HOOK(4135B0, CFA2Logger_WriteLogStart, 5)
//{
//    GET_STACK(UINT32, pCallerAddress, 0x0);
//    GET_STACK(DWORD, pLoggerFirstParam, 0x4);
//    logger::Debug(__FUNCTION__" Caller = 0x%8X Const = %d\n", pCallerAddress, pLoggerFirstParam);
//    return 0;
//}