#pragma once

#include "ppmfc_cwnd.h"
#include "ppmfc_cstring.h"

_PPMFC_BEGIN

_PPMFC_CLASS(CComboBox) _PPMFC_INHERIT(CWnd)
{
	// DECLARE_DYNAMIC(CComboBox)

	// Constructors
public:
	CComboBox();
	// BOOL Create(DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID);

	// Attributes
	// for entire combo box
	int GetCount() const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETCOUNT, 0, 0); }
	int GetCurSel() const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETCURSEL, 0, 0); }
	int SetCurSel(int nSelect) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_SETCURSEL, nSelect, 0); };
	LCID GetLocale() const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETLOCALE, 0, 0); }
	LCID SetLocale(LCID nNewLocale) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_SETLOCALE, nNewLocale, 0); }
	// Win4
	int GetTopIndex() const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETTOPINDEX, 0, 0); }
	int SetTopIndex(int nIndex) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_SETTOPINDEX, nIndex, 0); }
	int InitStorage(int nItems, UINT nBytes) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_INITSTORAGE, nItems, nBytes); }
	void SetHorizontalExtent(UINT nExtent) 
		{ ASSERT(::IsWindow(this->m_hWnd)); this->SendMessage(CB_SETHORIZONTALEXTENT, nExtent, 0); }
	UINT GetHorizontalExtent() const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETHORIZONTALEXTENT, 0, 0); }
	int SetDroppedWidth(UINT nWidth) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_SETDROPPEDWIDTH, nWidth, 0); }
	int GetDroppedWidth() const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETDROPPEDWIDTH, 0, 0); }

	 // for edit control
	DWORD GetEditSel() const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETEDITSEL, 0, 0); }
	BOOL LimitText(int nMaxChars) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_LIMITTEXT, nMaxChars, 0); }
	BOOL SetEditSel(int nStartChar, int nEndChar) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_SETEDITSEL, 0, MAKEWORD(nStartChar, nEndChar)); }

	// for combobox item
	DWORD GetItemData(int nIndex) const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETITEMDATA, nIndex, 0); }
	int SetItemData(int nIndex, DWORD dwItemData) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_SETITEMDATA, nIndex, dwItemData); }
	void* GetItemDataPtr(int nIndex) const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return reinterpret_cast<void*>(this->GetItemData(nIndex)); }
	int SetItemDataPtr(int nIndex, void* pData) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SetItemData(nIndex, reinterpret_cast<DWORD>(pData)); }
	int GetLBText(int nIndex, LPTSTR lpszText) const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETLBTEXT, nIndex, reinterpret_cast<LPARAM>(lpszText)); }
	void GetLBText(int nIndex, CString& rString) const
	{
		GetLBText(nIndex, rString.GetBufferSetLength(GetLBTextLen(nIndex)));
		rString.ReleaseBuffer();
	};
	int GetLBTextLen(int nIndex) const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETLBTEXTLEN, nIndex, 0); };

	int SetItemHeight(int nIndex, UINT cyItemHeight)
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_SETITEMHEIGHT, nIndex, cyItemHeight); }
	int GetItemHeight(int nIndex) const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETITEMHEIGHT, nIndex, 0); }
	int FindStringExact(int nIndexStart, LPCTSTR lpszFind) const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_FINDSTRINGEXACT, nIndexStart, reinterpret_cast<LPARAM>(lpszFind)); }
	int SetExtendedUI(BOOL bExtended = TRUE) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_SETEXTENDEDUI, bExtended, 0); }
	BOOL GetExtendedUI() const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETEXTENDEDUI, 0, 0); }
	void GetDroppedControlRect(LPRECT lprect) const 
		{ ASSERT(::IsWindow(this->m_hWnd)); this->SendMessage(CB_GETDROPPEDCONTROLRECT, 0, reinterpret_cast<LPARAM>(lprect)); }
	BOOL GetDroppedState() const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_GETDROPPEDSTATE, 0, 0); }

	// Operations
	// for drop-down combo boxes
	void ShowDropDown(BOOL bShowIt = TRUE) 
		{ ASSERT(::IsWindow(this->m_hWnd)); this->SendMessage(CB_SHOWDROPDOWN, bShowIt, 0); }

	// manipulating listbox items
	int AddString(LPCTSTR lpszString) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(lpszString)); }
	int DeleteString(UINT nIndex) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_DELETESTRING, nIndex, 0); }
	int InsertString(int nIndex, LPCTSTR lpszString) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_INSERTSTRING, nIndex, reinterpret_cast<LPARAM>(lpszString)); }
	void ResetContent() 
		{ ASSERT(::IsWindow(this->m_hWnd)); this->SendMessage(CB_RESETCONTENT, 0, 0); }
	int Dir(UINT attr, LPCTSTR lpszWildCard) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_DIR, attr, reinterpret_cast<LPARAM>(lpszWildCard)); }

	// selection helpers
	int FindString(int nStartAfter, LPCTSTR lpszString) const 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_FINDSTRING, nStartAfter, reinterpret_cast<LPARAM>(lpszString)); }
	int SelectString(int nStartAfter, LPCTSTR lpszString) 
		{ ASSERT(::IsWindow(this->m_hWnd)); return this->SendMessage(CB_SELECTSTRING, nStartAfter, reinterpret_cast<LPARAM>(lpszString)); }

	// Clipboard operations
	// void Clear();
	// void Copy();
	// void Cut();
	// void Paste();

	// Overridables (must override draw, measure and compare for owner draw)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);

	// Implementation
public:
	virtual ~CComboBox();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);

};

_PPMFC_END