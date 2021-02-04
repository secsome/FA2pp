#pragma once

#include "ppmfc_ccmdtarget.h"

_PPMFC_BEGIN

// forward declarations
class COleDropTarget;
class CCreateContext;
class CString;
class CFrameWnd;
class CDC;
class COleControlSite;
class CHandleMap;

_PPMFC_CLASS(CWnd) _PPMFC_INHERIT(CCmdTarget)
{
public:
    CWnd() _PPMFC_THISCALL(0x55231D);
    CWnd(HWND hWnd) _PPMFC_THISCALL(0x55235B);
    ~CWnd() _PPMFC_THISCALL(0x552DF7);

    CWnd* GetOwner() const
        _PPMFC_THISCALL(0x5336A0);

    BOOL EnableToolTips(BOOL bEnable = TRUE)
        _PPMFC_THISCALL(0x550A93);

    void FilterToolTipMessage(MSG * pMsg)
        _PPMFC_THISCALL(0x550B23);

    BOOL CreateDlg(LPCTSTR lpszTemplateName, CWnd * pParentWnd)
        _PPMFC_THISCALL(0x551AF8);

    BOOL CreateDlgIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd * pParentWnd,
        HINSTANCE hInst)
        _PPMFC_THISCALL(0x551B3C);

    static BOOL PASCAL ModifyStyle(HWND hWnd, DWORD dwRemove, DWORD dwAdd,
        UINT nFlags)
        _PPMFC_STDCALL(0x5523D6);

    static BOOL PASCAL ModifyStyleEx(HWND hWnd, DWORD dwRemove, DWORD dwAdd,
        UINT nFlags)
        _PPMFC_STDCALL(0x5523F0);

    static const MSG* PASCAL GetCurrentMessage()
        _PPMFC_STDCALL(0x552670);

    LRESULT Default()
        _PPMFC_THISCALL(0x5526A5);

    static CWnd* PASCAL FromHandle(HWND hWnd)
        _PPMFC_STDCALL(0x55273E);

    BOOL Attach(HWND hWndNew)
        _PPMFC_THISCALL(0x552783);

    HWND Detach()
        _PPMFC_THISCALL(0x5527BC);

    BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,
        LPCTSTR lpszWindowName, DWORD dwStyle,
        const RECT & rect,
        CWnd * pParentWnd, UINT nID,
        LPVOID lpParam = NULL)
        _PPMFC_THISCALL(0x552C7E);

    BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,
        LPCTSTR lpszWindowName, DWORD dwStyle,
        int x, int y, int nWidth, int nHeight,
        HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam = NULL)
        _PPMFC_THISCALL(0x552CC5);

    virtual BOOL PreCreateWindow(CREATESTRUCT & cs)
        _PPMFC_STDCALL(0x552D8B);

    virtual BOOL Create(LPCTSTR lpszClassName,
        LPCTSTR lpszWindowName, DWORD dwStyle,
        const RECT & rect,
        CWnd * pParentWnd, UINT nID,
        CCreateContext * pContext = NULL)
        _PPMFC_THISCALL(0x552DAB);

    void OnDestroy()
        _PPMFC_THISCALL(0x552E73);

    void OnNcDestroy()
        _PPMFC_THISCALL(0x552E91);

    virtual void OnFinalRelease()
        _PPMFC_THISCALL(0x552FA4);

    virtual BOOL DestroyWindow()
        _PPMFC_THISCALL(0x552FB5);

    virtual LRESULT DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x553002);

    virtual BOOL PreTranslateMessage(MSG * pMsg)
        _PPMFC_THISCALL(0x55304D);

    static void PASCAL CancelToolTips(BOOL bKeys = FALSE)
        _PPMFC_STDCALL(0x55306C);

    virtual int OnToolHitTest(CPoint point, TOOLINFO * pTI) const
        _PPMFC_THISCALL(0x5530C3);

    void GetWindowText(CString & rString) const
        _PPMFC_THISCALL(0x553134);

    void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
        _PPMFC_THISCALL(0x55317C);

    int OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct)
        _PPMFC_THISCALL(0x5531B9);

    void OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct)
        _PPMFC_THISCALL(0x5531E3);

    void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
        _PPMFC_THISCALL(0x553291);

    LRESULT OnNTCtlColor(WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x55345E);

    virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT)
        _PPMFC_THISCALL(0x5534A4);

    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x5535CC);

    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
        _PPMFC_THISCALL(0x553610);

    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x553BAC);

    virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
        _PPMFC_THISCALL(0x553C38);

    CFrameWnd* GetParentFrame() const
        _PPMFC_THISCALL(0x553CB2);

    CWnd* GetTopLevelParent() const
        _PPMFC_THISCALL(0x553D35);

    CWnd* GetParentOwner()
        _PPMFC_THISCALL(0x553D5D);

    BOOL IsTopParentActive() const
        _PPMFC_THISCALL(0x553DA1);

    void ActivateTopParent()
        _PPMFC_THISCALL(0x553DD5);

    CFrameWnd* GetTopLevelFrame() const
        _PPMFC_THISCALL(0x553E12);

    int MessageBox(LPCTSTR lpszText, LPCTSTR lpszCaption = NULL,
        UINT nType = MB_OK)
        _PPMFC_THISCALL(0x553E53);

    static CWnd* PASCAL GetDescendantWindow(HWND hWnd, int nID,
        BOOL bOnlyPerm)
        _PPMFC_STDCALL(0x553E85);

    static void PASCAL SendMessageToDescendants(HWND hWnd, UINT message,
        WPARAM wParam, LPARAM lParam, BOOL bDeep, BOOL bOnlyPerm)
        _PPMFC_STDCALL(0x553EFE);

    int SetScrollPos(int nPos, BOOL bRedraw = TRUE)
        _PPMFC_THISCALL(0x553F7B);

    int GetScrollPos(int nBar) const
        _PPMFC_THISCALL(0x553FAB);

    void SetScrollRange(int nBar, int nMinPos, int nMaxPos,
        BOOL bRedraw = TRUE)
        _PPMFC_THISCALL(0x5553FD3);

    void GetScrollRange(int nBar, LPINT lpMinPos, LPINT lpMaxPos) const
        _PPMFC_THISCALL(0x554006);

    void EnableScrollBarCtrl(int nBar, BOOL bEnable = TRUE)
        _PPMFC_THISCALL(0x554036);

    BOOL SetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo,
        BOOL bRedraw = TRUE)
        _PPMFC_THISCALL(0x554079);

    BOOL GetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, UINT nMask = SIF_ALL)
        _PPMFC_THISCALL(0x5540C6);

    int GetScrollLimit(int nBar)
        _PPMFC_THISCALL(0x554113);

    void ScrollWindow(int xAmount, int yAmount,
        LPCRECT lpRect = NULL,
        LPCRECT lpClipRect = NULL)
        _PPMFC_THISCALL(0x55415A);

    enum RepositionFlags
        { reposDefault = 0, reposQuery = 1, reposExtra = 2 };
    void RepositionBars(UINT nIDFirst, UINT nIDLast, UINT nIDLeftOver,
        UINT nFlag = reposDefault, LPRECT lpRectParam = NULL,
        LPCRECT lpRectClient = NULL, BOOL bStretch = TRUE)
        _PPMFC_THISCALL(0x554200);

    enum AdjustType { adjustBorder = 0, adjustOutside = 1 };
    virtual void CalcWindowRect(LPRECT lpClientRect,
        UINT nAdjustType = adjustBorder)
        _PPMFC_THISCALL(0x5543D4);

    static BOOL PASCAL WalkPreTranslateTree(HWND hWndStop, MSG* pMsg)
        _PPMFC_STDCALL(0x5543FF);

    BOOL SendChildNotifyLastMsg(LRESULT* pResult = NULL)
        _PPMFC_THISCALL(0x554441);

    static BOOL PASCAL ReflectLastMsg(HWND hWndChild, LRESULT* pResult = NULL)
        _PPMFC_STDCALL(0x55446E);

    virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
        _PPMFC_THISCALL(0x554512);

    BOOL ReflectChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
        _PPMFC_THISCALL(0x55456D);

    void OnParentNotify(UINT message, LPARAM lParam)
        _PPMFC_THISCALL(0x554655);

    LRESULT OnActivateTopLevel(WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x554682);

    void OnSysColorChange()
        _PPMFC_THISCALL(0x5546A4);

    void OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
        _PPMFC_THISCALL(0x554721);

    void OnDevModeChange(LPTSTR lpDeviceName)
        _PPMFC_THISCALL(0x554774);

    BOOL OnHelpInfo(HELPINFO* lpHelpInfo)
        _PPMFC_THISCALL(0x5547BF);

    LRESULT OnDisplayChange(WPARAM, LPARAM)
        _PPMFC_THISCALL(0x554823);

    LRESULT OnDragList(WPARAM, LPARAM)
        _PPMFC_THISCALL(0x55486C);

    void OnEnterIdle(UINT nWhy, CWnd* pWho)
        _PPMFC_THISCALL(0x5548B7);

    HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
        _PPMFC_THISCALL(0x554901);

    HBRUSH OnGrayCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
        _PPMFC_THISCALL(0x554928);

    static BOOL PASCAL GrayCtlColor(HDC hDC, HWND hWnd, UINT nCtlColor,
        HBRUSH hbrGray, COLORREF clrText)
        _PPMFC_STDCALL(0x55498B);

    LRESULT OnQuery3dControls(WPARAM, LPARAM)
        _PPMFC_THISCALL(0x554A00);

    BOOL UpdateData(BOOL bSaveAndValidate = TRUE)
        _PPMFC_THISCALL(0x554A08);

    void CenterWindow(CWnd* pAlternateOwner = NULL)
        _PPMFC_THISCALL(0x554AC0);

    BOOL ExecuteDlgInit(LPCTSTR lpszResourceName)
        _PPMFC_THISCALL(0x554C75);

    BOOL ExecuteDlgInit(LPVOID lpResource)
        _PPMFC_THISCALL(0x554CC5);

    void UpdateDialogControls(CCmdTarget* pTarget, BOOL bDisableIfNoHndler)
        _PPMFC_THISCALL(0x554D97);

    BOOL PreTranslateInput(LPMSG lpMsg)
        _PPMFC_THISCALL(0x554E9C);

    int RunModalLoop(DWORD dwFlags = 0)
        _PPMFC_THISCALL(0x554ECC);

    virtual BOOL ContinueModal()
        _PPMFC_THISCALL(0x55502B);

    virtual void EndModalLoop(int nResult)
        _PPMFC_THISCALL(0x555032);

    BOOL SubclassWindow(HWND hWnd)
        _PPMFC_THISCALL(0x5553E9);

    virtual BOOL OnAmbientProperty(COleControlSite* pSite, DISPID dispid,
        VARIANT* pvar)
        _PPMFC_THISCALL(0x55543B);

    CWnd* GetDlgItem(int nID) const
        _PPMFC_THISCALL(0x555452);

    void GetDlgItem(int nID, HWND* phWnd) const
        _PPMFC_THISCALL(0x55547C);

    void SetDlgItemText(int nID, LPCTSTR lpszString)
        _PPMFC_THISCALL(0x5554AA);

    BOOL IsDialogMessage(LPMSG lpMsg)
        _PPMFC_THISCALL(0x5554D9);

    DWORD GetStyle() const
        _PPMFC_THISCALL(0x55550C);

    DWORD GetExStyle() const
        _PPMFC_THISCALL(0x555526);

    BOOL ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0)
        _PPMFC_THISCALL(0x555540);

    BOOL ModifyStyleEx(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0)
        _PPMFC_THISCALL(0x555571);

    void SetWindowText(LPCTSTR lpszString)
        _PPMFC_THISCALL(0x5555A2);

    int GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) const
        _PPMFC_THISCALL(0x5555C9);

    int GetDlgCtrlID() const
        _PPMFC_THISCALL(0x5555F8);

    int SetDlgCtrlID(int nID)
        _PPMFC_THISCALL(0x555613);

    BOOL SetWindowPos(const CWnd* pWndInsertAfter, int x, int y,
        int cx, int cy, UINT nFlags)
        _PPMFC_THISCALL(0x55563C);

    BOOL ShowWindow(int nCmdShow)
        _PPMFC_THISCALL(0x55568B);

    BOOL IsWindowEnabled() const
        _PPMFC_THISCALL(0x5556B2);

    BOOL EnableWindow(BOOL bEnable = TRUE)
        _PPMFC_THISCALL(0x5556CD);

    CWnd* SetFocus()
        _PPMFC_THISCALL(0x5556F4);

    void AttachControlSite(CHandleMap* pMap)
        _PPMFC_THISCALL(0x555715);

    void AttachControlSite(CWnd* pWndParent)
        _PPMFC_THISCALL(0x555752);

    void ScreenToClient(LPRECT lpRect) const
        _PPMFC_THISCALL(0x558A4A);

    void ClientToScreen(LPRECT lpRect) const
        _PPMFC_THISCALL(0x558A86);

    static CWnd* PASCAL GetSafeOwner(CWnd* pParent = NULL, HWND* pWndTop = NULL)
        _PPMFC_STDCALL(0x55AC25);

    void OnHelp()
        _PPMFC_THISCALL(0x55FD2D);

    static CWnd* _PPMFC_API CreateObject()
        _PPMFC_STDCALL(0x564309);

public:
    HWND m_hWnd;
    HWND m_hWndOwner;
    UINT m_nFlags;
    WNDPROC m_pfnSuper;
    int m_nModalResult;
    COleDropTarget* m_pDropTarget;
    void* m_pCtrlCont;
    void* m_pCtrlSite;
};

_PPMFC_END