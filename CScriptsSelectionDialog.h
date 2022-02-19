#pragma once

#include "FA2PP.h"

// FAScript related dialog

enum class ScriptParamType : int
{
	Houses = 0,
	Countries,
	Triggers,
	Tags,
	IndexedHouses,
	IndexedCountries,
	CustomData
};

class CScriptsSelectionDialog : public ppmfc::CDialog // Dialog 289, don't know where uses
{
public:
	//member properties
	ScriptParamType Param;
	int Unknown_96;
	const char** FirstString;
	const char** LastString;
	int Unknown_108;
	BOOL TrimIndex;
	ppmfc::CString CString_CaptainText;
	ppmfc::CString CString_ComboData;

	CScriptsSelectionDialog(int nUnknown96) { JMP_THIS(0x41DBC0); }
	~CScriptsSelectionDialog() { JMP_THIS(0x41DC80); }

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x41DD20); }
};