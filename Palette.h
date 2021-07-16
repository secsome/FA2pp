#pragma once

#include "FA2PP.h"

struct ColorStruct
{
    unsigned char red, green, blue;
};

class BytePalette
{
public:
    ColorStruct Data[256];

    ColorStruct& operator[](int index) { return Data[index]; }
};

class Palette
{
public:
    COLORREF Data[256];

    COLORREF& operator[](int index) { return Data[index]; }
    ColorStruct GetByteColor(int index) {
        ColorStruct ret;
        ret.red = GetRValue(Data[index]);
        ret.green = GetGValue(Data[index]);
        ret.blue = GetBValue(Data[index]);
        return ret;
    }
};