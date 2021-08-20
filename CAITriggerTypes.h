#pragma once

#include "FA2PP.h"

class NOVTABLE CAITriggerTypes : public FA2CDialog
{
public:
	CAITriggerTypes() = default;

	//member properties
	ppmfc::CComboBox	CCBTeam1; // 92
	ppmfc::CComboBox	CCBComparisonObject; // 152
	ppmfc::CComboBox	CCBTeam2; // 212
	ppmfc::CComboBox	CCBConditionType; // 272
	ppmfc::CComboBox	CCBTechLevel; // 332
	ppmfc::CComboBox	CCBData; // 392 Useless
	ppmfc::CComboBox	CCBOwnerHouse; // 452
	CEdit				CETPercentageMax; // 512
	CEdit				CETPercentageMin; // 572
	CEdit				CETPercentageNormal; // 632
	ppmfc::CComboBox  CCBAITriggerList; // 692
	INT				Unknown_752; // As u see, there should be nothing :/ Fill 752 - 756
	ppmfc::CString			CString_MinDiff; // 756 Useless
	ppmfc::CString			CString_Name; // 760
	BYTE				Unknown_764[16]; // As u see, there should be nothing :/ Fill 764 - 780
	BOOL			BOOL_Allowed; // 780
	INT				INT_CCBComparator_Index; // 784
	INT				CETComparatorNum; // 788 Range From 0 - 256
	BOOL			BOOL_Easy; // 792
	BOOL			BOOL_Medium; // 796
	BOOL			BOOL_Hard; // 800
	BOOL			BOOL_BaseDefense; // 804
	BOOL			BOOL_AvailableInSkirmish; // 808
	INT				Unknown_812; // As u see, there should be nothing :/ Fill 812 - 816
	ppmfc::CString			CString_MultiHouse; // 816
};