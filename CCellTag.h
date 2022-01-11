#pragma once

#include "FA2PP.h"

class NOVTABLE CCellTag : public ppmfc::CDialog
{
public:
	CCellTag() = default;

	//member properties
	ppmfc::CString	Tag; // 92

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x41ADF0); }
};