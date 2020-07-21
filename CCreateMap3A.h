#pragma once

#include "FA2PP.h"

class NOVTABLE CCreateMap3A : public FA2CDialog // completely new map
{
public:
	CCreateMap3A() = default;

	//member properties
	CString			CString_Height; // 92
	CString			CString_Width; // 96
	INT				INT_StartingHeight; // 100
	INT				INT_TheaterIndex; // 104

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4D2E20);
	}
};