#pragma once

#include "FA2PP.h"

class NOVTABLE CRandomTree : public FA2CDialog
{
public:
	CRandomTree() = default;

	//member properties
	CButton		CBNPreviewImage; // 92
	CListBox	CLBUsed; // 152
	CListBox	CLBAvailable; // 212

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4D4100);
	}
};