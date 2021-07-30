#pragma once

#include "FA2PP.h"

class NOVTABLE CTriggerEvent : public FA2CDialog
{
public:
	CTriggerEvent() = default;

	//member properties
	ppmfc::CString		EventID; // 92
	CComboBox	CCBParameters; // 96
	CListBox	CLBParamList; // 156
	CComboBox	CCBEventType; // 216
	CEdit		CETDescription; // 276
	CComboBox	CCBCurrentEvent; // 336

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4FD0B0);
	}

	void OnBNNewEventClicked() { JMP_THIS(0x4FD1D0); }
	void OnBNDelEventClicked() { JMP_THIS(0x4FD630); }
	void OnCBCurrentEventSelChanged() { JMP_THIS(0x4FDAD0); }
	void OnCBEventTypeEditChanged() { JMP_THIS(0x4FDDB0); }
	void OnLBParamsSelChanged() { JMP_THIS(0x4FF3E0); }
	void OnCBParamValueEditChanged() { JMP_THIS(0x4FFB10); }
};