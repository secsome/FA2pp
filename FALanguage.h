#pragma once

#include "FA2PP.h"

class FALanguage
{
public:
    ppmfc::CString* GetTranslationItem(ppmfc::CString* name)
    {
        ppmfc::CString tmp;
        return GetTranslationItem(&tmp, name);
    }

private:
    ppmfc::CString* _cdecl GetTranslationItem(ppmfc::CString* a33, ppmfc::CString* name)
    {
        JMP_THIS(0x43DA80);
    }
};