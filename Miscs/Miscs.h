#pragma once

#include "../FA2PP.h"

namespace Miscs {
    ppmfc::CString* __cdecl ParseHouseName(ppmfc::CString* pRet, ppmfc::CString src, bool bRealToUIName) JMP_STD(0x43C3C0);
    ppmfc::CString ParseHouseName(const ppmfc::CString& src, bool bRealToUIName) 
    { 
        ppmfc::CString buffer; 
        ParseHouseName(&buffer, src, bRealToUIName);
        return buffer;
    }
    ppmfc::CString ParseHouseName(ppmfc::CString&& src, bool bRealToUIName)
    {
        ppmfc::CString buffer;
        ParseHouseName(&buffer, src, bRealToUIName);
        return buffer;
    }
}