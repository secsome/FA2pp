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
struct AFX_MSGMAP;
class CPtrArray;
class CTypeLibCache;

_PPMFC_CLASS(CCmdTarget) _PPMFC_INHERIT(CObject)
{
public:

    CCmdTarget() _PPMFC_THISCALL(0x555771);

    // virtual functions
    virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59AD08); }

    virtual ~CCmdTarget() override _PPMFC_THISCALL(0x55578B);

    virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO * pHandlerInfo)
        _PPMFC_THISCALL(0x5558BD);

    virtual void OnFinalRelease()
        _PPMFC_THISCALL(0x555A1C);

    virtual BOOL IsInvokeAllowed(DISPID dispid) R0;

    virtual BOOL GetDispatchIID(IID* pIID) R0;

    virtual UINT GetTypeInfoCount() R0;

    virtual CTypeLibCache* GetTypeLibCache() R0;

    virtual HRESULT GetTypeLib(LCID lcid, LPTYPELIB* ppTypeLib)
        _PPMFC_THISCALL(0x5559D2);

    virtual const AFX_MSGMAP* GetMessageMap() const R0;

    virtual const AFX_OLECMDMAP* GetCommandMap()
        _PPMFC_STDCALL(0x555A58);

    virtual const AFX_DISPMAP* GetDispatchMap() const
        _PPMFC_STDCALL(0x555A0A);

    virtual const AFX_CONNECTIONMAP* GetConnectionMap() const
        _PPMFC_STDCALL(0x555A52);

    virtual const AFX_INTERFACEMAP* GetInterfaceMap() const
        _PPMFC_STDCALL(0x555A16);

    virtual const AFX_EVENTSINKMAP* GetEventSinkMap() const
        _PPMFC_STDCALL(0x555A10);

    virtual BOOL OnCreateAggregates() R0;

    virtual LPUNKNOWN GetInterfaceHook(const void*) R0;

    virtual BOOL GetExtraConnectionPoints(CPtrArray* pConnPoints) R0;

    virtual LPCONNECTIONPOINT GetConnectionHook(const IID& iid) R0;

    // normal functions
    static void BeginWaitCursor()
        _PPMFC_STDCALL(0x5559DA);

    static void EndWaitCursor()
        _PPMFC_STDCALL(0x5559EF);

public:
    int m_dwRef;
    LPUNKNOWN m_pOuterUnknown;
    DWORD m_xInnerUnknown;
    XDispatch m_xDispatch;
    BOOL m_bResultExpected;
    XConnPtContainer m_xConnPtContainer;
};

typedef void (CCmdTarget::* AFX_PMSG)(void);

_PPMFC_STRUCT(AFX_MSGMAP_ENTRY)
{
    UINT nMessage;   // windows message
    UINT nCode;      // control code or WM_NOTIFY code
    UINT nID;        // control ID (or 0 for windows messages)
    UINT nLastID;    // used for entries specifying a range of control id's
    UINT nSig;       // signature type (action) or pointer to message #
    AFX_PMSG pfn;    // routine to call (or special value)
};

_PPMFC_STRUCT(AFX_MSGMAP)
{
    const AFX_MSGMAP* pBaseMap;
    const AFX_MSGMAP_ENTRY* lpEntries;
};

_PPMFC_END