#pragma once

#include "FA2PP.h"

class NOVTABLE CSingleplayerSettings : public ppmfc::CDialog
{
public:
	CSingleplayerSettings() = default;

	//member properties
	ppmfc::CComboBox			CCBInheritTimer; // 92
	ppmfc::CComboBox			CCBDropships; // 152
	ppmfc::CComboBox			CCBFillSilos; // 212
	ppmfc::CComboBox			CCBCarryOverMoney; // 272
	ppmfc::CComboBox			CCBMovieWin; // 332
	ppmfc::CComboBox			CCBMoviePremapSelect; // 392
	ppmfc::CComboBox			CCBMoviePostScore; // 452
	ppmfc::CComboBox			CCBMovieLose; // 512
	ppmfc::CComboBox			CCBMovieIntro; // 572
	ppmfc::CComboBox			CCBMovieBrief; // 632
	ppmfc::CComboBox			CCBMovieAction; // 692

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_THIS(0x4D9380);
	}


};