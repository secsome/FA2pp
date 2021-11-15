#pragma once

#include "FA2PP.h"

class NOVTABLE CCreateMap3A : public FA2CDialog // completely new map
{
public:
	CCreateMap3A() = default;

	//member properties
	INT				MapHeight; // 92
	INT				MapWidth; // 96
	INT				DefaultHeight; // 100
	INT				TheaterIndex; // 104

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4D2E20);
	}
};