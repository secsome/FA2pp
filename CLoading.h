#pragma once

#include "FA2PP.h"

// Forward Definations
class INIClass;

class NOVTABLE CLoading : public FA2CDialog
{
public:
	CLoading(FA2CWnd* pParentWnd)
	{
		JMP_THIS(0x479A40);
	}

	static CLoading* const Instance;

	//member properties
	char		TheaterIdentifier; // T, A(SNOW), U, N, D, L
	char		gap_93[3];
	CStatic		CSCVersion; // 96
	CStatic		CSCBuiltby; // 156
	CStatic		CSCLoading; // 216
	CProgressCtrl	CPCProgress; // 276
	char gap[120];
	char wtfgap[101][120];
	char fuckgap[400];

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x479C70);
	}

	void LoadTSINI(const char* pFile, INIClass* pINI, BOOL bMerge)
	{
		JMP_THIS(0x47FFB0);
	}

};

CLoading* const CLoading::Instance = reinterpret_cast<CLoading*>(0x7EE030);