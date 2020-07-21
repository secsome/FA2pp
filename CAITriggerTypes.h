#pragma once

#include "FA2PP.h"

class NOVTABLE CAITriggerTypes : public FA2CDialog
{
public:
	CAITriggerTypes() = default;

	//member properties
	CComboBox	CCBTeam1; // 92
	CComboBox	CCBComparisonObject; // 152
	CComboBox	CCBTeam2; // 212
	CComboBox	CCBConditionType; // 272
	CComboBox	CCBTechLevel; // 332
	CComboBox	CCBData; // 392 Useless
	CComboBox	CCBOwnerHouse; // 452
	CEdit				CETPercentageMax; // 512
	CEdit				CETPercentageMin; // 572
	CEdit				CETPercentageNormal; // 632
	CComboBox  CCBAITriggerList; // 692
	INT				Unknown_752; // As u see, there should be nothing :/ Fill 752 - 756
	CString			CString_MinDiff; // 756 Useless
	CString			CString_Name; // 760
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
	CString			CString_MultiHouse; // 816
};