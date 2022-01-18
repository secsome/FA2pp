#pragma once

#include "FA2PP.h"
#include "CMapData.h"

#include "CFinalSunApp.h"
#include "CFinalSunDlg.h"

#include <ddraw.h>

// Forward declarations
class CMyViewFrame;

enum FACurrentCommand : int
{
    Nothing = 0x0,
    ObjectPlace = 0x1,
    ObjectDelete = 0x2,
    WaypointHandle = 0x3,
    CelltagHandle = 0x4,
    BasenodeHandle = 0x5,
    TunnelHandle = 0x6,
    TileDraw = 0xA,
    HeightenGround = 0xB,
    LowerGround = 0xC,
    LowerSingleTile = 0xD,
    RaiseSingleTile = 0xE,
    MakeTerrainFlat = 0xF,
    HideTileSet = 0x10,
    HideSingleField = 0x11,
    PaintCliffFront = 0x12,
    PaintCliffBack = 0x13,
    TileCopy = 0x14,
    TilePaste = 0x15,
    TerrainRandom = 0x16,
};


class CIsoView : public ppmfc::CView
{
public:
    virtual ppmfc::CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<ppmfc::CRuntimeClass*>(0x5942B8); }

    static constexpr reference<ppmfc::CRuntimeClass, 0x5942B8> RuntimeClass{};
    static constexpr reference<bool, 0x5E7C0C> const RButtonDownOrFocusKilled{};
    static constexpr reference<bool, 0x5E7C10> const Destoryed{};
    static constexpr reference<bool, 0x5E7C14> const ScrollingRelatedFlag{};

    static CIsoView* GetInstance()
    {
        return CFinalSunDlg::Instance->MyViewFrame.pIsoView;
    }

    struct CurrentCommand // 518CB0 is the evidence
    {
        CurrentCommand() { JMP_THIS(0x518CF0); }
        ~CurrentCommand() { JMP_THIS(0x518CD0); }

        int Command;
        int Type;
        int Param;
        int Overlay;
        int OverlayData;
        int Height;
        DECLARE_PROPERTY(ppmfc::CString, ObjectID);
    };

    static constexpr reference<bool, 0x7EE080> const ControlKeyIsDown{};
    static constexpr reference<CurrentCommand, 0x72CBD8> const CurrentCommand{};
    static constexpr reference<ppmfc::CString, 0x5E7C98> const CurrentHouse{};

    static int GetCoordX(int nCoord) { return nCoord % 1000; }
    static int GetCoordY(int nCoord) { return nCoord / 1000; }
    static int GetCoord(int X, int Y) { return X * 1000 + Y; }

    static void __cdecl ScreenCoord2MapCoord_Flat(int& Y, int& X) { JMP_STD(0x466890); }
    static void __cdecl ScreenCoord2MapCoord_Height(int& Y, int& X) { JMP_STD(0x460F00); }
    inline static void ScreenCoord2MapCoord(int& Y, int& X)
    {
        if (CFinalSunApp::Instance->FlatToGround)
            ScreenCoord2MapCoord_Flat(Y, X);
        else
            ScreenCoord2MapCoord_Height(Y, X);
    }

    static void __cdecl MapCoord2ScreenCoord_Height(int& Y, int& X) { JMP_STD(0x45E880); }
    static void __cdecl MapCoord2ScreenCoord_Flat(int& Y, int& X) { JMP_STD(0x476240); }
    inline static void MapCoord2ScreenCoord(int& Y, int& X)
    {
        if (CFinalSunApp::Instance->FlatToGround)
            MapCoord2ScreenCoord_Flat(Y, X);
        else
            MapCoord2ScreenCoord_Height(Y, X);
    }
    inline MapCoord GetCurrentMapCoord(const CPoint& point)
    {
        RECT rect;
        this->GetWindowRect(&rect);
        int y = point.x + rect.left + this->ViewPosition.x;
        int x = point.y + rect.top + this->ViewPosition.y;
        ScreenCoord2MapCoord(y, x);
        return MapCoord{ x,y };
    }

    void MoveToWP(UINT nWaypoint) { JMP_THIS(0x4766A0); }
    void MoveTo(int X, int Y) { JMP_THIS(0x4763D0); }
    void MoveToMapCoord(int X, int Y) 
    {
        int nMapCoord = CMapData::Instance->GetCoordIndex(X, Y);
        RECT rect;
        this->GetWindowRect(&rect);
        this->MoveTo(
            30 * (CMapData::Instance->MapWidthPlusHeight + X - Y) - (rect.right - rect.left) / 2 - rect.left,
            15 * (Y + X) - CMapData::Instance->CellDatas[nMapCoord].Height - (rect.bottom - rect.top) / 2 - rect.top
        );
        this->RedrawWindow(nullptr, nullptr, RDW_INVALIDATE | RDW_UPDATENOW);
    }

    void DrawText(int X, int Y, LPCSTR lpString, COLORREF color) { JMP_THIS(0x4685C0); }
    void Draw() { JMP_THIS(0x46DE00); }
    void PrimarySurfaceLost() { JMP_THIS(0x4691D0); }
    void BltToBackBuffer(LPDIRECTDRAWSURFACE7 lpSrcSurface, int X, int Y, int W, int H) { JMP_THIS(0x4751B0); }
    
    void AfterUpdate(BOOL bSomeValidate) { JMP_THIS(0x456C10); }

    void DrawCellOutline(int X, int Y,int W,int H,COLORREF color,BOOL bDot,BOOL bDrawOnPrimarySurface)
        { JMP_THIS(0x469C60); }

    void UpdateStatusBar(int Y, int X) { JMP_THIS(0x469E70); }
    void DrawMouseAttachedStuff(int Y, int X, LPDIRECTDRAWSURFACE7 lpSurface) { JMP_THIS(0x46BC80); }

    void AutoConnectOverlayAt(int Y, int X) { JMP_THIS(0x469B20); }

    int StartCellY;
    int StartCellX; // which cell the left button clicked on
    int Height_48;
    int Unknown_4C;
    int Unknown_50;
    int Unknown_54;
    int Unknown_58;
    ppmfc::CPoint ViewPosition; // where the view center at
    ppmfc::CPoint MoveCenterPosition; // where right button down
    ppmfc::CPoint MouseCurrentPosition;
    BOOL IsScrolling;
    BOOL KeyboardAMode;
    int Unknown_7C;
    int Unknown_80;
    int Unknown_84;
    int Unknown_88;
    int LeftButtonDoubleClick_8C;
    int BrushSizeY;
    int BrushSizeX;
    CMyViewFrame* pParent;
    LPDIRECTDRAWSURFACE7 lpDDBackBufferSurface;
    LPDIRECTDRAWSURFACE7 lpDDTempBufferSurface;
    LPDIRECTDRAWSURFACE7 lpDDPrimarySurface;
    IDirectDraw7* lpDD7;
    LPDIRECTDRAW lpDirectDraw;
    int Unknown_B0;
    ppmfc::CMenu Menu;
    BOOL IsInitializing;
    RECT Rect_C0;
    int Unknown_D0;
    ppmfc::CPoint LineFrom;
    ppmfc::CPoint LineTo;
    int CurrentCellObjectType;
    int CurrentCellObjectIndex;
    int Flag_EC;
    int Unknown_F0;
};
