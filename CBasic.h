#pragma once

#include "FA2PP.h"

class NOVTABLE CBasic : public FA2CDialog
{
public:
	CBasic() = default;

	//member properties
	ppmfc::CComboBox CCBRequiredAddOn; // 92
	ppmfc::CComboBox CCBVeinGrowthEnabled; // 152
	ppmfc::CComboBox CCBTruckCrate; // 212
	ppmfc::CComboBox CCBTrainCrate; // 272
	ppmfc::CComboBox CCBTiberiumGrowthEnabled; // 332
	ppmfc::CComboBox CCBTiberiumDeathToVisceroid; // 392
	ppmfc::CComboBox CCBSkipScore; // 452
	ppmfc::CComboBox CCBSkipMapSelect; // 512
	ppmfc::CComboBox CCBOneTimeOnly; // 572
	ppmfc::CComboBox CCBOfficial; // 632
	ppmfc::CComboBox CCBNextScenario; // 692
	ppmfc::CEdit			   CETPercent; // 752 ?
	ppmfc::CEdit			   CETNewINIFormat; // 812
	ppmfc::CEdit			   CETName; // 872
	ppmfc::CEdit			   CETMultiplayerOnly; // 932
	ppmfc::CEdit			   CETInitTime; // 992
	ppmfc::CComboBox CCBIgnoreGlobalAITriggers; // 1052
	ppmfc::CComboBox CCBIceGrowthEnabled; // 1112
	ppmfc::CComboBox CCBFreeRadar; // 1172
	ppmfc::CComboBox CCBEndOfGame; // 1232
	ppmfc::CEdit			   CETCarryOverCap; // 1292
	ppmfc::CComboBox CCBAltNextScenario; // 1352
};
