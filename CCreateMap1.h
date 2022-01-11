#pragma once

#include "FA2PP.h"

class NOVTABLE CCreateMap1 : public ppmfc::CDialog
{
public:
	CCreateMap1() = default;

	//member properties
	BOOL		BOOL_SinglePlayerMap; // 92

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4D36C0); }
};