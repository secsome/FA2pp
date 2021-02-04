#pragma once

#include "ppmfc_forward.h"

_PPMFC_BEGIN

// forward declarations
class AFX_CMDHANDLERINFO;
class AFX_DISPMAP;
class AFX_EVENTSINKMAP;
class AFX_INTERFACEMAP;
class AFX_CONNECTIONMAP;
class AFX_OLECMDMAP;

_PPMFC_CLASS(CCmdTarget) _PPMFC_INHERIT(CObject)
{
public:
    CCmdTarget() _PPMFC_THISCALL(0x555771);
    ~CCmdTarget() _PPMFC_THISCALL(0x55578B);

    virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
        AFX_CMDHANDLERINFO * pHandlerInfo)
        _PPMFC_THISCALL(0x5558BD);

    virtual HRESULT GetTypeLib(LCID lcid, LPTYPELIB * ppTypeLib)
        _PPMFC_THISCALL(0x5559D2);

    static void BeginWaitCursor()
        _PPMFC_STDCALL(0x5559DA);

    static void EndWaitCursor()
        _PPMFC_STDCALL(0x5559EF);

    virtual const AFX_DISPMAP* GetDispatchMap() const
        _PPMFC_STDCALL(0x555A0A);

    virtual const AFX_EVENTSINKMAP* GetEventSinkMap() const
        _PPMFC_STDCALL(0x555A10);

    virtual const AFX_INTERFACEMAP* GetInterfaceMap() const
        _PPMFC_STDCALL(0x555A16);

    virtual void OnFinalRelease()
        _PPMFC_THISCALL(0x555A1C);

    virtual const AFX_CONNECTIONMAP* GetConnectionMap() const
        _PPMFC_STDCALL(0x555A52);

    virtual const AFX_OLECMDMAP* GetCommandMap()
        _PPMFC_STDCALL(0x555A58);

public:
    int m_dwRef;
    LPUNKNOWN m_pOuterUnknown;
    DWORD m_xInnerUnknown;
    XDispatch m_xDispatch;
    BOOL m_bResultExpected;
    XConnPtContainer m_xConnPtContainer;
};

_PPMFC_END