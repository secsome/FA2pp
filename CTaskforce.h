#pragma once

#include "FA2PP.h"

class NOVTABLE CTaskForce : public FA2CDialog
{
public:
	CTaskForce() = default;

	void UpdateMemberType()
	{
		JMP_THIS(0x4E1A10);
	}

	//event handlers
	void OnMemberEditChanged()
	{
		JMP_THIS(0x4E41A0);
	}

	//member properties
	CComboBox	CCBMemberType;
	CListBox		CLBItems;
	CComboBox	CCBTaskType;
	CString			CString_Group;
	CString			CString_Name;
	CString			CString_Num;
};