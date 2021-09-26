#pragma once

#include "ppmfc_cwnd.h"

_PPMFC_BEGIN

_PPMFC_CLASS(CTabCtrl) _PPMFC_INHERIT(CWnd)
{
public:
    CTabCtrl() : CWnd()
    {
        *(int*)this = 0x59B1F0;
    }
};

_PPMFC_END