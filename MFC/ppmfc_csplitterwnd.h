#pragma once

#include "ppmfc_cwnd.h"

_PPMFC_BEGIN

// forward declarations
class CView;

_PPMFC_CLASS(CSplitterWnd) _PPMFC_INHERIT(CWnd)
{
public:
	CSplitterWnd() _PPMFC_THISCALL(0x55BD5D);

	// virtual functions
	virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59A758); }

	virtual ~CSplitterWnd() override _PPMFC_THISCALL(0x55BDE4);

	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam) override
		_PPMFC_THISCALL(0x55E123);

	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) override
		_PPMFC_THISCALL(0x55E15D);

	virtual BOOL CreateView(int row, int col, CRuntimeClass* pViewClass, SIZE sizeInit, CCreateContext* pContext)
		_PPMFC_THISCALL(0x55BF94);

	virtual void RecalcLayout()
		_PPMFC_THISCALL(0x55D51C);

	enum ESplitType { splitBox, splitBar, splitIntersection, splitBorder };
	virtual void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect)
		_PPMFC_THISCALL(0x55C368);

	virtual void OnInvertTracker(const CRect& rect)
		_PPMFC_THISCALL(0x55D101);

	virtual BOOL CreateScrollBarCtrl(DWORD dwStyle, UINT nID)
		_PPMFC_THISCALL(0x55C0CE);

	virtual void DeleteView(int row, int col)
		_PPMFC_THISCALL(0x55C32B);

	virtual BOOL SplitRow(int cyBefore)
		_PPMFC_THISCALL(0x55C4A6);

	virtual BOOL SplitColumn(int cxBefore)
		_PPMFC_THISCALL(0x55C5A5);
	
	virtual void DeleteRow(int rowDelete)
		_PPMFC_THISCALL(0x55C6A4);

	virtual void DeleteColumn(int colDelete)
		_PPMFC_THISCALL(0x55C7B2);

	virtual CWnd* GetActivePane(int* pRow = NULL, int* pCol = NULL)
		_PPMFC_THISCALL(0x55E717);

	virtual void SetActivePane(int row, int col, CWnd* pWnd = NULL)
		_PPMFC_THISCALL(0x55E6CD);

	virtual BOOL CanActivateNext(BOOL bPrev = FALSE)
		_PPMFC_THISCALL(0x55E636);

	virtual void ActivateNext(BOOL bPrev = FALSE)
		_PPMFC_THISCALL(0x55E65C);

	virtual BOOL DoKeyboardSplit()
		_PPMFC_THISCALL(0x55D177);

	virtual BOOL DoScroll(CView* pViewFrom, UINT nScrollCode, BOOL bDoScroll = TRUE)
		_PPMFC_THISCALL(0x55E38C);

	virtual BOOL DoScrollBy(CView* pViewFrom, CSize sizeScroll, BOOL bDoScroll = TRUE)
		_PPMFC_THISCALL(0x55E4E3);

	virtual int HitTest(CPoint pt) const
		_PPMFC_THISCALL(0x55CF53);

	virtual void GetInsideRect(CRect& rect) const
		_PPMFC_THISCALL(0x55C8C0);

	virtual void GetHitRect(int ht, CRect& rect)
		_PPMFC_THISCALL(0x55CD93);

	virtual void TrackRowSize(int y, int row)
		_PPMFC_THISCALL(0x55CAD2);

	virtual void TrackColumnSize(int x, int col)
		_PPMFC_THISCALL(0x55CB5E);

	virtual void DrawAllSplitBars(CDC* pDC, int cxInside, int cyInside)
		_PPMFC_THISCALL(0x55D7D6);

	virtual void SetSplitCursor(int ht)
		_PPMFC_THISCALL(0x55DBDB);

	virtual void StartTracking(int ht)
		_PPMFC_THISCALL(0x55C90E);

	virtual void StopTracking(BOOL bAccept)
		_PPMFC_THISCALL(0x55CBEA);

	// normal functions
	BOOL CreateStatic(CWnd* pParentWnd,
		int nRows, int nCols,
		DWORD dwStyle = WS_CHILD | WS_VISIBLE,
		UINT nID = 0xE900) // AFX_IDW_PANE_FIRST
		_PPMFC_THISCALL(0x55BE29);

	BOOL CreateCommon(CWnd* pParentWnd, SIZE sizeMin, DWORD dwStyle, UINT nID)
		_PPMFC_THISCALL(0x55BE5C);

	BOOL OnNcCreate(LPCREATESTRUCT lpcs)
		_PPMFC_THISCALL(0x55BF62);

	int IdFromRowCol(int row, int col) const
		_PPMFC_THISCALL(0x55C10B);

	CWnd* GetPane(int row, int col) const
		_PPMFC_THISCALL(0x55C11E);

	void GetRowInfo(int row, int& cyCur, int& cyMin) const
	{
		cyCur = m_pRowInfo[row].nCurSize;
		cyMin = m_pRowInfo[row].nMinSize;
	}
	
	void SetRowInfo(int row, int cyIdeal, int cyMin)
		_PPMFC_THISCALL(0x55C1B6);

	void GetColumnInfo(int col, int& cxCur, int& cxMin) const
	{
		cxCur = m_pColInfo[col].nCurSize;
		cxMin = m_pColInfo[col].nMinSize;
	}

	void SetColumnInfo(int col, int cxIdeal, int cxMin)
	{
		m_pColInfo[col].nIdealSize = cxIdeal;
		m_pColInfo[col].nMinSize = cxMin;
	}

	BOOL IsChildPane(CWnd* pWnd, int* pRow, int* pCol)
		_PPMFC_THISCALL(0x55C13A);

	DWORD GetScrollStyle() const
		_PPMFC_THISCALL(0x55C1DA);

	void SetScrollStyle(DWORD dwStyle)
		_PPMFC_THISCALL(0x55C1F2);

	void OnDisplayChange()
		_PPMFC_THISCALL(0x55D26A);

	void OnSize(UINT nType, int cx, int cy)
		_PPMFC_THISCALL(0x55D293);

	CWnd* GetSizingParent()
		_PPMFC_THISCALL(0x55D486);

	void OnPaint()
		_PPMFC_THISCALL(0x55D9D3);

	BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
		_PPMFC_THISCALL(0x55DBBB);

	void OnMouseMove(UINT nFlags, CPoint pt)
		_PPMFC_THISCALL(0x55DCB8);

	void OnLButtonDown(UINT nFlags, CPoint pt)
		_PPMFC_THISCALL(0x55DE3C);

	void OnLButtonDblClk(UINT nFlags, CPoint pt)
		_PPMFC_THISCALL(0x55DE67);

	void OnLButtonUp(UINT nFlags, CPoint pt)
		_PPMFC_THISCALL(0x55DFAF);

	void OnCancelMode()
		_PPMFC_THISCALL(0x55DFBC);

	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
		_PPMFC_THISCALL(0x55DFC7);

	void OnSysCommand(UINT nID, LPARAM lParam)
		_PPMFC_THISCALL(0x55E0E4);

	BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
		_PPMFC_THISCALL(0x55E19A);

	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
		_PPMFC_THISCALL(0x55E260);

	void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
		_PPMFC_THISCALL(0x55E2F6);

