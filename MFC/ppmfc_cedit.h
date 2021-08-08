#pragma once

#include "ppmfc_cwnd.h"
#include "ppmfc_cstring.h"

_PPMFC_BEGIN

_PPMFC_CLASS(CEdit) _PPMFC_INHERIT(CWnd)
{
	// DECLARE_DYNAMIC(CEdit)

	// Constructors
public:
	CEdit()
	{ }
	BOOL CanUndo() const
		{ ASSERT(::IsWindow(m_hWnd)); return (BOOL)::SendMessage(m_hWnd, EM_CANUNDO, 0, 0); }
	int GetLineCount() const
		{ ASSERT(::IsWindow(m_hWnd)); return (int)::SendMessage(m_hWnd, EM_GETLINECOUNT, 0, 0); }
	BOOL GetModify() const
		{ ASSERT(::IsWindow(m_hWnd)); return (BOOL)::SendMessage(m_hWnd, EM_GETMODIFY, 0, 0); }
	void SetModify(BOOL bModified)
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_SETMODIFY, bModified, 0); }
	void GetRect(LPRECT lpRect) const
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_GETRECT, 0, (LPARAM)lpRect); }
	void GetSel(int& nStartChar, int& nEndChar) const
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&nStartChar, (LPARAM)&nEndChar); }
	DWORD GetSel() const
		{ ASSERT(::IsWindow(m_hWnd)); return ::SendMessage(m_hWnd, EM_GETSEL, 0, 0); }
	HANDLE GetHandle() const
		{ ASSERT(::IsWindow(m_hWnd)); return (HLOCAL)::SendMessage(m_hWnd, EM_GETHANDLE, 0, 0); }
	void SetHandle(HANDLE hBuffer)
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_SETHANDLE, (WPARAM)hBuffer, 0); }
	int GetLine(int nIndex, LPTSTR lpszBuffer) const
		{ ASSERT(::IsWindow(m_hWnd)); return (int)::SendMessage(m_hWnd, EM_GETLINE, nIndex, (LPARAM)lpszBuffer); }
	int GetLine(int nIndex, LPTSTR lpszBuffer, int nMaxLength) const
	{
		ASSERT(::IsWindow(m_hWnd));
		*(LPWORD)lpszBuffer = (WORD)nMaxLength;
		return (int)::SendMessage(m_hWnd, EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
	}
	void EmptyUndoBuffer()
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_EMPTYUNDOBUFFER, 0, 0); }
	BOOL FmtLines(BOOL bAddEOL)
		{ ASSERT(::IsWindow(m_hWnd)); return (BOOL)::SendMessage(m_hWnd, EM_FMTLINES, bAddEOL, 0); }
	void LimitText(int nChars)
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_LIMITTEXT, nChars, 0); }
	int LineFromChar(int nIndex) const
		{ ASSERT(::IsWindow(m_hWnd)); return (int)::SendMessage(m_hWnd, EM_LINEFROMCHAR, nIndex, 0); }
	int LineIndex(int nLine) const
		{ ASSERT(::IsWindow(m_hWnd)); return (int)::SendMessage(m_hWnd, EM_LINEINDEX, nLine, 0); }
	int LineLength(int nLine) const
		{ ASSERT(::IsWindow(m_hWnd)); return (int)::SendMessage(m_hWnd, EM_LINELENGTH, nLine, 0); }
	void  LineScroll(int nLines, int nChars)
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_LINESCROLL, nChars, nLines); }
	void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo)
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_REPLACESEL, (WPARAM)bCanUndo, (LPARAM)lpszNewText); }
	void SetPasswordChar(TCHAR ch)
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_SETPASSWORDCHAR, ch, 0); }
	void SetRect(LPCRECT lpRect)
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_SETRECT, 0, (LPARAM)lpRect); }
	void SetRectNP(LPCRECT lpRect)
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_SETRECTNP, 0, (LPARAM)lpRect); }
	void SetSel(DWORD dwSelection, BOOL bNoScroll)
	{
		ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_SETSEL,
			LOWORD(dwSelection), HIWORD(dwSelection));
		if (!bNoScroll)
			::SendMessage(m_hWnd, EM_SCROLLCARET, 0, 0);
	}
	void SetSel(int nStartChar, int nEndChar, BOOL bNoScroll)
	{
		ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_SETSEL, nStartChar, nEndChar);
		if (!bNoScroll)
			::SendMessage(m_hWnd, EM_SCROLLCARET, 0, 0);
	}
#ifndef _MAC
	BOOL SetTabStops(int nTabStops, LPINT rgTabStops)
		{ ASSERT(::IsWindow(m_hWnd)); return (BOOL)::SendMessage(m_hWnd, EM_SETTABSTOPS, nTabStops, (LPARAM)rgTabStops); }
	void SetTabStops()
		{ ASSERT(::IsWindow(m_hWnd)); VERIFY(::SendMessage(m_hWnd, EM_SETTABSTOPS, 0, 0)); }
	BOOL SetTabStops(const int& cxEachStop)
		{ ASSERT(::IsWindow(m_hWnd)); return (BOOL)::SendMessage(m_hWnd, EM_SETTABSTOPS, 1, (LPARAM)(LPINT)&cxEachStop); }
#endif
	BOOL Undo()
		{ ASSERT(::IsWindow(m_hWnd)); return (BOOL)::SendMessage(m_hWnd, EM_UNDO, 0, 0); }
	void Clear()
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, WM_CLEAR, 0, 0); }
	void Copy()
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, WM_COPY, 0, 0); }
	void Cut()
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, WM_CUT, 0, 0); }
	void Paste()
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, WM_PASTE, 0, 0); }
	BOOL SetReadOnly(BOOL bReadOnly)
		{ ASSERT(::IsWindow(m_hWnd)); return (BOOL)::SendMessage(m_hWnd, EM_SETREADONLY, bReadOnly, 0L); }
	int GetFirstVisibleLine() const
		{ ASSERT(::IsWindow(m_hWnd)); return (int)::SendMessage(m_hWnd, EM_GETFIRSTVISIBLELINE, 0, 0L); }
	TCHAR GetPasswordChar() const
		{ ASSERT(::IsWindow(m_hWnd)); return (TCHAR)::SendMessage(m_hWnd, EM_GETPASSWORDCHAR, 0, 0L); }
#if (WINVER >= 0x400)
	void SetMargins(UINT nLeft, UINT nRight)
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_SETMARGINS, EC_LEFTMARGIN | EC_RIGHTMARGIN, MAKELONG(nLeft, nRight)); }
	DWORD GetMargins() const
		{ ASSERT(::IsWindow(m_hWnd)); return (DWORD)::SendMessage(m_hWnd, EM_GETMARGINS, 0, 0); }
	void SetLimitText(UINT nMax)
		{ ASSERT(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, EM_SETLIMITTEXT, nMax, 0); }
	UINT GetLimitText() const
		{ ASSERT(::IsWindow(m_hWnd)); return (UINT)::SendMessage(m_hWnd, EM_GETLIMITTEXT, 0, 0); }
	CPoint PosFromChar(UINT nChar) const
		{ ASSERT(::IsWindow(m_hWnd)); return CPoint((DWORD)::SendMessage(m_hWnd, EM_POSFROMCHAR, nChar, 0)); }
	int CharFromPos(CPoint pt) const
		{ ASSERT(::IsWindow(m_hWnd)); return (int)::SendMessage(m_hWnd, EM_CHARFROMPOS, 0, MAKELPARAM(pt.x, pt.y)); }
#endif

	// Implementation
public:
	virtual ~CEdit();
};

_PPMFC_END