#pragma once
#include "FA2PP.h"

#include <ddraw.h>

// CScorllView Size 140
class NOVTABLE CTileSetBrowserView : public FA2CScrollView
{
	virtual void OnDraw(CDC* pDC) {};

public:
	int SelectedOverlayIndex;
	int ScrollWidth;
	LPDIRECTDRAWSURFACE7* TileSurfaces;
	int CurrentTileset;
	int CurrentMode;
	int TileSurfacesCount;
	int CurrentImageHeight;
	int CurrentImageWidth;
};