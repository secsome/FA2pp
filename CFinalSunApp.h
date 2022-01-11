#pragma once

#include "FA2PP.h"

class CFinalSunDlg;
class CLoading;

class NOVTABLE CFinalSunApp : public ppmfc::CWinApp
{
public:
	static constexpr reference<char, 0x72A738, 260> const ExePath{}; // Where FA2.exe locates
	static constexpr reference<char, 0x72A530, 260> const MapPath{}; // Where current map locates 
	static constexpr reference<char, 0x72A634, 260> const FilePath{}; // Where mix files locates

	static constexpr reference<CFinalSunApp, 0x7EDF08> const Instance{};

	CFinalSunApp() _PPMFC_THISCALL(0x41F720);

	// virtual functions
	virtual ~CFinalSunApp() override _PPMFC_THISCALL(0x41FA40);

	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, ppmfc::AFX_CMDHANDLERINFO* pHandlerInfo) override
		_PPMFC_THISCALL(0x422F60);

	virtual const ppmfc::AFX_MSGMAP* GetMessageMap() const override
		_PPMFC_THISCALL(0x41F710);

	virtual BOOL InitInstance() override
		_PPMFC_THISCALL(0x41FAD0);

	virtual int Run() override
		_PPMFC_THISCALL(0x4229D0);

	virtual BOOL PreTranslateMessage(MSG* pMsg) override
		_PPMFC_THISCALL(0x422F20);

	virtual BOOL OnIdle(LONG lCount) override
		_PPMFC_THISCALL(0x422F80);

	virtual LRESULT ProcessWndProcException(ppmfc::CException* e, const MSG* pMsg) override
		_PPMFC_THISCALL(0x422F00);

	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg) override
		_PPMFC_THISCALL(0x4229E0);

	// normal functions
	CFinalSunDlg* GetDialog() { return (CFinalSunDlg*)this->m_pMainWnd; }

	CLoading* GetLoading() { return this->Loading; }

public:
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
};