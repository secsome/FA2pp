#pragma once

#include "FA2PP.h"

class NOVTABLE CPropertyUnit : public FA2CDialog
{
public:
	CPropertyUnit() = default;

	//member properties
	BYTE			Unknown_92[4]; // Fill 92 - 96
	CSliderCtrl		CSCStrength;// 96
	CString			CString_Direction; // 156
	CString			CString_VeteranLevel; // 160
	CString			CString_Group; // 164
	CString			CString_House; // 168
	CString			CString_OnBridge; // 172
	CString			CString_FollowerID; // 176
	CString			CString_AutoCreateNoRecruitable; // 180
	CString			CString_AutoCreateYesRecruitable; // 184
	CString			CString_State; // 188
	CString			CString_Tag; // 192

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x50EA90);
	}
};