public:
	CRuntimeClass* m_pDynamicViewClass;
	int m_nMaxRows, m_nMaxCols;
	int m_cxSplitter, m_cySplitter;
	int m_cxBorderShare, m_cyBorderShare;
	int m_cxSplitterGap, m_cySplitterGap;
	int m_cxBorder, m_cyBorder;
	int m_nRows, m_nCols;
	BOOL m_bHasHScroll, m_bHasVScroll;
	struct CRowColInfo
	{
		int nMinSize;       // below that try not to show
		int nIdealSize;     // user set size
		// variable depending on the available size layout
		int nCurSize;       // 0 => invisible, -1 => nonexistant
	} *m_pColInfo, *m_pRowInfo;
	BOOL m_bTracking, m_bTracking2;
	CPoint m_ptTrackOffset;
	CRect m_rectLimit;
	CRect m_rectTracker, m_rectTracker2;
	int m_htTrack;
};

static int _PPMFC_API CanSplitRowCol(CSplitterWnd::CRowColInfo* pInfoBefore, int nBeforeSize, int nSizeSplitter)
_PPMFC_STDCALL(0x55C486);

static void _PPMFC_API LayoutRowCol(CSplitterWnd::CRowColInfo* pInfoArray, int nMax, int nSize, int nSizeSplitter)
_PPMFC_STDCALL(0x55D2BE);

_PPMFC_END