#pragma once

#include "FA2PP.h"

class ImageDataClass;

class CTileBlockClass
{
public:
    

    ImageDataClass* AnotherImage;
    ImageDataClass* NormalImage;
    void* Pointer_8;
    int Unknown_C;
    int Unknown_10;
    unsigned __int8 Height;
    unsigned __int8 Byte_15;
    unsigned __int8 Byte_16;
    unsigned __int8 ColorLeft_Red;
    unsigned __int8 ColorLeft_Green;
    unsigned __int8 ColorLeft_Blue;
    unsigned __int8 ColorRight_Red;
    unsigned __int8 ColorRight_Green;
    unsigned __int8 ColorRight_Blue;
    unsigned __int8 Byte_1D;
    unsigned __int8 Byte_1E;
    unsigned __int8 Byte_1F;
};

struct CTileTypeClass
{
public:
    static constexpr reference<CTileTypeClass**, 0x7EE070> const Instance{};
    static constexpr reference<CTileTypeClass**, 0x7EE070> const CurrentTileType{};
    static constexpr reference<int*, 0x7EE074> const InstanceCount{};
    static constexpr reference<int*, 0x7EE074> const CurrentTileTypeCount{};

    int TileSet;
    CTileBlockClass* SubTileDatas;
    __int16 SubTileCount;
    __int16 Short_A;
    int Unknown_C;
    int Unknown_10;
    int Unknown_14;
    int Unknown_18;
    int Unknown_1C;
    int Unknown_20;
    int Unknown_24;
    int Unknown_28;
    int Unknown_2C;
    int Unknown_30;
    int Unknown_34;
    CTileTypeClass* SomeData;
    unsigned __int8 SomeCount;
    unsigned __int8 Byte_3D;
    unsigned __int8 Byte_3E;
    unsigned __int8 Byte_3F;
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