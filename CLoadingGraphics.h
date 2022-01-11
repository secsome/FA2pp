#pragma once

#include "FA2PP.h"

class NOVTABLE CLoadingGraphics : public ppmfc::CDialog
{
public:
	CLoadingGraphics() = default;

	//member properties
	CProgressCtrl	CPCLoadingGraphics; // 92

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4CE620);
	}
};