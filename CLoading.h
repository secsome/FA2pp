#pragma once

#include "FA2PP.h"

// #include "CMixFile.h"

// #include "Helpers/CompileTime.h"

// Forward Definations
class INIClass;
class Palette;
class CMixFile;
struct MixesStruct
{
	CMixFile* Mix0;
	CMixFile* Mix1;
	CMixFile* Mix2;
	CMixFile* Mix3;
	CMixFile* Mix4;
	CMixFile* Mix5;
	CMixFile* Mix6;
	CMixFile* Mix7;
	CMixFile* Mix8;
	CMixFile* Mix9;
	CMixFile* Mix10;
	CMixFile* Mix11;
	CMixFile* Mix12;
	CMixFile* Mix13;
	CMixFile* Mix14;
	CMixFile* Mix15;
	CMixFile* Mix16;
	CMixFile* Mix17;
	CMixFile* Mix18;
	CMixFile* Mix19;
	CMixFile* Mix20;
	CMixFile* Mix21;
	CMixFile* Mix22;
	CMixFile* Mix23;
	CMixFile* Mix24;
	CMixFile* Mix25;
	CMixFile* Mix26;
	CMixFile* Mix27;
	CMixFile* Mix28;
	CMixFile* Mix29;
};
class NOVTABLE CLoading : public FA2CDialog
{
public:
	CLoading() = default;

	// static constexpr constant_ptr<CLoading, 0x7EE030> Instance{};

	CLoading(FA2CWnd* pParentWnd)
	{
		JMP_THIS(0x479A40);
	}

	//member properties
	char TheaterIdentifier; // T, A(SNOW), U, N, D, L
	char gap_93[3];
	CStatic CSCVersion;
	CStatic CSCBuiltby;
	CStatic CSCLoading;
	CProgressCtrl CPCProgress;
	int Unknown_150;
	int Unknown_154;
	Palette* PAL_ISOTEM;
	Palette* PAL_ISOSNO;
	Palette* PAL_ISOURB;
	Palette* PAL_UNITTEM;
	Palette* PAL_UNITSNO;
	Palette* PAL_UNITURB;
	Palette* PAL_TEMPERAT;
	Palette* PAL_SNOW;
	Palette* PAL_URBAN;
	Palette* PAL_LIB_ID2124019542;
	Palette* PAL_LUNAR;
	Palette* PAL_DESERT;
	Palette* PAL_URBANN;
	Palette* PAL_ISOLUN;
	Palette* PAL_ISODES;
	Palette* PAL_ISOUBN;
	Palette* PAL_UNITLUN;
	Palette* PAL_UNITDES;
	Palette* PAL_UNITUBN;
	CMixFile* MIX_LOCAL;
	CMixFile* MIX_SNO;
	CMixFile* MIX_TEM;
	CMixFile* MIX_URB;
	CMixFile* MIX_LUN;
	CMixFile* MIX_DES;
	CMixFile* MIX_UBN;
	CMixFile* MIX_RA2;
	CMixFile* MIX_GENERIC;
	MixesStruct xccfield_1C8[101];
	CMixFile* ECacheMixes[100];
	CMixFile* MIX_ISOTEM;
	CMixFile* MIX_ISOSNO;
	CMixFile* MIX_ISOURB;
	CMixFile* MIX_ISOGEN;
	CMixFile* MIX_ISOLUN;
	CMixFile* MIX_ISODES;
	CMixFile* MIX_ISOUBN;
	CMixFile* MIX_TEMPRAT;
	CMixFile* MIX_SNOW;
	CMixFile* MIX_URBAN;
	CMixFile* MIX_URBANN;
	CMixFile* MIX_LUNAR;
	CMixFile* MIX_DESERT;
	CMixFile* MIX_CACHE;
	CMixFile* MIX_CONQUER;
	CMixFile* MIX_LANGUAGE;
	CMixFile* MIX_LANGMD;
	CMixFile* MIX_MARBLE;
	int Unknown_32F8;

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x479C70);
	}

	void LoadTSINI(const char* pFile, INIClass* pINI, BOOL bMerge)
	{
		JMP_THIS(0x47FFB0);
	}

};