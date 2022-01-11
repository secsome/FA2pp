#pragma once

#include "FA2PP.h"

class NOVTABLE CSaveOption : public ppmfc::CDialog
{
public:
	CSaveOption() = default;

	//member properties
	BOOL		BOOL_CompressMap; // 92 , Useless
	INT			INT_CreateNewPreviewWithMinimap; // 96
	ppmfc::CString		CString_MapName; // 100
	BOOL		BOOL_Airwar; // 104
	BOOL		BOOL_Cooperative; // 108
	BOOL		BOOL_LandRush; // 112
	BOOL		BOOL_Meatgrind; // 116
	BOOL		BOOL_MegaWealth; // 120
	BOOL		BOOL_NavalWar; // 124
	BOOL		BOOL_NukeWar; // 128
	BOOL		BOOL_Standard; // 132
	BOOL		BOOL_TeamAlliance; // 136

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4D56E0);
	}
};