#pragma once

#include "ppmfc_cwnd.h"

_PPMFC_BEGIN

// forward declarations
class CFont;

_PPMFC_CLASS(CDialog) _PPMFC_INHERIT(CWnd)
{
public:
	CDialog() {}

	CDialog(UINT nIDTemplate, CWnd* pParentWnd = nullptr)
		_PPMFC_THISCALL(0x551D6B);

	// virtual functions
	virtual CRuntimeClass* GetRuntimeClass() override { return reinterpret_cast<CRuntimeClass*>(0x59A528); }

	virtual ~CDialog() override _PPMFC_THISCALL(0x551A1D);

	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) override
		_PPMFC_THISCALL(0x55197C);

	virtual const AFX_MSGMAP* GetMessageMap() const override
		_PPMFC_THISCALL(0x5518DD);

	virtual BOOL PreTranslateMessage(MSG* pMsg) override
		_PPMFC_THISCALL(0x5518E3);

	virtual BOOL CheckAutoCenter() override
		_PPMFC_THISCALL(0x55212E);

	virtual BOOL SetOccDialogInfo(struct _AFX_OCC_DIALOG_INFO* pOccDialogInfo) override
		_PPMFC_THISCALL(0x551D5E);

	virtual int DoModal()
		_PPMFC_THISCALL(0x551E20);

	virtual BOOL OnInitDialog()
		_PPMFC_THISCALL(0x5520A8);

	virtual void OnSetFont(CFont* pFont) RX;

	virtual void OnOK()
		_PPMFC_THISCALL(0x55210D);

	virtual void OnCancel()
		_PPMFC_THISCALL(0x552126);

	virtual void PreInitDialog() RX;

	// normal functions

	BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = nullptr)
		_PPMFC_THISCALL(0x551A5B);

	BOOL Create(UINT nIDTemplate, CWnd* pParentWnd)
		{ return Create(MAKEINTRESOURCE(nIDTemplate), pParentWnd); }

	void EndDialog(int nResult)
		_PPMFC_THISCALL(0x551F80);

public:
	UINT m_nIDHelp;
	LPCTSTR m_lpszTemplateName;
	HGLOBAL m_hDialogTemplate;
	LPCDLGTEMPLATE m_lpDialogTemplate;
	void* m_lpDialogInit;
	CWnd* m_pParentWnd;
	HWND m_hWndTop;
	_AFX_OCC_DIALOG_INFO* m_pOccDialogInfo;
};

_PPMFC_END