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

class NOVTABLE CFinalSunDlg : public ppmfc::CDialog
{
public:
	static constexpr reference<CFinalSunDlg*, 0x7EDF24> const Instance{}; // CFinalSunApp->MainWnd

	static constexpr reference<bool, 0x7EE07C> const SomeSettingConfigReadingLock{};

	static constexpr reference<DWORD, 0x7EE084> const LastSucceededOperation{};
	static constexpr reference<DWORD, 0x88403C> const LastSucceededLibraryOperation{};
	static constexpr reference<BOOL, 0x7EE078> const SE2KMODE{};

protected:
	
public:
	CFinalSunDlg(ppmfc::CWnd* pParentWnd) { JMP_THIS(0x423B40); }
	~CFinalSunDlg() { JMP_THIS(0x422070); }

	virtual int DoModal() override { JMP_THIS(0x435270); }
	void UpdateDialogs(BOOL bSkipUpdateSelf, BOOL bSkipUpdateIsoView) { JMP_THIS(0x4261E0); }
	void SaveMap(LPCSTR lpPath) { JMP_THIS(0x426E50); }
	void Update() { JMP_THIS(0x432010); }
	void LoadMap(LPCSTR lpPath) { JMP_THIS(0x4374B0); }
	void Settings() { JMP_THIS(0x43D0E0); }
	enum class FASoundType { Normal = 1, Error, Warning };
	void __cdecl PlaySound(FASoundType eSound) { JMP_STD(0x43CE00); }
public:
	//member properties
	DECLARE_PROPERTY(CTileSetBrowserFrame, TileSetBrowserFrame);
	DECLARE_PROPERTY(CToolBar, ToolBar1);
	DECLARE_PROPERTY(CToolBar, ToolBar2);
	DECLARE_PROPERTY(CToolBar, ToolBar3);
	DECLARE_PROPERTY(CBrushSize, BrushSize);
	DECLARE_PROPERTY(ppmfc::CWnd, ReBarCtrl);
	DECLARE_PROPERTY(CSingleplayerSettings, SingleplayerSettings);
	DECLARE_PROPERTY(CAITriggerTypes, AITriggerTypes);
	DECLARE_PROPERTY(CAITriggerTypesEnable ,AITriggerTypesEnable);
	DECLARE_PROPERTY(CScriptTypes ,ScriptTypes);
	char COldTriggerEditor[1112]; // I just don't want to analyse it, for it's obsoluted
	DECLARE_PROPERTY(CTriggerFrame ,TriggerFrame);
	DECLARE_PROPERTY(CTags ,Tags);
	DECLARE_PROPERTY(CTaskForce ,TaskForce);
	DECLARE_PROPERTY(CTeamTypes ,TeamTypes);
	DECLARE_PROPERTY(CHouses ,Houses);
	DECLARE_PROPERTY(CSplitterWnd ,SplitterWnd);
	DECLARE_PROPERTY(CMyViewFrame ,MyViewFrame);
	DECLARE_PROPERTY(CSpecialFlags ,SpecialFlags);
	DECLARE_PROPERTY(CLighting ,Lighting);
	DECLARE_PROPERTY(CINIEditor ,INIEditor);
	DECLARE_PROPERTY(CBasic ,Basic);
	DECLARE_PROPERTY(CMapD ,MapD);
	DECLARE_PROPERTY(CINI ,INIMap);
	DECLARE_PROPERTY(CViewObjects, ViewObjects);
	DECLARE_PROPERTY(HICON ,hIcon);
};