#pragma once

#include <WinUser.h>
#include "ppmfc_forward.h"

_PPMFC_BEGIN

_PPMFC_CLASS(CMenu) _PPMFC_INHERIT(CObject)
{
public:

    CMenu() { this->m_hMenu = NULL; }

    // virtual functions
    virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59C850); }

    virtual ~CMenu() override _PPMFC_THISCALL(0x432620);

    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) RX;

    virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) RX;

    // normal functions
    static CMenu* _PPMFC_API FromHandle(HMENU hMenu)
        _PPMFC_STDCALL(0x556E3E);

    BOOL Attach(HMENU hMenu)
        _PPMFC_THISCALL(0x556E71);

    HMENU Detach()
        _PPMFC_THISCALL(0x556E9E);

    static CMenu* _PPMFC_API FromHandlePermanent(HMENU hMenu)
        _PPMFC_STDCALL(0x556E53);

    UINT CheckMenuItem(UINT nIDCheckItem, UINT nCheck)
        { ASSERT(::IsMenu(m_hMenu)); return (UINT)::CheckMenuItem(m_hMenu, nIDCheckItem, nCheck); }

    BOOL CheckMenuRadioItem(UINT nIDFirst, UINT nIDLast, UINT nIDItem, UINT nFlags)
        { return ::CheckMenuRadioItem(m_hMenu, nIDFirst, nIDLast, nIDItem, nFlags); }

    operator HMENU()
        { return this->m_hMenu; }

public:
    HMENU m_hMenu;
};

_PPMFC_END