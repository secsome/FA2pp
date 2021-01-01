#pragma once

#include "FA2PP.h"

#include "CTriggerOption.h"
#include "CTriggerEvent.h"
#include "CTriggerAction.h"

class NOVTABLE CTriggerFrame : public FA2CDialog
{
public:
	CTriggerFrame() = default;

	//member properties
	CTriggerAction TriggerAction;
	CTriggerEvent TriggerEvent;
	CTriggerOption TriggerOption;
	char gap[148];
	CTabCtrl TabCtrl;


	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4CEAE0);
	}
};