#pragma once

#include "ppmfc_cwnd.h"

_PPMFC_BEGIN

// forward declarations
class CDockBar;
class CDockContext;
struct AFX_SIZEPARENTPARAMS;

_PPMFC_CLASS(CControlBar) _PPMFC_INHERIT(CWnd)
{
public:
	CControlBar() { JMP_THIS(0x565722); }

    // virtual functions
	virtual ~CControlBar() override { JMP_THIS(0x55E75C); }

	virtual BOOL DestroyWindow() override
		_PPMFC_THISCALL(0x55EF1B);

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override
		_PPMFC_STDCALL(0x56578D);

	virtual BOOL PreTranslateMessage(MSG* pMsg) override
		_PPMFC_THISCALL(0x55EA88);

	virtual void PostNcDestroy() override
		_PPMFC_THISCALL(0x55E7E1);

	virtual CSize CalcFixedLayout(BOOL bStretch, BOOL bHorz)  RT(CSize);

	virtual CSize CalcDynamicLayout(int nLength, DWORD nMode) RT(CSize);

	virtual void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler) RX;

	virtual void DelayShow(BOOL bShow)
		_PPMFC_THISCALL(0x55F3B2);

	virtual BOOL IsVisible() const
		_PPMFC_THISCALL(0x55F3E6);

	virtual DWORD RecalcDelayShow(AFX_SIZEPARENTPARAMS* lpLayout)
		_PPMFC_THISCALL(0x55F208);

	virtual BOOL IsDockBar() const
		_PPMFC_THISCALL(0x55E848);

	virtual void OnBarStyleChange(DWORD dwOldStyle, DWORD dwNewStyle)
		_PPMFC_THISCALL(0x56582E);

	virtual void DoPaint(CDC* pDC)
		_PPMFC_THISCALL(0x55F404);

	virtual BOOL SetStatusText(int nHit)
		_PPMFC_THISCALL(0x55E9F1);

    // normal functions

	void ResetTimer(UINT nEvent, UINT nTime)
		_PPMFC_THISCALL(0x55E84B);

	void OnTimer(UINT nIDEvent)
		_PPMFC_THISCALL(0x55E881);

	LRESULT OnHelpHitTest(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x55ED4E);

	void OnWindowPosChanging(LPWINDOWPOS lpWndPos)
		_PPMFC_THISCALL(0x55ED91);

	int OnCreate(LPCREATESTRUCT lpcs)
		_PPMFC_THISCALL(0x55EE92);

	void OnDestroy()
		_PPMFC_THISCALL(0x55EEE5);

	int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT nMsg)
		_PPMFC_THISCALL(0x55EF46);

	void OnPaint()
		_PPMFC_THISCALL(0x55EF67);

	void EraseNonClient()
		_PPMFC_THISCALL(0x55EFB9);

	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
		_PPMFC_THISCALL(0x55F086);

	void OnLButtonDown(UINT nFlags, CPoint pt)
		_PPMFC_THISCALL(0x55F0DE);

	void OnLButtonDblClk(UINT nFlags, CPoint pt)
		_PPMFC_THISCALL(0x55F124);
	
	LRESULT OnIdleUpdateCmdUI(WPARAM wParam, LPARAM lParam)
		_PPMFC_THISCALL(0x55F156);

	void OnInitialUpdate()
		_PPMFC_THISCALL(0x55F1FE);

	void DrawBorders(CDC* pDC, CRect& rect)
		_PPMFC_THISCALL(0x55F43B);

	void DrawGripper(CDC* pDC, const CRect& rect)
		_PPMFC_THISCALL(0x55F5E9);

	void CalcInsideRect(CRect& rect, BOOL bHorz) const
		_PPMFC_THISCALL(0x55F662);

	CFrameWnd* GetDockingFrame() const
		_PPMFC_THISCALL(0x5637F8);

	BOOL IsFloating() const
		_PPMFC_THISCALL(0x563809);

	void SetBorders(int left, int top, int right, int bottom)
		_PPMFC_THISCALL(0x56576E);

	void SetBarStyle(DWORD dwStyle)
		_PPMFC_THISCALL(0x565800);

	BOOL AllocElements(int nElements, int cbElement)
		_PPMFC_THISCALL(0x565831);

public:
	BOOL m_bAutoDelete;
    int m_cxLeftBorder, m_cxRightBorder;
    int m_cyTopBorder, m_cyBottomBorder;
    int m_cxDefaultGap;
    UINT m_nMRUWidth;
	int m_nCount;
	void* m_pData;
	enum StateFlags { delayHide = 1, delayShow = 2, tempHide = 4, statusSet = 8 };
	UINT m_nStateFlags;
	DWORD m_dwStyle;
	DWORD m_dwDockStyle;
	CFrameWnd* m_pDockSite;
	CDockBar* m_pDockBar;
	CDockContext* m_pDockContext;
};

_PPMFC_END