#pragma once

#include "FA2PP.h"

class NOVTABLE CPropertyAircraft : public FA2CDialog
{
public:
	CPropertyAircraft() = default;

	//member properties
	BYTE				Unknown_92[4]; // ;/ Fill 92 - 96
	CSliderCtrl		CSCStrength;// 96
	CString			CString_Direction; // 156
	CString			CString_House; // 160
	CString			CString_VeteranLevel; // 164
	CString			CString_Group; // 168
	CString			CString_Recruitable; // 172
	CString			CString_AIRecruitable; // 176
	CString			CString_Status; // 180
	CString			CString_Tag;  // 184

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x401250);
	}
};