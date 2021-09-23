#pragma once

#include "FA2PP.h"

#include "CTileSetBrowserFrame.h"
#include "CBrushSize.h"
#include "CSingleplayerSettings.h"
#include "CAITriggerTypes.h"
#include "CAITriggerTypesEnable.h"
#include "CScriptTypes.h"
#include "CTriggerFrame.h"
#include "CTags.h"
#include "CTaskforce.h"
#include "CTeamTypes.h"
#include "CHouses.h"
#include "CMyViewFrame.h"
#include "CSpecialFlags.h"
#include "CLighting.h"
#include "CINIEditor.h"
#include "CBasic.h"
#include "CMapD.h"
#include "CINI.h"

class NOVTABLE CFinalSunDlg : public FA2CDialog
{
public:
	static constexpr reference<CFinalSunDlg*, 0x7EDF24> const Instance{};

	static constexpr reference<bool, 0x7EDFE4> const FlatToGround{};
	static constexpr reference<bool, 0x7EDFE8> const EasyMode{};
	static constexpr reference<bool, 0x7EDFEC> const FrameMode{};
	static constexpr reference<bool, 0x7EDFF0> const MarbleLoaded{};
	static constexpr reference<bool, 0x7EDFF4> const ShowBuildingCells{};
	static constexpr reference<bool, 0x7EDFF8> const NoBuildingGraphics{};
	static constexpr reference<bool, 0x7EDFFC> const NoInfantryGraphics{};
	static constexpr reference<bool, 0x7ED000> const NoAircraftGraphics{};
	static constexpr reference<bool, 0x7EE004> const NoTreeGraphics{};
	static constexpr reference<bool, 0x7EE008> const NoSnowGraphics{};
	static constexpr reference<bool, 0x7EE00C> const NoTemperateGraphics{};
	static constexpr reference<bool, 0x7EE010> const NoVehicleGraphics{};
	static constexpr reference<bool, 0x7EE014> const NoBMPs{};
	static constexpr reference<bool, 0x7EE018> const NoOverlayGraphics{};
	static constexpr reference<bool, 0x7EE01C> const DisableAutoShore{};
	static constexpr reference<bool, 0x7EE020> const DisableAutoLat{};
	static constexpr reference<bool, 0x7EE024> const NoSounds{};
	static constexpr reference<bool, 0x7EE028> const DisableSlopeCorrection{};
	static constexpr reference<bool, 0x7EE02C> const FileSearchLikeTS{};

	static constexpr reference<bool, 0x7EE07C> const SomeSettingConfigReadingLock{};
	static constexpr reference<bool, 0x7EE080> const ControlKeyIsDown{};

	static constexpr reference<DWORD, 0x7EE084> const LastSucceededOperation{};
	static constexpr reference<DWORD, 0x88403C> const LastSucceededLibraryOperation{};
	static constexpr reference<DWORD, 0x7EE078> const SE2KMODE{};

protected:
	void UpdateDialogs_(int a2, int a3)
		{ JMP_THIS(0x4261E0); }
public:
	static void UpdateDialogs(int a2, int a3)
	{
		CFinalSunDlg* dlg = reinterpret_cast<CFinalSunDlg*>(0x7EDF24);
		dlg->UpdateDialogs_(a2, a2);
	}

	void SaveMap(LPCSTR lpPath) { JMP_THIS(0x426E50); }
	void Update() { JMP_THIS(0x432010); }
public:
	//member properties
	CTileSetBrowserFrame TileSetBrowserFrame;
	CToolBar ToolBar1;
	CToolBar ToolBar2;
	CToolBar ToolBar3;
	CBrushSize BrushSize;
	CWnd Unknown_CWnd;
	CSingleplayerSettings SingleplayerSettings;
	CAITriggerTypes AITriggerTypes;
	CAITriggerTypesEnable AITriggerTypesEnable;
	CScriptTypes ScriptTypes;
	char COldTriggerEditor[1112]; // I just don't want to analyse it, for it's obsoluted
	CTriggerFrame TriggerFrame;
	CTags Tags;
	CTaskForce TaskForce;
	CTeamTypes TeamTypes;
	CHouses Houses;
	CSplitterWnd SplitterWnd;
	CMyViewFrame MyViewFrame;
	CSpecialFlags SpecialFlags;
	CLighting Lighting;
	CINIEditor INIEditor;
	CBasic Basic;
	CMapD MapD;
	CINI INIMap;
	char gap[256];
	ObjectBrowserControl ObjectBrowserView;
	HICON hIcon;
};