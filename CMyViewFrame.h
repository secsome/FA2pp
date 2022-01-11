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

class CRightFrame : public FA2CFrameWnd
{
public:
    FA2CSplitterWnd CSplitter;
};

class CMyViewFrame : public FA2CFrameWnd
{
public:
    CMinimap Minimap;
    ppmfc::CStatusBar StatusBar;
    CViewObjects* pViewObjects;
    CIsoView* pIsoView;
    FA2CSplitterWnd SplitterWnd;
    CTileSetBrowserFrame* pTileSetBrowserFrame;
    CRightFrame* pRightFrame;

    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
    {
        JMP_THIS(0x4D2680);
    }
};