#pragma once

#include "FA2PP.h"

class NOVTABLE CMapScripts : public FA2CDialog
{
public:
	CMapScripts() = default;

	//member properties
	ppmfc::CString	CString_CurrentScript; // 92
	ppmfc::CString	CString_Report; // 96
	
	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x5100A0);
	}

};