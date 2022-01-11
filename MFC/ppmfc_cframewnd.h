#pragma once

#include "ppmfc_cwnd.h"
#include "ppmfc_objects.h"
#include "ppmfc_cstring.h"

_PPMFC_BEGIN

class COleFrameHook;
class CView;
class CDocument;
class CPrintPreviewState;
class CControlBar;
class CMenu;
class CCmdUI;
class CMiniDockFrameWnd;
class CDockBar;

_PPMFC_CLASS(CFrameWnd) _PPMFC_INHERIT(CWnd)
{
public:    
    CFrameWnd() _PPMFC_THISCALL(0x561704);

    // virtual functions
    virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59CAA0); }

    virtual ~CFrameWnd() override _PPMFC_THISCALL(0x5617E2);

	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) override
		_PPMFC_THISCALL(0x562393);

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override
		_PPMFC_THISCALL(0x561ED1);

	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam) override
		_PPMFC_THISCALL(0x561AB7);

	virtual void BeginModalState() override
		_PPMFC_THISCALL(0x561B4E);

	virtual void EndModalState() override
		_PPMFC_THISCALL(0x561C6A);

	virtual BOOL PreTranslateMessage(MSG* pMsg) override
		_PPMFC_THISCALL(0x5618F4);

	virtual BOOL LoadFrame(UINT nIDResource,
		DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | 0x8000, // FWS_ADDTOTITLE
		CWnd* pParentWnd = NULL,
		CCreateContext* pContext = NULL)
		_PPMFC_THISCALL(0x562128);

	virtual CDocument* GetActiveDocument()
		_PPMFC_THISCALL(0x56297F);

	virtual CFrameWnd* GetActiveFrame()
		_PPMFC_THISCALL(0x563537);

	virtual void GetMessageString(UINT nID, CString& rMessage) const
		_PPMFC_THISCALL(0x562D3A);

	virtual void RecalcLayout(BOOL bNotify = TRUE)
		_PPMFC_THISCALL(0x56353A);

	virtual void ActivateFrame(int nCmdShow = -1)
		_PPMFC_THISCALL(0x563779);

	virtual void OnSetPreviewMode(BOOL bPreview, CPrintPreviewState* pState)
		_PPMFC_THISCALL(0x563299);

	virtual CWnd* GetMessageBar()
		_PPMFC_THISCALL(0x562E6C);

	enum BorderCmd 
		{ borderGet = 1, borderRequest = 2, borderSet = 3 };
	virtual BOOL NegotiateBorderSpace(UINT nBorderCmd, LPRECT lpRectBorder)
		_PPMFC_THISCALL(0x563627);

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
		_PPMFC_THISCALL(0x562025);

	virtual void OnUpdateFrameTitle(BOOL bAddToTitle)
		_PPMFC_THISCALL(0x563158);

	virtual void OnUpdateFrameMenu(HMENU hMenuAlt)
		_PPMFC_THISCALL(0x5621F2);

	virtual HACCEL GetDefaultAccelerator()
		_PPMFC_THISCALL(0x5618D0);

	virtual void DelayUpdateFrameMenu(HMENU hMenuAlt)
		_PPMFC_THISCALL(0x5634B4);

	virtual void ExitHelpMode()
		_PPMFC_THISCALL(0x5619B4);

	// normal functions
	LRESULT Default()
		_PPMFC_THISCALL(0x4D3F90);

	BOOL IsTracking() const
		_PPMFC_THISCALL(0x5553CA);

	void OnHelp()
		_PPMFC_THISCALL(0x55FDCF);

	void AddFrameWnd()
		_PPMFC_THISCALL(0x561862);

	void RemoveFrameWnd()
		_PPMFC_THISCALL(0x561886);

	BOOL LoadAccelTable(LPCTSTR lpszResourceName)
		_PPMFC_THISCALL(0x5618AA);

	void OnPaletteChanged(CWnd* pFocusWnd)
		_PPMFC_THISCALL(0x561977);

	BOOL OnQueryNewPalette()
		_PPMFC_THISCALL(0x561993);

	BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
		_PPMFC_THISCALL(0x561A1F);

	LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x561A49);

	LRESULT OnHelpHitTest(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x561AA1);

	void ShowOwnedWindows(BOOL bShow)
		_PPMFC_THISCALL(0x561CD9);

	void OnEnable(BOOL bEnable)
		_PPMFC_THISCALL(0x561D71);

	void NotifyFloatingWindows(DWORD dwFlags)
		_PPMFC_THISCALL(0x561E27);

	CWnd* CreateView(CCreateContext* pContext, UINT nID = 0xE900) // AFX_IDW_PANE_FIRST
		_PPMFC_THISCALL(0x561FAD);

	int OnCreate(LPCREATESTRUCT lpCreateStruct)
		_PPMFC_THISCALL(0x562047);

	int OnCreateHelper(LPCREATESTRUCT lpcs, CCreateContext* pContext)
		_PPMFC_THISCALL(0x562056);

	LPCTSTR GetIconWndClass(DWORD dwDefaultStyle, UINT nIDResource)
		_PPMFC_THISCALL(0x5620A5);

	void OnClose()
		_PPMFC_THISCALL(0x562228);

	void OnDestroy()
		_PPMFC_THISCALL(0x56231F);

	void RemoveControlBar(CControlBar* pBar)
		_PPMFC_THISCALL(0x562372);

	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
		_PPMFC_THISCALL(0x56243B);

	void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
		_PPMFC_THISCALL(0x562464);

	LRESULT OnActivateTopLevel(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x56248D);

	void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
		_PPMFC_THISCALL(0x56251B);

	BOOL OnNcActivate(BOOL bActive)
		_PPMFC_THISCALL(0x5625EF);

	void OnSysCommand(UINT nID, LPARAM lParam)
		_PPMFC_THISCALL(0x562626);

	void OnDropFiles(HDROP hDropInfo)
		_PPMFC_THISCALL(0x5626BB);

	BOOL OnQueryEndSession()
		_PPMFC_THISCALL(0x56272D);

	void OnEndSession(BOOL bEnding)
		_PPMFC_THISCALL(0x562752);

	LRESULT OnDDEInitiate(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x56278A);

	LRESULT OnDDEExecute(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x56284D);

	LRESULT OnDDETerminate(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x5628E8);

	void SetActiveView(CView* pViewNew, BOOL bNotify = TRUE)
		_PPMFC_THISCALL(0x56290A);

	void OnSetFocus(CWnd* pOldWnd)
		_PPMFC_THISCALL(0x562964);

	void ShowControlBar(CControlBar* pBar, BOOL bShow, BOOL bDelay)
		_PPMFC_THISCALL(0x56298F);

	void OnInitMenu(CMenu* pMenu)
		_PPMFC_THISCALL(0x562A8A);

	void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu)
		_PPMFC_THISCALL(0x562AA8);

	void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu)
		_PPMFC_THISCALL(0x562C29);

	LRESULT OnPopMessageString(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x562D7E);

	LRESULT OnSetMessageString(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x562DA1);

	DWORD* OnHelpPromptAddr(/*WPARAM wParam, LPARAM lParam*/)
		_PPMFC_THISCALL(0x562E66);

	void OnEnterIdle(UINT nWhy, CWnd* pWho)
		_PPMFC_THISCALL(0x562E7C);

	void SetMessageText(UINT nID)
		_PPMFC_THISCALL(0x562EAD);

	void DestroyDockBars()
		_PPMFC_THISCALL(0x562EC4);

	CControlBar* GetControlBar(UINT nID)
		_PPMFC_THISCALL(0x562F4F);

	void OnUpdateControlBarMenu(CCmdUI* pCmdUI)
		_PPMFC_THISCALL(0x562F83);

	BOOL OnBarCheck(UINT nID)
		_PPMFC_THISCALL(0x562FB8);

	BOOL OnToolTipText(UINT nID, NMHDR* pNMHDR, LRESULT* pResult)
		_PPMFC_THISCALL(0x562FF1);

	void OnUpdateKeyIndicator(CCmdUI* pCmdUI)
		_PPMFC_THISCALL(0x5630C8);

	void OnUpdateContextHelp(CCmdUI* pCmdUI)
		_PPMFC_THISCALL(0x563129);

	void UpdateFrameTitleForDocument(LPCTSTR lpszDocName)
		_PPMFC_THISCALL(0x56319C);

	void OnIdleUpdateCmdUI()
		_PPMFC_THISCALL(0x5634C8);

	void OnSize(UINT nType, int cx, int cy)
		_PPMFC_THISCALL(0x5636A1);

	BOOL OnEraseBkgnd(CDC* pDC)
		_PPMFC_THISCALL(0x5636C0);

	LRESULT OnRegisteredMouseWheel(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x5636D6);

	void BringToTop(int nCmdShow)
		_PPMFC_THISCALL(0x5637C9);

	CMiniDockFrameWnd* CreateFloatingFrame(DWORD dwStyle)
		_PPMFC_THISCALL(0x56404B);

	void DockControlBar(CControlBar* pBar, CDockBar* pDockBar, LPCRECT lpRect = nullptr)
		_PPMFC_THISCALL(0x564084);

	void ReDockControlBar(CControlBar* pBar, CDockBar* pDockBar, LPCRECT lpRect = nullptr)
		_PPMFC_THISCALL(0x5640D9);

	void FloatControlBar(CControlBar* pBar, CPoint point, DWORD dwStyle = 0x2000) // CBRS_ALIGN_TOP
		_PPMFC_THISCALL(0x56415E);

	DWORD CanDock(CRect rect, DWORD dwDockStyle, CDockBar** ppDockBar = nullptr)
		_PPMFC_THISCALL(0x56425B);

	static CFrameWnd* _PPMFC_API CreateObject()
		_PPMFC_STDCALL(0x56586A);

public:
    static constexpr reference<CRect, 0x8864B8> defaultRect{};

    BOOL m_bAutoMenuEnable;
    int m_nWindow;
	HMENU m_hMenuDefault;
	HACCEL m_hAccelTable;
	DWORD m_dwPromptContext; 
	BOOL m_bHelpMode;
	CFrameWnd* m_pNextFrameWnd;
	CRect m_rectBorder;
	COleFrameHook* m_pNotifyHook;
	CPtrList m_listControlBars;
	int m_nShowDelay;
	UINT m_nIDHelp;
	UINT m_nIDTracking;
	UINT m_nIDLastMessage;
	CView* m_pViewActive;
	BOOL(CALLBACK* m_lpfnCloseProc)(CFrameWnd* pFrameWnd);
	UINT m_cModalStack;
	HWND* m_phWndDisable;
	HMENU m_hMenuAlt;
	CString m_strTitle;
	BOOL m_bInRecalcLayout;
	CRuntimeClass* m_pFloatingFrameClass;
	UINT m_nIdleFlags;
};

_PPMFC_END