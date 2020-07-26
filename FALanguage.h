#pragma once

#include "FA2PP.h"

class FALanguage
{
public:
    CString* GetTranslationItem(CString* name)
    {
        CString tmp;
        return GetTranslationItem(&tmp, name);
    }

private:
    CString* _cdecl GetTranslationItem(CString* a33, CString* name)
    {
        JMP_THIS(0x43DA80);
    }
};