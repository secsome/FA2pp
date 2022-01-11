#pragma once

#include "FA2PP.h"

class NOVTABLE CInputMessageBox : public ppmfc::CDialog
{
public:
    static ppmfc::CString* __cdecl GetString(ppmfc::CString* pRet, LPCSTR lpMessage, LPCSTR lpTitle) { JMP_THIS(0x456350); }
    static inline void GetString(ppmfc::CString& lpStr, LPCSTR lpMessage, LPCSTR lpTitle) 
    { 
        GetString(&lpStr, lpMessage, lpTitle); 
    }

protected:
    CInputMessageBox() = delete; // No manual construct
    ~CInputMessageBox() { JMP_THIS(0x456460); }

    void SetTitle(ppmfc::CString lpTitle) { JMP_THIS(0x4565C0); }
    void SetMessage(ppmfc::CString lpMessage) { JMP_THIS(0x456610); }

private:
    ppmfc::CString Title;
    ppmfc::CString Message;
};