#pragma once

#include "FA2PP.h"

class NOVTABLE CTriggerFrame : public FA2CDialog
{
public:
	CTriggerFrame() = default;

	//member properties
	BYTE				Unknown_92[8]; // ;/ Fill 92 - 100
	CComboBox	CCBTriggerList; // 100

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4CEAE0);
	}
};