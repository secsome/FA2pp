#pragma once

#include "FA2PP.h"

class NOVTABLE CRandomTree : public FA2CDialog
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
	CListBox	CLBUsed; // 152
	CListBox	CLBAvailable; // 212
	ppmfc::CString		CString_Terrain; // 272

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4D4100);
	}
};