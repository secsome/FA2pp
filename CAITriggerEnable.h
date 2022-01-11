#pragma once

#include "FA2PP.h"

// the sub window of CAITriggerTypesEnable
class NOVTABLE CAITriggerEnable : public ppmfc::CDialog
{
public:
	CAITriggerEnable() = default;

	//member properties
	ppmfc::CString		CString_5C;
	ppmfc::CListBox	CLBAITriggerTypes;
};