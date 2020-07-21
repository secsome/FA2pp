#pragma once

#include "FA2PP.h"

class NOVTABLE CPropertyInfantry : public FA2CDialog
{
public:
	CPropertyInfantry() = default;

	//member properties
	INT				Unknown_92; // ;/ Fill 92 - 96
	CSliderCtrl		CSCStrength; // 96
	CString			CString_Direction; // 156
	CString			CString_House; // 160
	CString			CString_VerteranStatus; // 164
	CString			CString_Group; // 168
	CString			CString_OnBridge; // 172
	CString			CString_AutocreateNoRecruitable; // 176
	CString			CString_State; // 180
	CString			CString_Tag; // 184
	CString			CString_AutocreateYesRecruitable;  // 188

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4519A0);
	}
};