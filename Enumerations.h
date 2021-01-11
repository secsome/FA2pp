#pragma once

enum class FADrawingFlag : __int32
{
    Nothing = 0x0,
    ObjectPlace = 0x1,
    ObjectDelete = 0x2,
    WaypointHandle = 0x3,
    CelltagHandle = 0x4,
    BasenodeHandle = 0x5,
    TunnelHandle = 0x6,
    TileDraw = 0xA,
    HeightenGround = 0xB,
    LowerGround = 0xC,
    LowerSingleTile = 0xD,
    RaiseSingleTile = 0xE,
    MakeTerrainFlat = 0xF,
    HideTileSet = 0x10,
    HideSingleField = 0x11,
    PaintCliffFront = 0x12,
    PaintCliffBack = 0x13,
    TileCopy = 0x14,
    TilePaste = 0x15,
    TerrainRandom = 0x16,
};
