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
	static constexpr reference<CFinalSunDlg*, 0x7EDF24> const Instance{}; // CFinalSunApp->MainWnd

	static constexpr reference<bool, 0x7EE07C> const SomeSettingConfigReadingLock{};
	static constexpr reference<bool, 0x7EE080> const ControlKeyIsDown{};

	static constexpr reference<DWORD, 0x7EE084> const LastSucceededOperation{};
	static constexpr reference<DWORD, 0x88403C> const LastSucceededLibraryOperation{};
	static constexpr reference<DWORD, 0x7EE078> const SE2KMODE{};

protected:
	
public:
	void UpdateDialogs(BOOL bSkipUpdateSelf, BOOL bSkipUpdateIsoView) { JMP_THIS(0x4261E0); }
	void SaveMap(LPCSTR lpPath) { JMP_THIS(0x426E50); }
	void Update() { JMP_THIS(0x432010); }
public:
	//member properties
	CTileSetBrowserFrame TileSetBrowserFrame;
	CToolBar ToolBar1;
	CToolBar ToolBar2;
	CToolBar ToolBar3;
	CBrushSize BrushSize;
	CWnd ReBarCtrl;
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
	ObjectBrowserControl ObjectBrowserView;
	HICON hIcon;
};