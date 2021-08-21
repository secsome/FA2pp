#pragma once

#include "FA2PP.h"

class NOVTABLE CAITriggerTypesEnable : public FA2CDialog
{
public:
	CAITriggerTypesEnable() = default;

	//member properties
	ppmfc::CComboBox	CCBAITriggerTypes;
};