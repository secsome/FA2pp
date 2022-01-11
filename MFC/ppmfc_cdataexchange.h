#pragma once

#include "ppmfc_cwnd.h"
#include "ppmfc_cstring.h"

_PPMFC_BEGIN

// forward declarations
class CWnd;

_PPMFC_CLASS(CDataExchange)
{
public:
	CDataExchange(CWnd * pDlgWnd, BOOL bSaveAndValidate)
		_PPMFC_THISCALL(0x554AAA);

	HWND PrepareCtrl(int nIDC)
		_PPMFC_THISCALL(0x55A3C4);

	HWND PrepareEditCtrl(int nIDC)
		_PPMFC_THISCALL(0x55A3AD);

	void Fail()
		_PPMFC_THISCALL(0x55A3F3);

public:
	BOOL m_bSaveAndValidate;
	CWnd* m_pDlgWnd;
	HWND m_hWndLastControl;    // last control used (for validation)
	BOOL m_bEditLastControl;   // last control was an edit item
};

static void _PPMFC_CDECL DDX_TextWithFormat(CDataExchange* pDX, int nIDC, LPCTSTR lpszFormat, UINT nIDPrompt, ...)
_PPMFC_CDECLCALL(0x55A4CD);

static void _PPMFC_API DDX_Text(CDataExchange* pDX, int nIDC, int& value)
_PPMFC_STDCALL(0x55A53D);

static void _PPMFC_API DDX_Text(CDataExchange* pDX, int nIDC, CString& value)
_PPMFC_STDCALL(0x55A56C);

static void _PPMFC_API DDX_Check(CDataExchange* pDX, int nIDC, int& value)
_PPMFC_STDCALL(0x55A5BE);

static void _PPMFC_API DDX_Radio(CDataExchange* pDX, int nIDC, int& value)
_PPMFC_STDCALL(0x55A610);

static void _PPMFC_API DDX_LBString(CDataExchange* pDX, int nIDC, CString& value)
_PPMFC_STDCALL(0x55A6A1);

static void _PPMFC_API DDX_CBString(CDataExchange* pDX, int nIDC, CString& value)
_PPMFC_STDCALL(0x55A721);

static void _PPMFC_API DDX_CBIndex(CDataExchange* pDX, int nIDC, int& index)
_PPMFC_STDCALL(0x55A7A0);

static void _PPMFC_API DDX_Control(CDataExchange* pDX, int nIDC, CWnd& rControl)
_PPMFC_STDCALL(0x55A89E);

static void _PPMFC_API DDV_MinMaxInt(CDataExchange* pDX, int value, int minVal, int maxVal)
_PPMFC_STDCALL(0x55A872);

_PPMFC_END