#pragma once

#include "FA2PP.h"

class NOVTABLE CSpecialFlags : public FA2CDialog
{
public:
	CSpecialFlags() = default;

	//member properties
	CComboBox			CCBVisceroids; // 92
	CComboBox			CCBTiberiumSpreads; // 152
	CComboBox			CCBTiberiumGrows; // 212
	CComboBox			CCBTiberiumExplosive; // 272
	CComboBox			CCBMeteorites; // 332
	CComboBox			CCBMCVDeploy; // 392
	CComboBox			CCBIonStorms; // 452
	CComboBox			CCBInitialVeteran; // 512
	CComboBox			CCBInert; // 572
	CComboBox			CCBHarvesterImmune; // 632
	CComboBox			CCBFogOfWar; // 692
	CComboBox			CCBFixedAlliance; // 752
	CComboBox			CCBDestoryableBridges; // 812

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4DBDD0);
	}
};