#pragma once
#include "FA2PP.h"

// CScorllView Size 140
class NOVTABLE CTileSetBrowserView : public FA2CScrollView
{
	virtual void OnDraw(CDC* pDC) {};

public:
	int SelectedOverlayIndex;
	int ScrollWidth;
	int Unknown_74;
	int CurrentTileset;
	int CurrentMode;
	int Unknown_80;
	int CurrentImageHeight;
	int CurrentImageWidth;
};