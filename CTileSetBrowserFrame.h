#pragma once
#include "FA2PP.h"
#include "CTileSetBrowserView.h"

// SIZE : 464
// : CFrameWnd
class NOVTABLE CTileSetBrowserFrame : public ppmfc::CFrameWnd
{
public:
	static constexpr reference<ppmfc::CRuntimeClass, 0x597378> RuntimeClass{};

	ppmfc::CDialogBar DialogBar;
	CTileSetBrowserView View;
};