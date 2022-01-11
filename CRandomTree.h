#pragma once

#include "FA2PP.h"

class NOVTABLE CRandomTree : public ppmfc::CDialog
{
public:
	CRandomTree() = default;

	void OnBNToUsedClicked()
	{
		JMP_THIS(0x4D48B0);
	}
	void OnBNToAvailableClicked()
	{
		JMP_THIS(0x4D4960);
	}
	void OnLBAvailableSelectChanged()
	{
		JMP_THIS(0x4D4CB0);
	}
	void OnLBAvailableDoubleClicked()
	{
		JMP_THIS(0x4D4D80);
	}
	void OnLBUsedSelectChanged()
	{
		JMP_THIS(0x4D4E30);
	}
	void OnLBUsedDoubleClicked()
	{
		JMP_THIS(0x4D4F00);
	}
	void OnPaint()
	{
		JMP_THIS(0x4D4FB0);
	}
	//member properties
	CButton		CBNPreviewImage; // 92
	ppmfc::CListBox	CLBUsed; // 152
	ppmfc::CListBox	CLBAvailable; // 212
	ppmfc::CString		CString_Terrain; // 272

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x4D4100); }
};