#pragma once

#include "FA2PP.h"

class NOVTABLE CLocal : public FA2CDialog
{
public:
	CLocal() = default;

	//member properties
	CComboBox			CCBPresetValue; // 92
	CComboBox			CCBLocalList; // 152
	CString					CString_Name; // 212


	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x448070);
	}
};