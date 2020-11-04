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

	virtual BOOL OnInitDialog() override
	{
		JMP_THIS(0x4D8D20);
	}

	virtual void DoDataExchange(CDataExchange* pDX)
	{
		JMP_THIS(0x4D5BE0);
	}

	//
	// Controls
	//

	virtual void OnCBCurrentScriptSelectChanged()
	{
		JMP_THIS(0x4D61B0);
	}

	virtual void OnLBScriptActionsSelectChanged()
	{
		JMP_THIS(0x4D6500);
	}

	virtual void OnETScriptNameChanged()
	{
		JMP_THIS(0x4D6770);
	}

	virtual void OnCBCurrentActionEditChanged()
	{
		JMP_THIS(0x4D6A10);
	}

	virtual void OnCBCurrentActionSelectChanged()
	{
		JMP_THIS(0x4D75D0);
	}

	virtual void OnCBScriptParameterEditChanged()
	{
		JMP_THIS(0x4D7670);
	}

	virtual void OnCBScriptParameterSelectChanged()
	{
		JMP_THIS(0x4D7A50);
	}

	virtual void OnBNAddActionClicked()
	{
		JMP_THIS(0x4D7AC0);
	}

	virtual void OnBNDeleteActionClicked()
	{
		JMP_THIS(0x4D7DD0);
	}

	virtual void OnBNAddScriptClicked()
	{
		JMP_THIS(0x4D8390);
	}

	virtual void OnBNDeleteScriptClicked()
	{
		JMP_THIS(0x4D8730);
	}
};
