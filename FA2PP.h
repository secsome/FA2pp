#pragma once

#include <AFXWIN.H>
#include <AFXCMN.H>
#include <AFXEXT.H>
#include "FA2PPCore.h"

#include "MFC/ppmfc_include.h"

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