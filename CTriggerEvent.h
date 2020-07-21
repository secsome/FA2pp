#pragma once

#include "FA2PP.h"

class NOVTABLE CTriggerEvent : public FA2CDialog
{
public:
	CTriggerEvent() = default;

	//member properties
	BYTE		Unknown_92[4]; // Fill 92 - 96
	CComboBox	CCBParameters; // 96
	CListBox	CLBParamList; // 156
	CComboBox	CCBEventType; // 216
	CEdit		CETDescription; // 276
	CComboBox	CCBCurrentEvent; // 336

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4FD0B0);
	}
};