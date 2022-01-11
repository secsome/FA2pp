#pragma once

#include "FA2PP.h"

class CMinimap : public ppmfc::CView
{
protected:
    virtual void OnDraw(ppmfc::CDC* pDC) override
        { JMP_THIS(0x4691C0); }

public:

    void Update()
        { JMP_THIS(0x4D1D60); }
};