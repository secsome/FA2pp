#pragma once

// #include "Helpers/CompileTime.h"
#include "FA2PP.h"

// #include "CMixFile.h"

// Forward Definations
class INIClass;
struct t_palet_entry;
class Cmix_file;

struct MixesStruct
{
	Cmix_file* Mix0;
	Cmix_file* Mix1;
	Cmix_file* Mix2;
	Cmix_file* Mix3;
	Cmix_file* Mix4;
	Cmix_file* Mix5;
	Cmix_file* Mix6;
	Cmix_file* Mix7;
	Cmix_file* Mix8;
	Cmix_file* Mix9;
	Cmix_file* Mix10;
	Cmix_file* Mix11;
	Cmix_file* Mix12;
	Cmix_file* Mix13;
	Cmix_file* Mix14;
	Cmix_file* Mix15;
	Cmix_file* Mix16;
	Cmix_file* Mix17;
	Cmix_file* Mix18;
	Cmix_file* Mix19;
	Cmix_file* Mix20;
	Cmix_file* Mix21;
	Cmix_file* Mix22;
	Cmix_file* Mix23;
	Cmix_file* Mix24;
	Cmix_file* Mix25;
	Cmix_file* Mix26;
	Cmix_file* Mix27;
	Cmix_file* Mix28;
	Cmix_file* Mix29;
};

class NOVTABLE CLoading : public FA2CDialog
{
public:
	CLoading() = default;

	CLoading(CWnd* pParentWnd) { JMP_THIS(0x479A40) }

	Cmix_file* SearchFile(const char* pName, char* pUnk = nullptr) { JMP_THIS(0x48A650) }
	void LoadTSINI(const char* pFile, INIClass* pINI, BOOL bMerge) { JMP_THIS(0x47FFB0); }

	//member properties
	char TheaterIdentifier; // T, A(SNOW), U, N, D, L
	char gap_93[3];
	CStatic CSCVersion;
	CStatic CSCBuiltby;
	CStatic CSCLoading;
	CProgressCtrl CPCProgress;
	int Unknown_150;
	int Unknown_154;
	t_palet_entry* PAL_ISOTEM;
	t_palet_entry* PAL_ISOSNO;
	t_palet_entry* PAL_ISOURB;
	t_palet_entry* PAL_UNITTEM;
	t_palet_entry* PAL_UNITSNO;
	t_palet_entry* PAL_UNITURB;
	t_palet_entry* PAL_TEMPERAT;
	t_palet_entry* PAL_SNOW;
	t_palet_entry* PAL_URBAN;
	t_palet_entry* PAL_LIB_ID2124019542;
	t_palet_entry* PAL_LUNAR;
	t_palet_entry* PAL_DESERT;
	t_palet_entry* PAL_URBANN;
	t_palet_entry* PAL_ISOLUN;
	t_palet_entry* PAL_ISODES;
	t_palet_entry* PAL_ISOUBN;
	t_palet_entry* PAL_UNITLUN;
	t_palet_entry* PAL_UNITDES;
	t_palet_entry* PAL_UNITUBN;
	Cmix_file* MIX_LOCAL;
	Cmix_file* MIX_SNO;
	Cmix_file* MIX_TEM;
	Cmix_file* MIX_URB;
	Cmix_file* MIX_LUN;
	Cmix_file* MIX_DES;
	Cmix_file* MIX_UBN;
	Cmix_file* MIX_RA2;
	Cmix_file* MIX_GENERIC;
	MixesStruct xccfield_1C8[101];
	Cmix_file* ECacheMixes[100];
	Cmix_file* MIX_ISOTEM;
	Cmix_file* MIX_ISOSNO;
	Cmix_file* MIX_ISOURB;
	Cmix_file* MIX_ISOGEN;
	Cmix_file* MIX_ISOLUN;
	Cmix_file* MIX_ISODES;
	Cmix_file* MIX_ISOUBN;
	Cmix_file* MIX_TEMPRAT;
	Cmix_file* MIX_SNOW;
	Cmix_file* MIX_URBAN;
	Cmix_file* MIX_URBANN;
	Cmix_file* MIX_LUNAR;
	Cmix_file* MIX_DESERT;
	Cmix_file* MIX_CACHE;
	Cmix_file* MIX_CONQUER;
	Cmix_file* MIX_LANGUAGE;
	Cmix_file* MIX_LANGMD;
	Cmix_file* MIX_MARBLE;
	int Unknown_32F8;

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x479C70);
	}

};