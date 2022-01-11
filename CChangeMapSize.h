#pragma once

#include "FA2PP.h"

class NOVTABLE CChangeMapSize : public ppmfc::CDialog
{
public:
	CChangeMapSize() = default;

	//member properties
	int		INT_Left; // 92
	int		INT_Height; // 96, range [0, 511]
	int		INT_Top; // 100
	int		INT_Width; // 104, range [0, 511]

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x41B0E0);
	}
};