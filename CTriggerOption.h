#pragma once

#include "FA2PP.h"

class NOVTABLE CTriggerOption : public FA2CDialog
{
public:
	CTriggerOption() = default;

	//member properties
	BYTE		Unknown_92[4]; // Fill 92 - 96
	CButton		CBNMedium; // 96
	CButton		CBNHard; // 156
	CButton		CBNEasy; // 216
	CButton		CBNDisabled; // 276
	CComboBox	CCBRepeatType; // 336
	CEdit		CETName; // 396
	CComboBox	CCBHouse; // 456
	CComboBox	CCBAttachedTag; // 516

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x5008C0);
	}
};