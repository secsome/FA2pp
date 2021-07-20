#pragma once

#include "FA2PP.h"

struct ShapeHeader
{
    short Type;
    short Width;
    short Height;
    short FrameCount;
};

struct ShapeImageHeader
{
    short X;
    short Y;
    short Width;
    short Height;
    int Compression;
    int Unknown;
    int Zero;
    int Offset;
};

struct ShapeFileStruct
{
    ShapeHeader Header;
    ShapeImageHeader* FrameHeaders;
};


class CShpFile
{
public:
    static bool __cdecl GetSHPHeader(ShapeHeader* pHeader) { JMP_STD(0x525A30); }
    static bool __cdecl LoadFrame(int nFrame, int nFrameCount, unsigned char** ppBuffer) { JMP_STD(0x526020); }
};