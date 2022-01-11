#pragma once

#include "ppmfc_forward.h"

_PPMFC_BEGIN

_PPMFC_CLASS(CPtrList) _PPMFC_INHERIT(CObject)
{
public:
	CPtrList(int nBlockSize = 10) _PPMFC_THISCALL(0x551206);

	virtual CRuntimeClass* GetRuntimeClass() const override { return reinterpret_cast<CRuntimeClass*>(0x59DAC0); }

	virtual ~CPtrList() override _PPMFC_THISCALL(0x551265);

public:
	struct CNode
	{
		CNode* pNext;
		CNode* pPrev;
		void* data;
	};

	CNode* m_pNodeHead;
	CNode* m_pNodeTail;
	int m_nCount;
	CNode* m_pNodeFree;
	struct CPlex* m_pBlocks;
	int m_nBlockSize;
};

_PPMFC_END