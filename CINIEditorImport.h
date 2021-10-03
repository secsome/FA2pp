#pragma once

#include "FA2PP.h"

class NOVTABLE CINIEditorImport : public FA2CDialog
{
public:
	CINIEditorImport() = default;

	//member properties
	INT			Unknown_92; // Fill 92 - 96
	ppmfc::CListBox	CLBAvailableSections; // 96

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4513D0);
	}
};