#pragma once

#include "FA2PP.h"

#include "CTileSetBrowerFrame.h"
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
#include "UnknownFrameWnd.h"
#include "CSpecialFlags.h"
#include "CLighting.h"
#include "CINIEditor.h"
#include "CBasic.h"
#include "CMapD.h"
#include "CINI.h"

using ObjectBrowserControl = CTreeCtrl;

class NOVTABLE CFinalSunDlg : public FA2CDialog
{
public:
	CFinalSunDlg() = default;

	//member properties
	CTileSetBrowserFrame TileSetBrowserFrame;
	CToolBar ToolBar1;
	CToolBar ToolBar2;
	CToolBar ToolBar3;
	CBrushSize BrushSize;
	CWnd unknown_cwnd_2;
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
	UnknownFrameWnd MainWnd;
	CSpecialFlags SpecialFlags;
	CLighting Lighting;
	CINIEditor INIEditor;
	CBasic Basic;
	CMapD MapD;
	INIClass INIMap;
	char gap[260];
	CTabCtrl ObjectBrowserView;
	HICON hIcon;
};