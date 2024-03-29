#pragma once

#include "FA2PP.h"

class NOVTABLE CLighting : public ppmfc::CDialog
{
public:
	CLighting() = default;

	//member properties
	ppmfc::CEdit CETLightingRed; // 92
	ppmfc::CEdit CETNormalRed; // 152
	ppmfc::CEdit CETLightingLevel; // 212
	ppmfc::CEdit CETNormalLevel; // 272
	ppmfc::CEdit CETLightingGreen; // 332
	ppmfc::CEdit CETNormalGreen; // 392
	ppmfc::CEdit CETLightingBlue; // 452
	ppmfc::CEdit CETNormalBlue; // 512
	ppmfc::CEdit CETLightingIon; // 572
	ppmfc::CEdit CETNormalIon; // 632

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4775E0); }
};