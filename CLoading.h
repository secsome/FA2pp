#pragma once

// #include "Helpers/CompileTime.h"
#include "FA2PP.h"

// #include "CMixFile.h"

// Forward Definations
class INIClass;
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

class Palette;

class NOVTABLE CLoading : public FA2CDialog
{
public:
	CLoading() = default;

	CLoading(CWnd* pParentWnd) { JMP_THIS(0x479A40) }

	int SearchFile(const char* pName, char* pUnk = nullptr) { JMP_THIS(0x48A650) }
	void LoadTSINI(const char* pFile, INIClass* pINI, BOOL bMerge) { JMP_THIS(0x47FFB0) }
	void GetSHPValidRange(unsigned char* pData, int Width, int Height, int* OutBegin, 
		int* OutEnd, BOOL bUnknown = FALSE, int* pUnknown = nullptr) // Last one is realtived to tmp drawing
		{ JMP_THIS(0x4965B0); }

	void Release() { JMP_THIS(0x491D00); }
	int GetPaletteISO()
	{
		switch (this->TheaterIdentifier)
		{
		case 'A':
			return this->PAL_ISOSNO;
		case 'U':
			return this->PAL_ISOURB;
		case 'N':
			return this->PAL_ISOUBN;
		case 'D':
			return this->PAL_ISODES;
		case 'L':
			return this->PAL_ISOLUN;
		case 'T':
		default:
			return this->PAL_ISOTEM;
		}
	}
	int GetPaletteUnit()
	{
		switch (this->TheaterIdentifier)
		{
		case 'A':
			return this->PAL_UNITSNO;
		case 'U':
			return this->PAL_UNITURB;
		case 'N':
			return this->PAL_UNITUBN;
		case 'D':
			return this->PAL_UNITDES;
		case 'L':
			return this->PAL_UNITLUN;
		case 'T':
		default:
			return this->PAL_UNITTEM;
		}
	}
	int GetPaletteTheater()
	{
		switch (this->TheaterIdentifier)
		{
		case 'A':
			return this->PAL_SNOW;
		case 'U':
			return this->PAL_URBAN;
		case 'N':
			return this->PAL_URBANN;
		case 'D':
			return this->PAL_DESERT;
		case 'L':
			return this->PAL_LUNAR;
		case 'T':
		default:
			return this->PAL_TEMPERAT;
		}
	}
	ppmfc::CString GetFileExtension()
	{
		switch (this->TheaterIdentifier)
		{
		case 'A':
			return ".sno";
		case 'U':
			return ".urb";
		case 'N':
			return ".ubn";
		case 'D':
			return ".des";
		case 'L':
			return ".lun";
		case 'T':
		default:
			return ".tem";
		}
	}
	Palette* GetPalette(int id)
	{
		if (id == PAL_UNITTEM || id == PAL_UNITSNO || id == PAL_UNITURB || 
			id == PAL_UNITUBN || id == PAL_UNITLUN || id == PAL_UNITDES)
			return (Palette*)(0x72B4C4);
		if (id == PAL_ISOTEM || id == PAL_ISOSNO || id == PAL_ISOURB ||
			id == PAL_ISOUBN || id == PAL_ISOLUN || id == PAL_ISODES)
			return (Palette*)(0x72B8C4);
		if (id == PAL_TEMPERAT || id == PAL_SNOW || id == PAL_URBAN ||
			id == PAL_URBANN || id == PAL_LUNAR || id == PAL_DESERT)
			return (Palette*)(0x72ACC4);
		if (id == PAL_LIB_ID2124019542)
			return (Palette*)(0x72A8C4);
		return nullptr;
	}
	void* ReadWholeFile(const char* filename, DWORD* pDwSize = nullptr);
	bool HasFile(ppmfc::CString filename);
	void SetTheaterLetter(ppmfc::CString& string)
	{
		if (this->TheaterIdentifier != 0)
		{
			char f = string[0], s = string[1];
			if (f >= 'A' && f <= 'Z')	f += ' ';
			if (s >= 'A' && s <= 'Z')	s += ' ';
			if ((f == 'g' || f == 'n' || f == 'c' || f == 'y') && (s == 'a' || s == 't'))
				string.SetAt(1, this->TheaterIdentifier);
		}
	}
	void SetGenericTheaterLetter(ppmfc::CString& string)
	{
		string.SetAt(1, 'G');
	}

	//member properties
	char TheaterIdentifier; // T, A(SNOW), U, N, D, L
	//align 3 bytes
	CStatic CSCVersion;
	CStatic CSCBuiltby;
	CStatic CSCLoading;
	CProgressCtrl CPCProgress;
	int Unknown_150;
	int Unknown_154;
	int PAL_ISOTEM; // index in the array at 0x7EDD9C BytePalette[]
	int PAL_ISOSNO;
	int PAL_ISOURB;
	int PAL_UNITTEM;
	int PAL_UNITSNO;
	int PAL_UNITURB;
	int PAL_TEMPERAT;
	int PAL_SNOW;
	int PAL_URBAN;
	int PAL_LIB_ID2124019542;
	int PAL_LUNAR;
	int PAL_DESERT;
	int PAL_URBANN;
	int PAL_ISOLUN;
	int PAL_ISODES;
	int PAL_ISOUBN;
	int PAL_UNITLUN;
	int PAL_UNITDES;
	int PAL_UNITUBN;
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