#pragma once

#include "FA2PP.h"

class NOVTABLE CAITriggerTypesEnable : public ppmfc::CDialog
{
public:
	CAITriggerTypesEnable() = default;

	//member properties
	ppmfc::CComboBox	CCBAITriggerTypes;
};