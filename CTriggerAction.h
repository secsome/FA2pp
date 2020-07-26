#pragma once

#include "FA2PP.h"

class NOVTABLE CTriggerAction : public FA2CDialog
{
public:
	CTriggerAction() = default;

	//member properties
	BYTE		Unknown_92[4]; // Fill 92 - 96
	CComboBox	CCBParameters; // 96
	CListBox	CLBParamList; // 156
	CComboBox	CCBActionType; // 216
	CEdit		CETDescription; // 276
	CComboBox	CCBCurrentAction; // 336

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4F60D0);
	}
};