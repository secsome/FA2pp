#pragma once

#include "FA2PP.h"

class CMinimap : public FA2CView
{
protected:
    virtual void OnDraw(CDC* pDC) override
    {
        JMP_THIS(0x4691C0);
    }

public:
    BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, 
        DWORD dwStyle, const RECT* rect, CWnd* pParentWnd, UINT nID, LPVOID lpParam = nullptr)
    {
        JMP_THIS(0x552C7E);
    }

    void Update()
    {
        JMP_THIS(0x4D1D60);
    }
};