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

    static int Format(char* buffer, const char* format, ...)
    {
        JMP_STD(0x534B56);
    }

};