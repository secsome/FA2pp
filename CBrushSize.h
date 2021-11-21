#pragma once

#include "FA2PP.h"

class NOVTABLE CBrushSize : public CDialogBar
{
public:
	CBrushSize() = default;

	static void __stdcall UpdateBrushSize(unsigned int nTileset) { JMP_STD(0x523350); }

	//member properties
	int nCurSel; // ComboBox 1377
};