#pragma once

#include <FA2PP.h>

class NOVTABLE CliffPainterBase2
{
public:
    CliffPainterBase2() { JMP_THIS(0x4CE670); }

protected:
    CliffPainterBase2(noinit_t) {}
};

class NOVTABLE CliffPainterBase : public CliffPainterBase2
{
public:
    CliffPainterBase() { JMP_THIS(0x4F1830); }

protected:
    CliffPainterBase(noinit_t) : CliffPainterBase2(noinit_t()) {}
};

class NOVTABLE CliffPainter : public CliffPainterBase
{
public:
    virtual ~CliffPainter() RX;
    virtual void Update(int StartY, int StartX, int EndY, int EndX, bool bUseAltData) RX;
    virtual ppmfc::CString* GetDataSectionName(ppmfc::CString* pRet) R0;
    virtual void Next(int* pY, int* pX, bool bUnknown) RX;
    virtual void Next2(int* pIndex, int nUnk = 0) RX;
    virtual int GetCliff(int, bool* pbFlag) R0;

    CliffPainter() { JMP_THIS(0x41B200); }

    int EndCellIndex;
    int StartCellIndex;
    int Direction;
    int DY;
    int DX;
    bool UseAltData;

protected:
    CliffPainter(noinit_t) : CliffPainterBase(noinit_t()) {}
};

class NOVTABLE CliffFrontPainter : public CliffPainter
{
public:
    CliffFrontPainter() { JMP_THIS(0x43C1C0); }

protected:
    CliffFrontPainter(noinit_t) : CliffPainter(noinit_t()) {}
};

class NOVTABLE CliffBackPainter : public CliffPainter
{
public:
    CliffBackPainter() { JMP_THIS(0x40DB80); }

protected:
    CliffBackPainter(noinit_t) : CliffPainter(noinit_t()) {}
};