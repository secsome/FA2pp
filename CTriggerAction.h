#pragma once

#include "FA2PP.h"

class NOVTABLE CTriggerAction : public FA2CDialog
{
public:
	CTriggerAction() = default;

	//member properties
	ppmfc::CString		ActionID; // 92
	ppmfc::CComboBox	CCBParameters; // 96
	CListBox	CLBParamList; // 156
	ppmfc::CComboBox	CCBActionType; // 216
	ppmfc::CEdit		CETDescription; // 276
	ppmfc::CComboBox	CCBCurrentAction; // 336

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4F60D0);
	}

	void OnBNNewActionClicked() { JMP_THIS(0x4F90C0); }
	void OnBNDelActionClicked() { JMP_THIS(0x4F9480); }
	void OnCBCurrentActionSelChanged() { JMP_THIS(0x4F6150); }
	void OnCBActionTypeEditChanged() { JMP_THIS(0x4F6430); }
	void OnLBParamsSelChanged() { JMP_THIS(0x4F80B0); }
	void OnCBParamValueEditChanged() { JMP_THIS(0x4F8880); }
};