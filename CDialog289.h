#pragma once

#include "FA2PP.h"

class NOVTABLE CDialog289 : public FA2CDialog // Dialog 289, don't know where uses
{
public:
	CDialog289() = default;

	//member properties
	BYTE Unknown_92[24]; // Fill 92 - 116
	CString CString_Captain; // 116
	CString CString_Combo; // 120


	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x0041DD20);
	}
};