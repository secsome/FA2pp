#pragma once

#include "FA2PP.h"

class NOVTABLE CCellTag : public FA2CDialog
{
public:
	CCellTag() = default;

	//member properties
	CComboBox	CCBTag; // 92

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x41ADF0);
	}
};