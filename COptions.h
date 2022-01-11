#pragma once

#include "FA2PP.h"

class NOVTABLE COptions : public ppmfc::CDialog
{
public:
	COptions() = default;

	//member properties
	BYTE		Unknown_92[8]; // Fill 92 - 100
	ppmfc::CComboBox	CCBLanguage; // 100
	ppmfc::CEdit		CETPath; // 160
	BOOL		BOOL_SelectMode; // 220

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x50E1D0); }
};