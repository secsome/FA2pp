#pragma once

#include "FA2PP.h"

// Forward Definations
class CINI;

struct ExpandMixStruct
{
	int Parent;
	int Ecache01;
	int Conquer;
	int Local;
	int IsoSnowmd;
	int IsoTempmd;
	int IsoUrbmd;
	int IsoGen;
	int IsoLun;
	int IsoDes;
	int IsoUbn;
	int IsoGenmd;
	int IsoLunmd;
	int IsoDesmd;
	int IsoUbnmd;
	int Temperatmd;
	int Snowmd;
	int Urbanmd;
	int Lunarmd;
	int Urbannmd;
	int Desertmd;
	int Genericmd;
	int Temmd;
	int Snomd;
	int Urbmd;
	int Ubn;
	int Lun;
	int Des;
	int Unknown;
	int Marblemd;
};

class Palette;

class NOVTABLE CLoading : public FA2CDialog
{
public:
	static constexpr reference<CLoading*, 0x7EE030> const Instance{};

	static constexpr reference<bool, 0x5D32AC> const HasMdFile{};

	CLoading() = default;

	CLoading(CWnd* pParentWnd) { JMP_THIS(0x479A40) }

	//Returns : The index of mixfile in the global array, 0 for not found.
	//pTheaterType:
	// 0 : Not a specific theater
	// 1 - 6 : TEM SNO URB UBN LUN DES
	int SearchFile(const char* pName, char* pTheaterType = nullptr) { JMP_THIS(0x48A650) }
	void LoadTSINI(const char* pFile, CINI* pINI, BOOL bMerge) { JMP_THIS(0x47FFB0) }
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
			// Ares code here
			char c0 = string[0];
			char c1 = string[1] & ~0x20; // evil hack to uppercase
			if (isalpha(static_cast<unsigned char>(c0))) {
				if (c1 == 'A' || c1 == 'T') {
					string.SetAt(1, this->TheaterIdentifier);
				}
			}
			/* WW code here
			char f = string[0], s = string[1];
			if (f >= 'A' && f <= 'Z')	f += ' ';
			if (s >= 'A' && s <= 'Z')	s += ' ';
			if ((f == 'g' || f == 'n' || f == 'c' || f == 'y') && (s == 'a' || s == 't'))
				string.SetAt(1, this->TheaterIdentifier);
			*/
		}
	}
	void SetGenericTheaterLetter(ppmfc::CString& string)
	{
		string.SetAt(1, 'G');
	}

	static bool __cdecl IsFileExists(ppmfc::CString lpFileName) { JMP_STD(0x43D920); }

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
	int MIX_LOCAL;
	int MIX_SNO;
	int MIX_TEM;
	int MIX_URB;
	int MIX_LUN;
	int MIX_DES;
	int MIX_UBN;
	int MIX_RA2;
	int MIX_GENERIC;
	ExpandMixStruct ExpandMixes[101];
	int ECacheMixes[100];
	int MIX_ISOTEM;
	int MIX_ISOSNO;
	int MIX_ISOURB;
	int MIX_ISOGEN;
	int MIX_ISOLUN;
	int MIX_ISODES;
	int MIX_ISOUBN;
	int MIX_TEMPRAT;
	int MIX_SNOW;
	int MIX_URBAN;
	int MIX_URBANN;
	int MIX_LUNAR;
	int MIX_DESERT;
	int MIX_CACHE;
	int MIX_CONQUER;
	int MIX_LANGUAGE;
	int MIX_LANGMD;
	int MIX_MARBLE;
	int Unknown_32F8;

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x479C70);
	}

};