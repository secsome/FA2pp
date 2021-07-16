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
    ColorStruct GetByteColor(int index) { // It's BGR color
        ColorStruct ret;
        struct BGRStruct { unsigned char B, G, R, Zero; };
        BGRStruct& tmp = *(BGRStruct*)&Data[index];
        ret.red = tmp.R;
        ret.green = tmp.G;
        ret.blue = tmp.B;
        return ret;
    }
};