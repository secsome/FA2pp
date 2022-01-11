#pragma once
#include "FA2PP.h"

#include <ddraw.h>

// CScorllView Size 140
class NOVTABLE CTileSetBrowserView : public ppmfc::CScrollView
{
	virtual void OnDraw(ppmfc::CDC* pDC) override
		{ JMP_THIS(0x4F1D70); }

public:
	void SelectTileSet(int nTileSet, bool bNotInvokeUpdate) { JMP_THIS(0x4F2B10); }

	int SelectedOverlayIndex;
	int ScrollWidth;
	LPDIRECTDRAWSURFACE7* TileSurfaces;
	int CurrentTileset;
	int CurrentMode;
	int TileSurfacesCount;
	int CurrentImageHeight;
	int CurrentImageWidth;
};