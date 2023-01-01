#pragma once

#include "ppmfc_cwnd.h"
#include "ppmfc_cstring.h"

_PPMFC_BEGIN

_PPMFC_CLASS(CListBox) _PPMFC_INHERIT(CWnd)
{
	// DECLARE_DYNAMIC(CListBox)

	// Constructors
public:
	CListBox();
	// BOOL Create(DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID);

	// Attributes
	// for entire listbox
	int GetCount() const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETCOUNT, 0, 0); }
	int GetHorizontalExtent() const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETHORIZONTALEXTENT, 0, 0); }
	void SetHorizontalExtent(int cxExtent)
		{ ASSERT(::IsWindow(this->m_hWnd)); this->SendMessage(LB_SETHORIZONTALEXTENT, cxExtent, 0); }
	int GetTopIndex() const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETTOPINDEX, 0, 0); }
	int SetTopIndex(int nIndex)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_SETTOPINDEX, nIndex, 0); }
	LCID GetLocale() const
		{ ASSERT(::IsWindow(this->m_hWnd)); return (LCID)this->SendMessage(LB_GETLOCALE, 0, 0); }
	LCID SetLocale(LCID nNewLocale)
		{ ASSERT(::IsWindow(this->m_hWnd)); return (LCID)this->SendMessage(LB_SETLOCALE, (WPARAM)nNewLocale, 0); }
#if (WINVER >= 0x400)
	int InitStorage(int nItems, UINT nBytes)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_INITSTORAGE, (WPARAM)nItems, nBytes); }
	UINT ItemFromPoint(CPoint pt, BOOL& bOutside) const
	{
		ASSERT(::IsWindow(m_hWnd));
		DWORD dw = this->SendMessage(LB_ITEMFROMPOINT, 0, MAKELPARAM(pt.x, pt.y));
		bOutside = !!HIWORD(dw);
		return LOWORD(dw);
	}
#endif
	// for single-selection listboxes
	int GetCurSel() const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETCURSEL, 0, 0); }
	int SetCurSel(int nSelect)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_SETCURSEL, nSelect, 0); }

	// for multiple-selection listboxes
	int GetSel(int nIndex) const           // also works for single-selection
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETSEL, nIndex, 0); }
	int SetSel(int nIndex, BOOL bSelect = TRUE)
		{ ASSERT(::IsWindow(m_hWnd)); return this->SendMessage(LB_SETSEL, bSelect, nIndex); }
	int GetSelCount() const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETSELCOUNT, 0, 0); }
	int GetSelItems(int nMaxItems, LPINT rgIndex) const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETSELITEMS, nMaxItems, (LPARAM)rgIndex); }
	void SetAnchorIndex(int nIndex)
		{ ASSERT(::IsWindow(this->m_hWnd)); this->SendMessage(LB_SETANCHORINDEX, nIndex, 0); }
	int GetAnchorIndex() const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETANCHORINDEX, 0, 0); }

	// for listbox items
	DWORD GetItemData(int nIndex) const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETITEMDATA, nIndex, 0); }
	int SetItemData(int nIndex, DWORD dwItemData)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_SETITEMDATA, nIndex, (LPARAM)dwItemData); }
	void* GetItemDataPtr(int nIndex) const
		{ ASSERT(::IsWindow(this->m_hWnd)); return (LPVOID)this->SendMessage(LB_GETITEMDATA, nIndex, 0); }
	int SetItemDataPtr(int nIndex, void* pData)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SetItemData(nIndex, (DWORD)(LPVOID)pData); }
	int GetItemRect(int nIndex, LPRECT lpRect) const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETITEMRECT, nIndex, (LPARAM)lpRect); }
	int GetText(int nIndex, LPTSTR lpszBuffer) const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETTEXT, nIndex, (LPARAM)lpszBuffer); }
	void GetText(int nIndex, CString& rString) const
	{
		GetText(nIndex, rString.GetBufferSetLength(GetTextLen(nIndex)));
		rString.ReleaseBuffer();
	}
	int GetTextLen(int nIndex) const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETTEXTLEN, nIndex, 0); }

	// Settable only attributes
	void SetColumnWidth(int cxWidth)
		{ ASSERT(::IsWindow(this->m_hWnd)); this->SendMessage(LB_SETCOLUMNWIDTH, cxWidth, 0); }
	BOOL SetTabStops(int nTabStops, LPINT rgTabStops)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_SETTABSTOPS, nTabStops, (LPARAM)rgTabStops); }
	void SetTabStops()
		{ ASSERT(::IsWindow(this->m_hWnd)); VERIFY(this->SendMessage(LB_SETTABSTOPS, 0, 0)); }
	BOOL SetTabStops(const int& cxEachStop)    // takes an 'int'
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_SETTABSTOPS, 1, (LPARAM)(LPINT)&cxEachStop); }

	int SetItemHeight(int nIndex, UINT cyItemHeight)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_SETITEMHEIGHT, nIndex, MAKELONG(cyItemHeight, 0)); }
	int GetItemHeight(int nIndex) const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETITEMHEIGHT, nIndex, 0L); }
	int FindStringExact(int nIndexStart, LPCTSTR lpszFind) const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_FINDSTRINGEXACT, nIndexStart, (LPARAM)lpszFind); }
	int GetCaretIndex() const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_GETCARETINDEX, 0, 0L); }
	int SetCaretIndex(int nIndex, BOOL bScroll = TRUE)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_SETCARETINDEX, nIndex, MAKELONG(bScroll, 0)); }

	// Operations
	// manipulating listbox items
	int AddString(LPCTSTR lpszItem)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_ADDSTRING, 0, (LPARAM)lpszItem); }
	int DeleteString(UINT nIndex)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_DELETESTRING, nIndex, 0); }
	void DeleteAllStrings()
		{ while (this->DeleteString(0) != LB_ERR); }
	int InsertString(int nIndex, LPCTSTR lpszItem)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_INSERTSTRING, nIndex, (LPARAM)lpszItem); }
	void ResetContent()
		{ ASSERT(::IsWindow(this->m_hWnd)); this->SendMessage(LB_RESETCONTENT, 0, 0); }
	int Dir(UINT attr, LPCTSTR lpszWildCard)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_DIR, attr, (LPARAM)lpszWildCard); }

	// selection helpers
	int FindString(int nStartAfter, LPCTSTR lpszItem) const
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_FINDSTRING, nStartAfter, (LPARAM)lpszItem); }
	int SelectString(int nStartAfter, LPCTSTR lpszItem)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(LB_SELECTSTRING, nStartAfter, (LPARAM)lpszItem); }
	int SelItemRange(BOOL bSelect, int nFirstItem, int nLastItem)
	{
		ASSERT(::IsWindow(this->m_hWnd)); 
		return bSelect ?
			this->SendMessage(LB_SELITEMRANGEEX, nFirstItem, nLastItem) :
			this->SendMessage(LB_SELITEMRANGEEX, nLastItem, nFirstItem);
	}

	// Overridables (must override draw, measure and compare for owner draw)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
	virtual int VKeyToItem(UINT nKey, UINT nIndex);
	virtual int CharToItem(UINT nKey, UINT nIndex);

	// Implementation
public:
	virtual ~CListBox();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

_PPMFC_END