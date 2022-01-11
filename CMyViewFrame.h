#pragma once

#include "FA2PP.h"

#include "CMinimap.h"

class CIsoView;
class CTileSetBrowserFrame;

class CViewObjects : public CTreeCtrl
{
public:
    void Update() { JMP_THIS(0x51CD20); }
};

class CRightFrame : public ppmfc::CFrameWnd
{
public:
    static constexpr reference<ppmfc::CRuntimeClass, 0x595A88> RuntimeClass{};

    virtual ppmfc::CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<ppmfc::CRuntimeClass*>(0x595A88); }

    virtual const ppmfc::AFX_MSGMAP* GetMessageMap() const override
        { JMP_THIS(0x4D3E40); }

    virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override
        { JMP_THIS(0x4D3F50); }

    virtual void RecalcLayout(BOOL bNotify = TRUE) override
        { JMP_THIS(0x4D3F80); }

    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, ppmfc::CCreateContext* pContext) override
        { JMP_THIS(0x4D3E50); }

public:
    ppmfc::CSplitterWnd CSplitter;
};

class CMyViewFrame : public ppmfc::CFrameWnd
{
public:
    virtual ppmfc::CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<ppmfc::CRuntimeClass*>(0x595A88); }

    virtual const ppmfc::AFX_MSGMAP* GetMessageMap() const override
        { JMP_THIS(0x4D2670); }

    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, ppmfc::CCreateContext* pContext) override
        { JMP_THIS(0x4D2680); }

public:
    CMinimap Minimap;
    ppmfc::CStatusBar StatusBar;
    CViewObjects* pViewObjects;
    CIsoView* pIsoView;
    ppmfc::CSplitterWnd SplitterWnd;
    CTileSetBrowserFrame* pTileSetBrowserFrame;
    CRightFrame* pRightFrame;
};