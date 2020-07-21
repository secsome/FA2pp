#pragma once

#include "FA2PP.h"

class NOVTABLE CHouses : public FA2CDialog
{
public:
	CHouses() = default;

	//member properties
	CComboBox  CCBHumanHouse; // 92
	CComboBox  CCBTechLevel; // 152
	CComboBox  CCBCountry; //212
	CComboBox  CCBPlayerControl; // 272
	CComboBox  CCBPercentBuilt; // 332
	CComboBox  CCBNodeCount; // 392
	CComboBox  CCBIQ; // 452
	CComboBox  CCBEdge; // 512
	CEdit				CETCredits; // 572
	CComboBox  CCBColor; // 632
	CEdit				CETAllies; // 692
	CComboBox  CCBActsLike; // 752
	CComboBox	CCBHouses; // 812
};