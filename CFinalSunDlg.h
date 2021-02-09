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

#include "GlobalVars.h"

using ObjectBrowserControl = CTreeCtrl;

class NOVTABLE CFinalSunDlg : public FA2CDialog
{
protected:
	void UpdateDialogs_(int a2, int a3)
		{ JMP_THIS(0x4261E0); }
public:
	static void UpdateDialogs(int a2, int a3)
	{
		CFinalSunDlg* dlg = reinterpret_cast<CFinalSunDlg*>(0x7EDF24);
		dlg->UpdateDialogs_(a2, a2);
	}

public:
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
	CMyViewFrame MyViewFrame;
	CSpecialFlags SpecialFlags;
	CLighting Lighting;
	CINIEditor INIEditor;
	CBasic Basic;
	CMapD MapD;
	INIClass INIMap;
	char gap[260];
	ObjectBrowserControl ObjectBrowserView;
	HICON hIcon;
};