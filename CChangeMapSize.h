#pragma once

#include "FA2PP.h"

class NOVTABLE CChangeMapSize : public FA2CDialog
{
public:
	CChangeMapSize() = default;

	//member properties
	CString		CString_Left; // 92
	CString		CString_Height; // 96, range [0, 511]
	CString		CString_Top; // 100
	CString		CString_Width; // 104, range [0, 511]

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x41B0E0);
	}
};