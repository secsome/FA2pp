#pragma once

#include "FA2PP.h"

class NOVTABLE CINIEditorImport : public ppmfc::CDialog
{
public:
	CINIEditorImport() = default;

	//member properties
	ppmfc::CString	INIPath;
	ppmfc::CListBox	CLBAvailableSections;
	unsigned short SectionCount;

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4513D0);
	}
};