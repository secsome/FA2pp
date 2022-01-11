#pragma once

#include "ppmfc_cwinthread.h"

_PPMFC_BEGIN

// forward declarations
class CDocManager;
class CRecentFileList;
class CCommandLineInfo;
class CCmdUI;

_PPMFC_CLASS(CWinApp) _PPMFC_INHERIT(CWinThread)
{
public:

	CWinApp(LPCTSTR lpszAppName = nullptr) _PPMFC_THISCALL(0x564C30);

    // virtual functions
    virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59BDA8); }

    virtual ~CWinApp() override _PPMFC_THISCALL(0x564D7A);

	virtual BOOL InitInstance() override
		_PPMFC_THISCALL(0x564D76);

	virtual int Run() override
		_PPMFC_THISCALL(0x556630);

	virtual BOOL OnIdle(LONG lCount) override
		_PPMFC_THISCALL(0x556700);

	virtual int ExitInstance() override
		_PPMFC_THISCALL(0x564EE0);

	virtual LRESULT ProcessWndProcException(CException* e, const MSG* pMsg) override
		_PPMFC_THISCALL(0x556689);

	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName)
		_PPMFC_THISCALL(0x55A9E8);

	virtual void AddToRecentFileList(LPCTSTR lpszPathName)
		_PPMFC_THISCALL(0x55A9D2);

	virtual BOOL InitApplication()
		_PPMFC_THISCALL(0x564D36);

	virtual BOOL SaveAllModified()
		_PPMFC_THISCALL(0x55A9BF);

	virtual int DoMessageBox(LPCTSTR lpszPrompt, UINT nType, UINT nIDPrompt)
		_PPMFC_THISCALL(0x55AAAD);

	virtual void DoWaitCursor(int nCode) // 0 => restore, 1=> begin, -1=> end
		_PPMFC_THISCALL(0x55A960);

	virtual BOOL OnDDECommand(LPTSTR lpszCommand)
		_PPMFC_THISCALL(0x55AA32);

	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT)
		_PPMFC_THISCALL(0x556652);

	// normal functions
	void DevModeChange(LPTSTR lpDeviceName)
		_PPMFC_THISCALL(0x55676A);

	void OnAppExit()
		_PPMFC_THISCALL(0x558E09);

	void OnHelp()
		_PPMFC_THISCALL(0x55A8EA);

	void HideApplication()
		_PPMFC_THISCALL(0x55A92E);

	void CloseAllDocuments(BOOL bEndSession)
		_PPMFC_THISCALL(0x55A9FA);

	void OnUpdateRecentFileMenu(CCmdUI* pCmdUI)
		_PPMFC_THISCALL(0x55AA10);

	BOOL OnOpenRecentFile(UINT nID)
		_PPMFC_THISCALL(0x55AA4C);

	void EnableModeless(BOOL bEnable)
		_PPMFC_THISCALL(0x55AA7F);

	BOOL WriteProfileInt(LPCTSTR lpszSection, LPCTSTR lpszEntry, int nValue)
		_PPMFC_THISCALL(0x55FE02);

	void SaveStdProfileSettings()
		_PPMFC_THISCALL(0x564EB0);

	HKEY GetAppRegistryKey()
		_PPMFC_THISCALL(0x5665FD);

	HKEY GetSectionKey(LPCTSTR lpszSection)
		_PPMFC_THISCALL(0x566691);

	void SetCurrentHandles()
		_PPMFC_THISCALL(0x566746);

public:
	HINSTANCE m_hInstance;
	HINSTANCE m_hPrevInstance;
	LPTSTR m_lpCmdLine;
	int m_nCmdShow;
	LPCTSTR m_pszAppName;
	LPCTSTR m_pszRegistryKey;
	CDocManager* m_pDocManager;
	BOOL m_bHelpMode;
	LPCTSTR m_pszExeName;       // executable name (no spaces)
	LPCTSTR m_pszHelpFilePath;  // default based on module path
	LPCTSTR m_pszProfileName;   // default based on app name
	HGLOBAL m_hDevMode;             // printer Dev Mode
	HGLOBAL m_hDevNames;            // printer Device Names
	DWORD m_dwPromptContext;        // help context override for message box
	int m_nWaitCursorCount;         // for wait cursor (>0 => waiting)
	HCURSOR m_hcurWaitCursorRestore; // old cursor to restore after wait cursor
	CRecentFileList* m_pRecentFileList;
	CCommandLineInfo* m_pCmdInfo;
	ATOM m_atomApp, m_atomSystemTopic;   // for DDE open
	UINT m_nNumPreviewPages;        // number of default printed pages
	size_t  m_nSafetyPoolSize;      // ideal size
	void (_PPMFC_API* m_lpfnDaoTerm)();
};

_PPMFC_END