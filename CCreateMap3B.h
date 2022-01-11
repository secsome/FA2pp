#pragma once

#include "FA2PP.h"

class NOVTABLE CCreateMap3B : public ppmfc::CDialog // Import map
{
public:
	CCreateMap3B() = default;

	//member properties
	ppmfc::CString			CString_FilePath; // 92
	BOOL			BOOL_ImportOverlay; // 96
	BOOL			BOOL_ImportTrees; // 100
	BOOL			BOOL_ImportUnitsAndBuildings; // 104

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4D3070); }
};