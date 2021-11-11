#pragma once

#include "FA2PP.h"

#include "Drawing.h"

class ImageDataClass;

enum LandType : char
{
    Clear0 = 0x0,
    Clear1 = 0x1,
    Clear13 = 0xD,
    Ice0 = 0x0,
    Ice1 = 0x1,
    Ice2 = 0x2,
    Ice3 = 0x3,
    Ice4 = 0x4,
    Tunnel = 0x5,
    Railroad = 0x6,
    Rock7 = 0x7,
    Rock8 = 0x8,
    CliffRock = 0xF,
    Water = 0x9,
    Beach = 0xA,
    Road11 = 0xB,
    Road12 = 0xC,
    Rough = 0xE,
    Cliff = 0xF,
};

class CTileBlockClass
{
public:
    BOOL HasValidImage;
    unsigned char* ImageData; // Had been drawn already at 48E9E7
    struct ValidRangeData
    {
        short First;
        short Last;
    } *pPixelValidRanges;
    short BlockWidth;
    short BlockHeight;
    short XMinusExX;
    short YMinusExY;
    unsigned char Height;
    unsigned char RampType;
    LandType TerrainType;
    RGBClass RadarColorLeft;
    RGBClass RadarColorRight;
    LandType TerrainTypeAlt; // Beach -> Water, Rough->Clear13, ShoreTerrainRA2/TS -> Water/Rough, WaterSet -> Water

    PROTECTED_PROPERTY(char, align_1E[2]);
};

struct NOVTABLE CTileTypeClass
{
public:
    static constexpr reference<CTileTypeClass**, 0x7EE070> const Instance{};
    static constexpr reference<CTileTypeClass**, 0x7EE070> const CurrentTileType{};
    static constexpr reference<int*, 0x7EE074> const InstanceCount{};
    static constexpr reference<int*, 0x7EE074> const CurrentTileTypeCount{};

    static int GetTileIndex(int nTileSet, int nTileBlock) { JMP_STD(0x4F2620); }

    int TileSet;
    CTileBlockClass* TileBlockDatas;
    unsigned short TileBlockCount;
    short Height;
    short Width;
    
    PROTECTED_PROPERTY(unsigned char, align_E[2]);
    
    int AllowTiberium;
    int AllowToPlace;
    int Morphable;
    BOOL IsHidden; // Is this tileset being hidden, which means which being drawn transparently
    int NonMarbleMadness;
    unsigned short FrameModeIndex;

    PROTECTED_PROPERTY(unsigned char, align_26[2]);

    RECT Bounds; // The pixel range
    CTileTypeClass* AltTypes; // clear01a, clear01b, clear01c and so on
    unsigned char AltTypeCount; // we have 3 if ends to 'c'

    PROTECTED_PROPERTY(unsigned char, align_3D[3]);
};

struct CTileTypeInfo
{
    static constexpr reference<CTileTypeInfo, 0x7EE040> const Temperate{};
    static constexpr reference<CTileTypeInfo, 0x7EE048> const Snow{};
    static constexpr reference<CTileTypeInfo, 0x7EE050> const Urban{};
    static constexpr reference<CTileTypeInfo, 0x7EE058> const NewUrban{};
    static constexpr reference<CTileTypeInfo, 0x7EE060> const Lunar{};
    static constexpr reference<CTileTypeInfo, 0x7EE068> const Desert{};

    CTileTypeClass* Datas;
    int Count;
};