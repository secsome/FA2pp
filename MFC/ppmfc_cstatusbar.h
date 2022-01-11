#pragma once

#include "ppmfc_ccontrolbar.h"

_PPMFC_BEGIN

_PPMFC_CLASS(CStatusBar) _PPMFC_INHERIT(CControlBar)
{
public:
    CStatusBar() _PPMFC_THISCALL(0x5658BD);

    // virtual functions
    virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59D5E0); }

    virtual ~CStatusBar() override { JMP_THIS(0x565916); }

    virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override
        _PPMFC_STDCALL(0x5659C1);

    virtual BOOL OnChildNotify(UINT message, WPARAM, LPARAM, LRESULT*) override
        _PPMFC_THISCALL(0x55F997);

    virtual CSize CalcFixedLayout(BOOL bStretch, BOOL bHorz) override
        _PPMFC_THISCALL(0x55F84D);

    virtual void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler) override
        _PPMFC_THISCALL(0x55FB43);

    virtual void OnBarStyleChange(DWORD dwOldStyle, DWORD dwNewStyle) override
        _PPMFC_THISCALL(0x55F96C);

    virtual void DrawItem(LPDRAWITEMSTRUCT) RX;

    // normal functions
    void SetText(LPCSTR lpszText, int nPane = NULL, int nType = NULL)
        _PPMFC_THISCALL(0x476310);

    int CommandToIndex(UINT nIDFind) const
        _PPMFC_THISCALL(0x55F705);

    UINT GetPaneStyle(int nIndex) const
        _PPMFC_THISCALL(0x55F72D);

    void SetPaneStyle(int nIndex, UINT nStyle)
        _PPMFC_THISCALL(0x55F73E);

    BOOL SetPaneText(int nIndex, LPCTSTR lpszNewText, BOOL bUpdate = TRUE)
        _PPMFC_THISCALL(0x55F790);

    UINT OnNcHitTest(CPoint)
        _PPMFC_THISCALL(0x55F916);

    void OnNcCalcSize(BOOL, NCCALCSIZE_PARAMS*)
        _PPMFC_THISCALL(0x55F92A);

    void OnPaint()
        _PPMFC_THISCALL(0x55F9C5);

    void OnSize(UINT nType, int cx, int cy)
        _PPMFC_THISCALL(0x55F9DA);

    LRESULT OnSetText(WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x55FA11);

    LRESULT OnGetText(WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x55FA3D);

    LRESULT OnGetTextLength(WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x55FA91);

    LRESULT OnSetMinHeight(WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x55FAB5);

    BOOL CreateEx(
        CWnd* pParentWnd,
        DWORD dwCtrlStyle = 0,
        DWORD dwStyle = WS_CHILD | WS_VISIBLE | 0x8200, // CBRS_BOTTOM
        UINT nID = 0xE801 ) //AFX_IDW_STATUS_BAR
    _PPMFC_THISCALL(0x565951);

    BOOL AllocElements(int nElements, int cbElement)
        _PPMFC_THISCALL(0x5659F0);

    void CalcInsideRect(CRect& rect, BOOL bHorz) const
        _PPMFC_THISCALL(0x565A54);

    void UpdateAllPanes(BOOL bUpdateRects, BOOL bUpdateText)
        _PPMFC_THISCALL(0x565AC4);

public:
    int m_nMinHeight;
};

_PPMFC_END