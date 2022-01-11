#pragma once

#include "FA2PP.h"

class NOVTABLE CTags : public ppmfc::CDialog
{
public:
	CTags() = default;

	//member properties
	ppmfc::CComboBox	CCBRepeat; // 92
	ppmfc::CComboBox	CCBTagList; // 152
	ppmfc::CComboBox	CCBTrigger; // 212
	ppmfc::CString			CString_Name; // 272

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4DE780); }
};