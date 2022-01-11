#pragma once

#include "ppmfc_cwnd.h"

_PPMFC_BEGIN

class CPrintDialog;
class CPreviewView;
class CSplitterWnd;
class COleServerDoc;
typedef DWORD DROPEFFECT;
class COleDataObject;
class CDocument;
class CPrintInfo;

_PPMFC_CLASS(CView) _PPMFC_INHERIT(CWnd)
{
public:
    CView() _PPMFC_THISCALL(0x558E1C);

    // virtual functions
    virtual ~CView() override _PPMFC_THISCALL(0x558E2C);

    virtual BOOL PreCreateWindow(CREATESTRUCT & cs) override
        _PPMFC_THISCALL(0x558E7F);

    virtual CScrollBar* GetScrollBarCtrl(int nBar) const override
        _PPMFC_THISCALL(0x55919A);

    virtual BOOL IsSelected(const CObject * pDocItem) const R0;

    virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE) R0;

    virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE) R0;

    virtual DROPEFFECT OnDragEnter(COleDataObject * pDataObject, DWORD dwKeyState, CPoint point) R0;
    
    virtual DROPEFFECT OnDragOver(COleDataObject * pDataObject, DWORD dwKeyState, CPoint point) R0;
    
    virtual void OnDragLeave() RX;
    
    virtual BOOL OnDrop(COleDataObject * pDataObject, DROPEFFECT dropEffect, CPoint point) R0;

    virtual DROPEFFECT OnDropEx(COleDataObject * pDataObject, DROPEFFECT dropDefault, DROPEFFECT dropList, CPoint point)
        _PPMFC_THISCALL(0x559135);

    virtual DROPEFFECT OnDragScroll(DWORD dwKeyState, CPoint point)
        _PPMFC_THISCALL(0x559128);

    virtual void OnPrepareDC(CDC * pDC, CPrintInfo * pInfo = NULL) RX;

    virtual void OnInitialUpdate()
        _PPMFC_THISCALL(0x559062);

    virtual void OnActivateView(BOOL bActivate, CView * pActivateView, CView * pDeactiveView)
        _PPMFC_THISCALL(0x559094);

    virtual void OnActivateFrame(UINT nState, CFrameWnd * pFrameWnd) RX;

    virtual void OnUpdate(CView * pSender, LPARAM lHint, CObject * pHint)
        _PPMFC_THISCALL(0x559070);

    virtual void OnDraw(CDC * pDC) = 0;

    virtual BOOL OnPreparePrinting(CPrintInfo * pInfo)
        _PPMFC_THISCALL(0x5592E0);

    virtual void OnBeginPrinting(CDC * pDC, CPrintInfo * pInfo) RX;

    virtual void OnPrint(CDC * pDC, CPrintInfo * pInfo)
        _PPMFC_THISCALL(0x559080);

    virtual void OnEndPrinting(CDC * pDC, CPrintInfo * pInfo) RX;

    virtual void OnEndPrintPreview(CDC * pDC, CPrintInfo * pInfo, POINT point, CPreviewView * pView)
        _PPMFC_THISCALL(0x5592E9);

public:
    CDocument* m_pDocument;
};

_PPMFC_END