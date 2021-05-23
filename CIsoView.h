#pragma once

#include "FA2PP.h"

#include <ddraw.h>

// Forward declarations
class CMyViewFrame;

class CIsoView : public FA2CView
{
public:
    int Unknown_40;
    int Unknown_44;
    int Unknown_48;
    int Unknown_4C;
    int Unknown_50;
    int Unknown_54;
    int Unknown_58;
    int Unknown_5C;
    int Unknown_60;
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
