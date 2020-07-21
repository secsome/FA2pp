#pragma once

#include "FA2PP.h"

class NOVTABLE CBasic : public FA2CDialog
{
public:
	CBasic() = default;

	//member properties
	CComboBox CCBRequiredAddOn; // 92
	CComboBox CCBVeinGrowthEnabled; // 152
	CComboBox CCBTruckCrate; // 212
	CComboBox CCBTrainCrate; // 272
	CComboBox CCBTiberiumGrowthEnabled; // 332
	CComboBox CCBTiberiumDeathToVisceroid; // 392
	CComboBox CCBSkipScore; // 452
	CComboBox CCBSkipMapSelect; // 512
	CComboBox CCBOneTimeOnly; // 572
	CComboBox CCBOfficial; // 632
	CComboBox CCBNextScenario; // 692
	CEdit			   CETPercent; // 752 ?
	CEdit			   CETNewINIFormat; // 812
	CEdit			   CETName; // 872
	CEdit			   CETMultiplayerOnly; // 932
	CEdit			   CETInitTime; // 992
	CComboBox CCBIgnoreGlobalAITriggers; // 1052
	CComboBox CCBIceGrowthEnabled; // 1112
	CComboBox CCBFreeRadar; // 1172
	CComboBox CCBEndOfGame; // 1232
	CEdit			   CETCarryOverCap; // 1292
	CComboBox CCBAltNextScenario; // 1352
};
