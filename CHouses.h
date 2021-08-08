#pragma once

#include "FA2PP.h"

class NOVTABLE CHouses : public FA2CDialog
{
public:
	CHouses() = default;

	//member properties
	ppmfc::CComboBox  CCBHumanHouse; // 92
	ppmfc::CComboBox  CCBTechLevel; // 152
	ppmfc::CComboBox  CCBCountry; //212
	ppmfc::CComboBox  CCBPlayerControl; // 272
	ppmfc::CComboBox  CCBPercentBuilt; // 332
	ppmfc::CComboBox  CCBNodeCount; // 392
	ppmfc::CComboBox  CCBIQ; // 452
	ppmfc::CComboBox  CCBEdge; // 512
	ppmfc::CEdit	  CETCredits; // 572
	ppmfc::CComboBox  CCBColor; // 632
	ppmfc::CEdit	  CETAllies; // 692
	ppmfc::CComboBox  CCBActsLike; // 752
	ppmfc::CComboBox  CCBHouses; // 812
};