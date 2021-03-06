#pragma once

#include "FA2PP.h"

class NOVTABLE CPropertyUnit : public FA2CDialog
{
public:
	CPropertyUnit() = default;

	//member properties
	ppmfc::CString			CString_Unknown; // Fill 92 - 96
	CSliderCtrl		CSCStrength;// 96
	ppmfc::CString			CString_Direction; // 156
	ppmfc::CString			CString_VeteranLevel; // 160
	ppmfc::CString			CString_Group; // 164
	ppmfc::CString			CString_House; // 168
	ppmfc::CString			CString_OnBridge; // 172
	ppmfc::CString			CString_FollowerID; // 176
	ppmfc::CString			CString_AutoCreateNoRecruitable; // 180
	ppmfc::CString			CString_AutoCreateYesRecruitable; // 184
	ppmfc::CString			CString_State; // 188
	ppmfc::CString			CString_Tag; // 192

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x50EA90);
	}
};