#pragma once

#include <WinUser.h>
#include "ppmfc_ccmdtarget.h"

_PPMFC_BEGIN

// forward declarations
class CWnd;
class COleMessageFilter;
class CException;

typedef UINT(__cdecl* AFX_THREADPROC)(LPVOID);

_PPMFC_CLASS(CWinThread) _PPMFC_INHERIT(CCmdTarget)
{
public:

    CWinThread() { JMP_THIS(0x564F59); }

    // virtual functions
    virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59BEF8); }

    virtual ~CWinThread() override _PPMFC_THISCALL(0x566909);

    virtual BOOL InitInstance() R0;

    virtual int Run()
        _PPMFC_THISCALL(0x5568A0);

    virtual BOOL PreTranslateMessage(MSG* pMsg)
        _PPMFC_THISCALL(0x556B02);

    virtual BOOL PumpMessage()
        _PPMFC_THISCALL(0x556D8C);

    virtual BOOL OnIdle(LONG lCount)
        _PPMFC_THISCALL(0x55697C);

    virtual BOOL IsIdleMessage(MSG* pMsg)
        _PPMFC_THISCALL(0x55691F);

    virtual int ExitInstance()
        _PPMFC_THISCALL(0x556978);

    virtual LRESULT ProcessWndProcException(CException* e, const MSG* pMsg)
        _PPMFC_THISCALL(0x556B5F);

    virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg)
        _PPMFC_THISCALL(0x556C27);

    virtual CWnd* GetMainWnd()
        _PPMFC_THISCALL(0x556D71);

    virtual void Delete()
        _PPMFC_THISCALL(0x55688B);

    // normal functions

    BOOL DispatchThreadMessageEx(MSG* msg)
        _PPMFC_THISCALL(0x556A87);

public:
    CWnd* m_pMainWnd;
    CWnd* m_pActiveWnd;
    BOOL m_bAutoDelete;
    HANDLE m_hThread;
    DWORD m_nThreadID;
    MSG m_msgCur;
    LPVOID m_pThreadParams;
    AFX_THREADPROC m_pfnThreadProc;
    void* m_lpfnOleTermOrFreeLib;
    COleMessageFilter* m_pMessageFilter;
    CPoint m_ptCursorLast;
    UINT m_nMsgLast;
};

_PPMFC_END