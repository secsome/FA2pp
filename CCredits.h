#pragma once

#include "FA2PP.h"

class NOVTABLE CCredits : public ppmfc::CDialog
{
public:
	CCredits() = default;

	//member properties
	int Unknown_92;
	BOOL DrawHappyFace;
	ppmfc::CStatic	CSCEasterEgg; // 100


	virtual void DoDataExchange(ppmfc::CDataExchange* pDX) override
		{ JMP_THIS(0x41E030); }
};