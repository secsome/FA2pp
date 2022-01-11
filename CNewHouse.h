#pragma once

#include "FA2PP.h"

class NOVTABLE CNewHouse : public ppmfc::CDialog
{
public:
	CNewHouse() = default;

	//member properties
	ppmfc::CString		CString_House; // 92

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4D37C0); }
};