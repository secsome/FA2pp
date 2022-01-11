#pragma once

#include "FA2PP.h"

class NOVTABLE CTriggerAction : public ppmfc::CDialog
{
public:
	CTriggerAction() = default;

	//member properties
	ppmfc::CString		TriggerID; // 92
	ppmfc::CComboBox	CCBParameters; // 96
	ppmfc::CListBox	CLBParamList; // 156
	ppmfc::CComboBox	CCBActionType; // 216
	ppmfc::CEdit		CETDescription; // 276
	ppmfc::CComboBox	CCBCurrentAction; // 336

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4F60D0); }

	void OnBNNewActionClicked() { JMP_THIS(0x4F90C0); }
	void OnBNDelActionClicked() { JMP_THIS(0x4F9480); }
	void OnCBCurrentActionSelChanged() { JMP_THIS(0x4F6150); }
	void OnCBActionTypeEditChanged() { JMP_THIS(0x4F6430); }
	void OnLBParamsSelChanged() { JMP_THIS(0x4F80B0); }
	void OnCBParamValueEditChanged() { JMP_THIS(0x4F8880); }
	void Update() { JMP_THIS(0x4F9940); }
};