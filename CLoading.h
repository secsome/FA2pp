#pragma once

#include "FA2PP.h"

class NOVTABLE CLoading : public FA2CDialog
{
public:
	CLoading() = default;

	//member properties
	INT			Unknown_92; // Fill 92 - 96
	CStatic		CSCVersion; // 96
	CStatic		CSCBuiltby; // 156
	CStatic		CSCLoading; // 216
	CProgressCtrl	CPCProgress; // 276

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x479C70);
	}
};