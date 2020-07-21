#pragma once

#include "FA2PP.h"

class NOVTABLE CPropertyBuilding : public FA2CDialog
{
public:
	CPropertyBuilding() = default;

	//member properties
	BYTE				Unknown_92[8]; // ;/ Fill 92 - 100
	CSliderCtrl		CSCStrength;// 100
	CString			CString_Direction; // 160
	CString			CString_House; // 164
	CString			CString_Sellable; // 168
	CString			CString_Rebuildable; // 172
	CString			CString_EnergySupport; // 176
	CString			CString_Spotlight; // 180
	CString			CString_UpgradeCount; // 184
	CString			CString_Upgrade1; // 188
	CString			CString_Upgrade2;  // 192
	CString			CString_Upgrade3;  // 196
	CString			CString_AIRepairs; // 200
	CString			CString_ShowName; // 204
	CString			CString_Tag; // 208

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x417910);
	}
};