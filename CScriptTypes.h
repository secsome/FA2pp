#pragma once

#include "FA2PP.h"

class NOVTABLE CScriptTypes : public FA2CDialog
{
public:
	CScriptTypes() = default;

	//member properties
	CEdit				CETDescription; // 92
	CStatic			CSTParameterOfSection; // 152
	CComboBox	CCBCurrentAction; // 212
	CComboBox	CCBCurrentScript; // 272
	CComboBox	CCBScriptParameter; // 332
	CListBox		CLBScriptActions; // 392
	CString			CString_ScriptName; // 452

public:

	BOOL OnInitDialog() override
	{
		JMP_THIS(0x4D8D20);
	}

	void DoDataExchange(CDataExchange* pDX)
	{
		JMP_THIS(0x4D5BE0);
	}

	void UpdateDialog()
	{
		JMP_THIS(0x4262C6);
	}

	//
	// Controls
	//

	void OnCBCurrentScriptSelectChanged()
	{
		JMP_THIS(0x4D61B0);
	}

	void OnLBScriptActionsSelectChanged()
	{
		JMP_THIS(0x4D6500);
	}

	void OnETScriptNameChanged()
	{
		JMP_THIS(0x4D6770);
	}

	void OnCBCurrentActionEditChanged()
	{
		JMP_THIS(0x4D6A10);
	}

	void OnCBCurrentActionSelectChanged()
	{
		JMP_THIS(0x4D75D0);
	}

	void OnCBScriptParameterEditChanged()
	{
		JMP_THIS(0x4D7670);
	}

	void OnCBScriptParameterSelectChanged()
	{
		JMP_THIS(0x4D7A50);
	}

	void OnBNAddActionClicked()
	{
		JMP_THIS(0x4D7AC0);
	}

	void OnBNDeleteActionClicked()
	{
		JMP_THIS(0x4D7DD0);
	}

	void OnBNAddScriptClicked()
	{
		JMP_THIS(0x4D8390);
	}

	void OnBNDeleteScriptClicked()
	{
		JMP_THIS(0x4D8730);
	}
};
