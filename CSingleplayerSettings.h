#pragma once

#include "FA2PP.h"

class NOVTABLE CSingleplayerSettings : public FA2CDialog
{
public:
	CSingleplayerSettings() = default;

	//member properties
	CComboBox			CCBInheritTimer; // 92
	CComboBox			CCBDropships; // 152
	CComboBox			CCBFillSilos; // 212
	CComboBox			CCBCarryOverMoney; // 272
	CComboBox			CCBMovieWin; // 332
	CComboBox			CCBMoviePremapSelect; // 392
	CComboBox			CCBMoviePostScore; // 452
	CComboBox			CCBMovieLose; // 512
	CComboBox			CCBMovieIntro; // 572
	CComboBox			CCBMovieBrief; // 632
	CComboBox			CCBMovieAction; // 692

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4D9380);
	}
};