#pragma once

#include "FA2PP.h"

class NOVTABLE CTaskForce : public FA2CDialog
{
public:
	void OnCBCurrentTaskforceEditChanged()
	{
		JMP_THIS(0x448C20);
	}
	void OnCBCurrentTaskforceSelectChanged()
	{
		JMP_THIS(0x4E2DA0);
	}
	void OnLBMembersSelectChanged()
	{
		JMP_THIS(0x4E3270);
	}
	void OnBNDeleteMemberClicked()
	{
		JMP_THIS(0x4E3690);
	}
	void OnETMemberCountEditChanged()
	{
		JMP_THIS(0x4E3B00);
	}
	void OnETCurrentTaskforceEditChanged()
	{
		JMP_THIS(0x4E3F00);
	}
	void OnCBMemberTypeEditChanged()
	{
		JMP_THIS(0x4E41A0);
	}
	void OnCBMemberTypeSelectChanged()
	{
		JMP_THIS(0x4E4540);
	}
	void OnBNAddMemberClicked()
	{
		JMP_THIS(0x4E48A0);
	}
	void OnBNDeleteTaskforceClicked()
	{
		JMP_THIS(0x4E4C60);
	}
	void OnBNAddTaskforce()
	{
		JMP_THIS(0x4E50B0);
	}
	void OnETGroupEditChanged()
	{
		JMP_THIS(0x4E5550);
	}

	//member properties
	CComboBox		CCBMemberType;
	CListBox		CLBMembers;
	CComboBox		CCBCurrentTaskforce;
	ppmfc::CString			CString_Group;
	ppmfc::CString			CString_Name;
	ppmfc::CString			CString_Num;
};