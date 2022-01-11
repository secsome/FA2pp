#pragma once

#include "FA2PP.h"

class NOVTABLE CSpecialFlags : public ppmfc::CDialog
{
public:
	CSpecialFlags() = default;

	//member properties
	ppmfc::CComboBox			CCBVisceroids; // 92
	ppmfc::CComboBox			CCBTiberiumSpreads; // 152
	ppmfc::CComboBox			CCBTiberiumGrows; // 212
	ppmfc::CComboBox			CCBTiberiumExplosive; // 272
	ppmfc::CComboBox			CCBMeteorites; // 332
	ppmfc::CComboBox			CCBMCVDeploy; // 392
	ppmfc::CComboBox			CCBIonStorms; // 452
	ppmfc::CComboBox			CCBInitialVeteran; // 512
	ppmfc::CComboBox			CCBInert; // 572
	ppmfc::CComboBox			CCBHarvesterImmune; // 632
	ppmfc::CComboBox			CCBFogOfWar; // 692
	ppmfc::CComboBox			CCBFixedAlliance; // 752
	ppmfc::CComboBox			CCBDestoryableBridges; // 812

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4DBDD0); }
};