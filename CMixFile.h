#pragma once

#include "FA2PP.h"

class CMixFile
{
private:
    struct CMixQueryHelper;

public:
    static bool FindAndCopyTo(const char* pWantName, const char* pCopyToWhere, 
        DWORD PtrAddr = 0x13ACBBC, DWORD PtrResult = 0)
    {
        CMixQueryHelper* pQueryHelper = reinterpret_cast<CMixQueryHelper*>(PtrAddr);
        char* pResult = reinterpret_cast<char*>(PtrResult);
        UINT nFlag = pQueryHelper->QueryFlag(pWantName, pResult);
        if (!nFlag)
            return false;
        return FindAndCopyTo(pWantName, pCopyToWhere, nFlag);
    }

private:
    struct CMixQueryHelper {
        UINT QueryFlag(CString CSFName, char* resultPtr)
        {
            JMP_THIS(0x48A650);
        }
    };

    static bool __cdecl FindAndCopyTo(const char* pWantName, const char* pCopyToWhere, UINT nFlag)
    {
        JMP_STD(0x5257D0);
    }


};