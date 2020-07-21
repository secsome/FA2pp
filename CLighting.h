#pragma once

#include "FA2PP.h"

class NOVTABLE CLighting : public FA2CDialog
{
public:
	CLighting() = default;

	//member properties
	CEdit CETLightingRed; // 92
	CEdit CETNormalRed; // 152
	CEdit CETLightingLevel; // 212
	CEdit CETNormalLevel; // 272
	CEdit CETLightingGreen; // 332
	CEdit CETNormalGreen; // 392
	CEdit CETLightingBlue; // 452
	CEdit CETNormalBlue; // 512
	CEdit CETLightingIon; // 572
	CEdit CETNormalIon; // 632


	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4775E0);
	}
};