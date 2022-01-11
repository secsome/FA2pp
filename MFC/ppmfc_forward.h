#pragma once

#include <WinNT.h>
#include <WinDef.h>
#include <CommCtrl.h>

#include "../FA2PPCore.h"

#ifndef _PPMFC
#define _PPMFC ppmfc
#endif // _PPMFC

#ifndef _PPMFC_BEGIN
#define _PPMFC_BEGIN namespace _PPMFC {
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

#ifndef _PPMFC_API
#define _PPMFC_API __stdcall
#endif // _PPMFC_API

#define MAX(a,b) a>b?a:b;
#define MIN(a,b) a<b?a:b;

_PPMFC_BEGIN

typedef LONG HRESULT;

struct IUnknown;
typedef IUnknown* LPUNKNOWN;

struct IDispatch;
typedef IDispatch* LPDISPATCH;

struct IConnectionPoint;
typedef IConnectionPoint* LPCONNECTIONPOINT;

struct IEnumOLEVERB;
typedef IEnumOLEVERB* LPENUMOLEVERB;

struct ITypeLib;
typedef ITypeLib* LPTYPELIB;

typedef struct _GUID GUID;
typedef GUID IID;
typedef GUID CLSID;

struct CRuntimeClass;

_PPMFC_CLASS(CObject)
{
private:
public:
    virtual CRuntimeClass* GetRuntimeClass() { return reinterpret_cast<CRuntimeClass*>(0x59D988); }
    virtual ~CObject() {}
    virtual void Serialize(const CArchive* ar) {};
};

_PPMFC_STRUCT(CRuntimeClass)
{
    LPCSTR m_lpszClassName;
    int m_nObjectSize;
    UINT m_wSchema;
    CObject* (PASCAL * m_pfnCreateObject)();
    CRuntimeClass* m_pBaseClass;
    CRuntimeClass* m_pNextClass;
};

_PPMFC_CLASS(CRect) _PPMFC_INHERIT(tagRECT)
{
public:
};

_PPMFC_CLASS(CSize) _PPMFC_INHERIT(tagSIZE)
{
public:
};

_PPMFC_CLASS(CPoint) _PPMFC_INHERIT(tagPOINT)
{
public:
    CPoint(DWORD dwPoint) _PPMFC_THISCALL(0x5338A9);
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