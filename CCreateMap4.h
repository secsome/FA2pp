#pragma once

#include "FA2PP.h"

class NOVTABLE CCreateMap4 : public ppmfc::CDialog
{
public:
	CCreateMap4() = default;

	//member properties
	BOOL		BOOL_SetAutoProductionTriggers; // 92
	INT			INT_PlayerHouseIndex; // 96
	BOOL		BOOL_PrepareStandardHouses; // 100

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4D3350); }
};