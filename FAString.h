#pragma once

#include "Helpers/ASMMacros.h"

// A Helper Class For CString
// For safer memory writing
class FAString
{
public:
    void AssignCopy(size_t size, const char* src)
    {
        JMP_THIS(0x55601B);
    }

    static void Assignment(ppmfc::CString& des, const char* src)
    {
        FAString* ptr = (FAString*)&des;
        ptr->AssignCopy(strlen(src) + 1, src);
    }

    FAString(LPCWSTR lpWideCharStr)
    {
        JMP_THIS(0x555FCF);
    }

    FAString(LPCSTR lpCharStr)
    {
        JMP_THIS(0x555F7D);
    }

    void DTOR()
    {
        JMP_THIS(0x555F0F);
    }

    static int Format(char* buffer, const char* format, ...)
    {
        JMP_STD(0x534B56);
    }

    operator ppmfc::CString()
    {
        return real;
    }

    operator const char* ()
    {
        return real;
    }

private:
    ppmfc::CString real;
};