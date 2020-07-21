#pragma once

#include "FA2PP.h"

class NOVTABLE CCreateMap4 : public FA2CDialog
{
public:
	CCreateMap4() = default;

	//member properties
	BOOL		BOOL_SetAutoProductionTriggers; // 92
	INT			INT_PlayerHouseIndex; // 96
	BOOL		BOOL_PrepareStandardHouses; // 100

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4D3350);
	}
};