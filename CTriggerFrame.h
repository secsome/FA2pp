#pragma once

#include "FA2PP.h"

#include "CTriggerOption.h"
#include "CTriggerEvent.h"
#include "CTriggerAction.h"

class NOVTABLE CTriggerFrame : public ppmfc::CDialog
{
public:
	CTriggerFrame() = default;

	//member properties
	CTriggerAction TriggerAction;
	CTriggerEvent TriggerEvent;
	CTriggerOption TriggerOption;
	ppmfc::CComboBox CCBCurrentTrigger;
	CTabCtrl TabCtrl;

	BOOL OnInitDialog() override
	{
		JMP_THIS(0x4FA250);
	}

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override 
		{ JMP_THIS(0x4FA1F0); }

	void OnBNNewTriggerClicked() { JMP_THIS(0x4FAAD0); }
	void OnBNDelTriggerClicked() { JMP_THIS(0x4FB1B0); }
	void OnCBCurrentTriggerSelectedChanged() { JMP_THIS(0x4FBA00); }
	void OnCBCurrentTriggerEditChanged() { JMP_THIS(0x4FBA10); }
	void OnTCSelectedChanged() { JMP_THIS(0x4FBC50); }
	void OnBNPlaceOnMapClicked() { JMP_THIS(0x4FBD10); }
	void OnBNCloneTriggerClicked() { JMP_THIS(0x4FC180); }
	void Update() { JMP_THIS(0x4FA450); }
	
};