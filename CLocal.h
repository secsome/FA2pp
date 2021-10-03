#pragma once

#include "FA2PP.h"

class NOVTABLE CLocal : public FA2CDialog
{
public:
	CLocal() = default;

	//member properties
	ppmfc::CComboBox			CCBPresetValue; // 92
	ppmfc::CComboBox			CCBLocalList; // 152
	ppmfc::CString					CString_Name; // 212


	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x448070);
	}
};