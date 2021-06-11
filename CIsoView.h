#pragma once

#include "FA2PP.h"

#include <ddraw.h>

// Forward declarations
class CMyViewFrame;

class CIsoView : public FA2CView
{
public:
    static int GetCoordX(int nCoord) { return nCoord % 1000; }
    static int GetCoordY(int nCoord) { return nCoord / 1000; }
    static int GetCoord(int X, int Y) { return X * 1000 + Y; }

    void MoveToWP(UINT nWaypoint) { JMP_THIS(0x4766A0); }
    void MoveTo(int X, int Y) { JMP_THIS(0x4763D0); }
    void MoveToCoord(int X, int Y) 
    {
        // Main code from CIsoView::MoveToWP
        int nHW = *reinterpret_cast<DWORD*>(0x72CC00); // CurrentMapWidthPlusHeight, we don't want too much headers included.
        int nParam = X + Y * nHW;
        RECT rect;
        this->GetWindowRect(&rect);
        int v6 = (60 * (nParam % nHW)) / 4
            + (30 * (nParam / nHW)) / 2
            - 30
            * *(unsigned __int8*)(((nParam % nHW
                + nParam / nHW * nHW) << 6)
                + *reinterpret_cast<DWORD*>(0x7ACDB8)
                + 51)
            / 2;
        this->MoveTo(
            30 * (nHW + (nParam / nHW)) - (rect.right - rect.left) / 2 - (30 * (nParam % nHW)) - rect.left,
            v6 - (rect.bottom - rect.top) / 2 - rect.top
        );
        this->RedrawWindow(nullptr, nullptr, RDW_INVALIDATE | RDW_UPDATENOW);
    }

    int Unknown_40;
    int Unknown_44;
    int Unknown_48;
    int Unknown_4C;
    int Unknown_50;
    int Unknown_54;
    int Unknown_58;
    int Unknown_5C; // X related
    int Unknown_60; // Y related
    int Unknown_64;
    int Unknown_68;
    int Unknown_6C;
    int Unknown_74;
    int Unknown_78;
    int Unknown_7C;
    int Unknown_80;
    int Unknown_84;
    int Unknown_88;
    int Unknown_8C;
    int Unknown_90;
    int Unknown_94;
    CMyViewFrame* pParent;
    int Unknown_9C;
    LPDIRECTDRAWSURFACE7 lpDDTempBufferSurface;
    LPDIRECTDRAWSURFACE7 lpDDPrimarySurface;
    IDirectDraw7* lpDD7;
    LPDIRECTDRAW lpDirectDraw;
    int Unknown_B0;
    CMenu Menu;
    BOOL IsInitializing;
    int Unknown_BC;
    int Unknown_C0;
    int Unknown_C4;
    int Unknown_C8;
    int Unknown_CC;
    int Unknown_D0;
    int Unknown_D4;
    int Unknown_D8;
    int Unknown_DC;
    int Unknown_E0;
    int Unknown_E4;
    int Unknown_E8;
    int Unknown_EC;
};
