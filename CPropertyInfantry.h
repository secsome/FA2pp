#pragma once

#include "FA2PP.h"

class NOVTABLE CPropertyInfantry : public FA2CDialog
{
public:
	CPropertyInfantry() = default;

	//member properties
	ppmfc::CString			CString_Unknown; // ;/ Fill 92 - 96
	CSliderCtrl		CSCStrength; // 96
	ppmfc::CString			CString_Direction; // 156
	ppmfc::CString			CString_House; // 160
	ppmfc::CString			CString_VerteranStatus; // 164
	ppmfc::CString			CString_Group; // 168
	ppmfc::CString			CString_OnBridge; // 172
	ppmfc::CString			CString_AutocreateNoRecruitable; // 176
	ppmfc::CString			CString_State; // 180
	ppmfc::CString			CString_Tag; // 184
	ppmfc::CString			CString_AutocreateYesRecruitable;  // 188

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4519A0);
	}
};