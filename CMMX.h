#pragma once

#include "FA2PP.h"

class NOVTABLE CMMX : public FA2CDialog
{
public:
	CMMX() = default;

	//member properties
	CString			CString_DescriptionTag; // 92
	BOOL			BOOL_Airwar; // 96
	BOOL			BOOL_Cooperative; // 100
	BOOL			BOOL_Duel; // 104
	INT				INT_MaxPlayer; // 108
	BOOL			BOOL_Meatgrind; // 112
	BOOL			BOOL_MegaWealth; // 116
	INT				INT_MinPlayer; // 120
	BOOL			BOOL_NavalWar; // 124
	BOOL			BOOL_NukeWar; // 128
	BOOL			BOOL_Standard; // 132

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4D2240);
	}
};