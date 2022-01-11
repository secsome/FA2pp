#pragma once

#include "ppmfc_cwnd.h"

_PPMFC_BEGIN

_PPMFC_CLASS(CStatic) _PPMFC_INHERIT(CWnd)
{
public:
    CStatic() : CWnd() {}

    // virtual functions
    virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59B368); }

    virtual ~CStatic() override _PPMFC_THISCALL(0x5613B5);
};

_PPMFC_END