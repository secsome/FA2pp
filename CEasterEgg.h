#pragma once

#include "FA2PP.h"

class NOVTABLE CEasterEgg : public FA2CDialog
{
public:
	CEasterEgg() = default;

	//member properties
	CStatic		CSCGamePanel; // 92

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x41E7E0);
	}
};