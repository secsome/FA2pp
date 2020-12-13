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

    FAString(LPCWSTR lpWideCharStr)
    {
        JMP_THIS(0x555FCF);
    }

    static int Format(char* buffer, const char* format, ...)
    {
        JMP_STD(0x534B56);
    }

    operator CString()
    {
        return real;
    }

    operator const char* ()
    {
        return real;
    }

private:
    CString real;
};