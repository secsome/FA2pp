#pragma once

#include "FA2PP.h"

class NOVTABLE CTags : public FA2CDialog
{
public:
	CTags() = default;

	//member properties
	CComboBox	CCBRepeat; // 92
	CComboBox	CCBTagList; // 152
	CComboBox	CCBTrigger; // 212
	CString			CString_Name; // 272

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4DE780);
	}
};