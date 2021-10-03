#pragma once

#include "FA2PP.h"

class NOVTABLE CCreateMap1 : public FA2CDialog
{
public:
	CCreateMap1() = default;

	//member properties
	BOOL		BOOL_SinglePlayerMap; // 92

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4D36C0);
	}
};