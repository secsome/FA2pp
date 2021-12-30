#pragma once

#include "FA2PP.h"

class NOVTABLE CPropertyBuilding : public FA2CDialog
{
public:

	//member properties
	ppmfc::CString			CString_ObjectID; // ;/ Fill 92 - 100
	ppmfc::CString			CString_HealthPoint;
	CSliderCtrl		CSCStrength;// 100
	ppmfc::CString			CString_Direction; // 160
	ppmfc::CString			CString_House; // 164
	ppmfc::CString			CString_Sellable; // 168
	ppmfc::CString			CString_Rebuildable; // 172
	ppmfc::CString			CString_EnergySupport; // 176
	ppmfc::CString			CString_Spotlight; // 180
	ppmfc::CString			CString_UpgradeCount; // 184
	ppmfc::CString			CString_Upgrade1; // 188
	ppmfc::CString			CString_Upgrade2;  // 192
	ppmfc::CString			CString_Upgrade3;  // 196
	ppmfc::CString			CString_AIRepairs; // 200
	ppmfc::CString			CString_ShowName; // 204
	ppmfc::CString			CString_Tag; // 208

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x417910);
	}

	// Should be ppmfc::CWnd*
	CPropertyBuilding(void* pParent) { JMP_THIS(0x417480); }

	void Translate() { JMP_THIS(0x41A750); }

private:
	CPropertyBuilding(noinit_t) {}
};