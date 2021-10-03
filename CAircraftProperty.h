#pragma once

#include "FA2PP.h"

class NOVTABLE CAircraftProperty : public FA2CDialog
{
public:
	CAircraftProperty() = default;

	//member properties
	ppmfc::CString			CString_Unknown; // ;/ Fill 92 - 96
	CSliderCtrl		CSCStrength;// 96
	ppmfc::CString			CString_Direction; // 156
	ppmfc::CString			CString_House; // 160
	ppmfc::CString			CString_VeteranLevel; // 164
	ppmfc::CString			CString_Group; // 168
	ppmfc::CString			CString_Recruitable; // 172
	ppmfc::CString			CString_AIRecruitable; // 176
	ppmfc::CString			CString_Status; // 180
	ppmfc::CString			CString_Tag;  // 184

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x401250);
	}
};