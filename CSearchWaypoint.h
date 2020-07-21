#pragma once

#include "FA2PP.h"

class NOVTABLE CSearchWaypoint : public FA2CDialog
{
public:
	CSearchWaypoint() = default;

	//member properties
	BYTE			Unknown_92[4]; // Fill 92 - 96
	CString		CString_Waypoint; // 96

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4D8EC0);
	}
};