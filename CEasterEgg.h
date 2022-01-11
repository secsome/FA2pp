#pragma once

#include "FA2PP.h"

class NOVTABLE CGamePanel : public ppmfc::CStatic
{
public:
	CGamePanel() { JMP_THIS(0x41E890); }
	virtual ~CGamePanel() override { JMP_THIS(0x41E8D0); }

	enum BlockType : int
	{
		None = 0x0,
		Player = 0x1,
		Computer = 0x2
	};

	BlockType Map[9];
	bool CanPlayerPlace;

	BlockType& GetBlock(int X, int Y) { return this->Map[3 * X + Y]; }

	void AI() { JMP_THIS(0x41ECA0); }
	void OnPaint() { JMP_THIS(0x41E9A0); }
	void OnLButtonDown(UINT nFlags, int X, int Y) { JMP_THIS(0x41E8F0); }
};

class NOVTABLE CEasterEgg : public ppmfc::CDialog
{
public:
	CEasterEgg() = default;

	//member properties
	CGamePanel GamePanel;

	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x41E7E0); }
};