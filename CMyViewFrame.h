#pragma once

#include "FA2PP.h"

#include "CWndView.h"

// For Temperory Use
class CMyViewFrame : CFrameWnd
{
public:
    CWndView WndView;
    CStatusBar StatusBar;
    DWORD unknown_A;
    DWORD unknown_B;
    CSplitterWnd SplitterWnd;
    DWORD unknown_C;
    DWORD unknown_D;
};