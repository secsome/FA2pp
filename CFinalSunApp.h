#pragma once

#include "FA2PP.h"

class CFinalSunDlg;
class CLoading;

class NOVTABLE CFinalSunApp : public FA2CWinApp
{
public:
	static constexpr reference<char, 0x72A738, 260> const ExePath{}; // Where FA2.exe locates
	static constexpr reference<char, 0x72A530, 260> const MapPath{}; // Where current map locates 
	static constexpr reference<char, 0x72A634, 260> const FilePath{}; // Where mix files locates

	static constexpr reference<CFinalSunApp, 0x7EDF08> const Instance{};

	CFinalSunDlg* GetDlg() { return reinterpret_cast<CFinalSunDlg*>(this->m_pMainWnd); }

	//member properties
	DWORD Unknown_C0; // never seen it huh
	ppmfc::CString InstallPath; // Will be copied into FilePath at the end of InitInstance
	ppmfc::CString Language; // default to English
	ppmfc::CString RecentFiles[4];
	BOOL FlatToGround;
	BOOL EasyMode;
	BOOL FrameMode;
	BOOL MarbleLoaded;
	BOOL ShowBuildingCells;
	BOOL NoBuildingGraphics;
	BOOL NoInfantryGraphics;
	BOOL NoAircraftGraphics;
	BOOL NoTreeGraphics;
	BOOL NoSnowGraphics;
	BOOL NoTemperateGraphics;
	BOOL NoVehicleGraphics;
	BOOL NoBMPs;
	BOOL NoOverlayGraphics;
	BOOL DisableAutoShore;
	BOOL DisableAutoLat;
	BOOL NoSounds;
	BOOL DisableSlopeCorrection;
	BOOL FileSearchLikeTS;
	CLoading* Loading;
	UINT ClipboardFormat;
	HACCEL AccTable;

	CFinalSunDlg* GetDialog() { return (CFinalSunDlg*)this->m_pMainWnd; }
	CLoading* GetLoading() { return this->Loading; }
};