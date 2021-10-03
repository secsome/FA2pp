#pragma once

#include "FA2PP.h"

class NOVTABLE CNewHouse : public FA2CDialog
{
public:
	CNewHouse() = default;

	//member properties
	ppmfc::CString		CString_House; // 92

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4D37C0);
	}
};