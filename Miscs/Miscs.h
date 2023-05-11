#pragma once

#include "../FA2PP.h"

namespace Miscs {
    static ppmfc::CString* __cdecl ParseHouseName(ppmfc::CString* pRet, ppmfc::CString src, bool bRealToUIName) JMP_STD(0x43C3C0);
    static ppmfc::CString ParseHouseName(const ppmfc::CString& src, bool bRealToUIName) 
    { 
        ppmfc::CString buffer; 
        ParseHouseName(&buffer, src, bRealToUIName);
        return buffer;
    }
    static ppmfc::CString ParseHouseName(ppmfc::CString&& src, bool bRealToUIName)
    {
        ppmfc::CString buffer;
        ParseHouseName(&buffer, src, bRealToUIName);
        return buffer;
    }
    static COLORREF __declspec(naked) __stdcall GetColorRef(const char* pHouse, const char* pColor = nullptr)
    {
        JMP(0x468760);
    }
}