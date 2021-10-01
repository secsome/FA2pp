#pragma once

#include "FA2PP.h"

class NOVTABLE CTriggerOption : public FA2CDialog
{
public:
	CTriggerOption() = default;

	//member properties
	ppmfc::CString		TriggerID; // 92
	CButton		CBNMedium; // 96
	CButton		CBNHard; // 156
	CButton		CBNEasy; // 216
	CButton		CBNDisabled; // 276
	ppmfc::CComboBox	CCBRepeatType; // 336
	ppmfc::CEdit		CETName; // 396
	ppmfc::CComboBox	CCBHouse; // 456
	ppmfc::CComboBox	CCBAttachedTag; // 516
	CToolTipCtrl CTTCHouse;

	BOOL OnInitDialog() override
	{
		JMP_THIS(0x502DC0);
	}

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x5008C0);
	}

	void Update() { JMP_THIS(0x500970); }
};