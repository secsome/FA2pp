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

	virtual void OnScriptSelChanged()
	{
		JMP_THIS(0x4D61B0);
	}

	virtual void OnActionSelChanged()
	{
		JMP_THIS(0x4D6500);
	}

	virtual void OnScriptSelUpdateName()
	{
		JMP_THIS(0x4D6770);
	}

	virtual void OnParamConvert()
	{
		JMP_THIS(0x4D6A10);
	}

	virtual void OnParamEntered()
	{
		JMP_THIS(0x4D75D0);
	}

	virtual void OnUpdateAction()
	{
		JMP_THIS(0x4D7670);
	}

	virtual void OnParamValidation()
	{
		JMP_THIS(0x4D7A50);
	}

	virtual void OnNameUpdate() // maybe?
	{
		JMP_THIS(0x4D7AC0);
	}

	virtual void OnHandleAction() // delete / add?
	{
		JMP_THIS(0x4D7DD0);
	}

	virtual void OnLoadMapScripts()
	{
		JMP_THIS(0x4D8390);
	}

	virtual void OnDeleteScript()
	{
		JMP_THIS(0x4D8730);
	}
};
