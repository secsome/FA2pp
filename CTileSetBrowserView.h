#pragma once
#include "FA2PP.h"

// CScorllView Size 140
class NOVTABLE CTileSetBrowserView : CScrollView
{
	virtual void OnDraw(CDC* pDC) {};

public:
	int SelectedIndex;
	PROTECTED_PROPERTY(char, gap_69[3]);
	int field_70;
	int field_74;
	int field_78;
	int field_7c;
	PROTECTED_PROPERTY(char, gap_7C[4]);
	int unknown_84;
};