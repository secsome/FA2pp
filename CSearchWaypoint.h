#pragma once

#include "FA2PP.h"

class NOVTABLE CSearchWaypoint : public ppmfc::CDialog
{
public:
	CSearchWaypoint() = default;

	//member properties
	INT			INT_SelectedWaypoint; // 92
	ppmfc::CString		CString_Waypoint; // 96

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4D8EC0); }
};