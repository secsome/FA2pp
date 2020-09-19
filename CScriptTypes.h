#pragma once

#include "FA2PP.h"

#include <AFXOLE.H>

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
};
