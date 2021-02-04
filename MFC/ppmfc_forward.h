#pragma once

#include <Windows.h>
#include "../FA2PPCore.h"

#ifndef _PPMFC
#define _PPMFC namespace ppmfc
#endif // _PPMFC

#ifndef _PPMFC_BEGIN
#define _PPMFC_BEGIN _PPMFC {
#endif // __PPMFC_BEGIN

#ifndef _PPMFC_END
#define _PPMFC_END }
#endif // __PPMFC_END

#ifndef _PPMFC_CLASS
#define _PPMFC_CLASS(clsname) class NOVTABLE clsname
#endif // _PPMFC_CLASS

#ifndef _PPMFC_STRUCT
#define _PPMFC_STRUCT(clsname) struct clsname
#endif // _PPMFC_STRUCT

#ifndef _PPMFC_INHERIT
#define _PPMFC_INHERIT(clsname) : public clsname
#endif // _PPMFC_INHERIT

#ifndef _PPMFC_THISCALL
#define _PPMFC_THISCALL(addr) { JMP_THIS(addr); }
#endif // _PPMFC_THISCALL

#ifndef _PPMFC_STDCALL
#define _PPMFC_STDCALL(addr) { JMP_STD(addr); }
#endif // _PPMFC_STDCALL

_PPMFC_BEGIN

_PPMFC_CLASS(CObject)
{
private:
public:
    void* vfptr;
};

_PPMFC_STRUCT(XDispatch)
{
    DWORD m_vtbl;
};

_PPMFC_STRUCT(XConnPtContainer)
{
    DWORD m_vtbl;
};

_PPMFC_END