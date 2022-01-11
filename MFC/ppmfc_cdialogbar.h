#pragma once

#include "ppmfc_ccontrolbar.h"

_PPMFC_BEGIN

_PPMFC_CLASS(CDialogBar) _PPMFC_INHERIT(CControlBar)
{
public:
    CDialogBar() _PPMFC_THISCALL(0x55BB45);

    // virtual functions
    virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59C248); }

    virtual ~CDialogBar () override { JMP_THIS(0x55BB81); }
    
    virtual BOOL SetOccDialogInfo(_AFX_OCC_DIALOG_INFO* pOccDialogInfo) override
        _PPMFC_THISCALL(0x55BD47);

    virtual CSize CalcFixedLayout(BOOL bStretch, BOOL bHorz)
        _PPMFC_THISCALL(0x55BCB2);

    virtual void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler)
        _PPMFC_THISCALL(0x55BCF6);

    // normal functions
    LRESULT HandleInitDialog(WPARAM, LPARAM)
        _PPMFC_THISCALL(0x55BD0C);

    BOOL Create(CWnd* pParentWnd, LPCTSTR lpszTemplateName, UINT nStyle, UINT nID)
        _PPMFC_THISCALL(0x55BBB9);

public:
    CSize m_sizeDefault;
    _AFX_OCC_DIALOG_INFO* m_pOccDialogInfo;
    LPCTSTR m_lpszTemplateName;
};

_PPMFC_END