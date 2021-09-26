#pragma once
#include "FA2PP.h"
#include "CTileSetBrowserView.h"

// SIZE : 464
// : CFrameWnd
class NOVTABLE CTileSetBrowserFrame : public FA2CFrameWnd
{
public:
	FA2CDialogBar DialogBar;
	CTileSetBrowserView View;
};