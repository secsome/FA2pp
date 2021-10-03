#pragma once

#include "FA2PP.h"

class NOVTABLE CSearchWaypoint : public FA2CDialog
{
public:
	CSearchWaypoint() = default;

	//member properties
	INT			INT_SelectedWaypoint; // 92
	ppmfc::CString		CString_Waypoint; // 96

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4D8EC0);
	}
};