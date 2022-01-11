#pragma once

#include "FA2PP.h"

class NOVTABLE CPropertyInfantry : public ppmfc::CDialog
{
public:
	//member properties
	ppmfc::CString			CString_HealthPoint; // ;/ Fill 92 - 96
	CSliderCtrl		CSCStrength; // 96
	ppmfc::CString			CString_Direction; // 156
	ppmfc::CString			CString_House; // 160
	ppmfc::CString			CString_VerteranStatus; // 164
	ppmfc::CString			CString_Group; // 168
	ppmfc::CString			CString_OnBridge; // 172
	ppmfc::CString			CString_AutoCreateNoRecruitable; // 176
	ppmfc::CString			CString_State; // 180
	ppmfc::CString			CString_Tag; // 184
	ppmfc::CString			CString_AutoCreateYesRecruitable;  // 188

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4519A0); }

	CPropertyInfantry(ppmfc::CWnd* pParent = nullptr) { JMP_THIS(0x451640); }

private:
	CPropertyInfantry(noinit_t) {}
};