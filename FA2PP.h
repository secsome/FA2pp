#pragma once

#include <AFXWIN.H>
#include <AFXCMN.H>
#include <AFXEXT.H>
#include "FA2PPCore.h"

#include "MFC/ppmfc_include.h"

#include "Helpers/CompileTime.h"

class FA2PP
{
public:
	static void __stdcall DDX_Text(CDataExchange* pDX, int nIDC, int& value) { JMP_STD(0x55A53D); }

};

class NOVTABLE FA2CWinApp : public CWinApp
{

};

class NOVTABLE FA2CScrollView : public CScrollView
{
public:
	void Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT* rect, 
		CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
	{
		JMP_THIS(0x552DAB);
	}

	void SetScrollSizes(int a2, SIZE a3, SIZE* a4, SIZE* a5)
	{
		JMP_THIS(0x559720);
	}
	
};

class NOVTABLE FA2CView : public CView
{
public:
	// Cwnd
	virtual BOOL PreTransateMessage(MSG* pMsg)
	{
		JMP_THIS(0x55304D);
	}
};

class FA2CStatusBar : public CStatusBar
{
public:
	BOOL Create(CWnd* pParent, unsigned int a3, unsigned int a4, int nID)
	{
		JMP_THIS(0x565951);
	}
};

class NOVTABLE FA2CFrameWnd : public CFrameWnd
{
public:
	virtual void RecalcLayout(BOOL bRepaint = FALSE)
	{
		JMP_THIS(0x56353A);
	}

	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
	{
		JMP_THIS(0x553C38);
	}

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pCreateContent)
	{
		JMP_THIS(0x562025);
	}

	virtual BOOL PreTransateMessage(MSG* pMsg)
	{
		JMP_THIS(0x5618F4);
	}

	void OnSysCommand(UINT uID, LPARAM lParam)
	{
		JMP_THIS(0x562626);
	}
};

class FA2CSplitterWnd : public CSplitterWnd
{
public:
	virtual BOOL CreateView(int row, int col, CRuntimeClass* pViewClass,
		SIZE sizeInit, CCreateContext* pContext)
	{
		JMP_THIS(0x55BF94);
	}

	BOOL CreateStatic(CWnd* pWnd, int nRows, int nCols, DWORD dwStyle, UINT nID)
	{
		JMP_THIS(0x55BE29);
	}

	CWnd* GetPane(int row, int col)
	{
		JMP_THIS(0x55C11E);
	}

	void SetColumnInfo(int col, int cxIdeal, int cxMin)
	{
		this->m_pColInfo[col].nIdealSize = cxIdeal;
		this->m_pColInfo[col].nMinSize = cxMin;
	}

	void SetRowInfo(int row, int cyIdeal, int cyMin)
	{
		JMP_THIS(0x55C1B6);
	}
};

class FA2CDialogBar : public CDialogBar
{
public:
	BOOL Create(CWnd* pParent, LPCSTR Name, int a4, LONG dwNewLong)
	{
		JMP_THIS(0x55BBB9);
	}
};