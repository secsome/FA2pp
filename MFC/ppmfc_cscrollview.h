#pragma once

#include "ppmfc_cview.h"

_PPMFC_BEGIN

_PPMFC_CLASS(CScrollView) _PPMFC_INHERIT(CView)
{
public:
	CScrollView() _PPMFC_THISCALL(0x559568);

	// virtual functions
	virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59D1F8); }
	
	virtual ~CScrollView() override _PPMFC_THISCALL(0x5595AB);

	virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder) override
		_PPMFC_THISCALL(0x559C4E);

	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE) override
		_PPMFC_THISCALL(0x559EC0);

	virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE) override
		_PPMFC_THISCALL(0x559F90);

	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL) override
		_PPMFC_THISCALL(0x5595B6);

	// normal functions
	void SetScaleToFitSize(SIZE sizeTotal)
		_PPMFC_THISCALL(0x559695);

	void SetScrollSizes(int nMapMode, SIZE sizeTotal,
		const SIZE& sizePage = sizeDefault,
		const SIZE& sizeLine = sizeDefault)
		_PPMFC_THISCALL(0x559720);

	CPoint GetDeviceScrollPosition() const
		_PPMFC_THISCALL(0x559852);

	void ScrollToDevicePosition(POINT ptDev)
		_PPMFC_THISCALL(0x5598CB);

	void OnSize(UINT nType, int cx, int cy)
		_PPMFC_THISCALL(0x55991D);

	void GetScrollBarSizes(CSize& sizeSb)
		_PPMFC_THISCALL(0x559945);

	BOOL GetTrueClientSize(CSize& size, CSize& sizeSb)
		_PPMFC_THISCALL(0x55999F);

	void GetScrollBarState(CSize sizeClient, CSize& needSb, CSize& sizeRange, CPoint& ptMove, BOOL bInsideClient)
		_PPMFC_THISCALL(0x559A14);

	void UpdateBars()
		_PPMFC_THISCALL(0x559AD9);

	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
		_PPMFC_THISCALL(0x559CD5);

	void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
		_PPMFC_THISCALL(0x559D19);

	BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
		_PPMFC_THISCALL(0x559D61);

	BOOL DoMouseWheel(UINT fFlags, short zDelta, CPoint point)
		_PPMFC_THISCALL(0x559D95);

public:
	static constexpr reference<SIZE, 0x59D220> sizeDefault{};

	int m_nMapMode;
	CSize m_totalLog;
	CSize m_totalDev;
	CSize m_pageDev;
	CSize m_lineDev;
	BOOL m_bCenter;
	BOOL m_bInsideUpdate;
};

_PPMFC_END