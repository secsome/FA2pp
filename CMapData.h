#pragma once

#include <CINI.h>
#include <GlobalVars.h>
#include <CObjectDatas.h>

#include <Structures/FAVector.h>

// need debug to find out what it actually stores
struct TileData
{
    TileData(const TileData& another) { JMP_THIS(0x416EB0); }

    short Short_0;
    short Short_2;
    short Short_4;
    short Short_6;
    int Unknown_8;
    int Unknown_C;
    int Unknown_10;
    short Short_14;
    int Unknown_18;
    short Short_1C;
    int Unknown_20;
    int Unknown_24;
    CString String_28;
    unsigned char Byte_2C;
    unsigned char Byte_2D;
    short Short_2E;
    short Height;
    unsigned char Byte_32;
    unsigned char Byte_33;
    unsigned char Byte_34;
    short Short_36;
    short Unknown_38;
    unsigned char Byte_3A;
    short Flags; // 0, 16, 32, 48, 64
};

#pragma pack(push, 1)
struct TileStruct
{
    short X;
    short Y;
    int TileIndex;
    unsigned char TileSubIndex;
    unsigned char Level;
    unsigned char IceGrowth; // Unused in RA2/YR
};
#pragma pack(pop)

class NOVTABLE CMapData
{
public:

    void UpdateMapFieldData(bool bFlag) { JMP_THIS(0x49C280); }
    INIClass* UpdateCurrentDocument() { JMP_THIS(0x49C260); }
    static INIClass* GetMapDocument(bool bUpdateMapField = false)
    {
        if (bUpdateMapField)
            GlobalVars::CMapData().UpdateMapFieldData(1);
        return &GlobalVars::CMapData().INI;
    }

    const wchar_t* QueryUIName(const char* pRegName) { JMP_THIS(0x4B2610); }
    static ppmfc::CString GetUIName(const char* pRegName) { return ppmfc::CString(GlobalVars::CMapData().QueryUIName(pRegName)); }

    void LoadMap(const char* pMapPath) { JMP_THIS(0x49D2C0); }
    void UnpackData() { JMP_THIS(0x49EE50); } // called in LoadMap


    ppmfc::CString StringBuffer;
    BOOL Initialized; // Maybe? It's data related, if this is false, UnitData, StructureData and so on will be called for loading?
    int MapWidthPlusHeight;
    TileData TempTileData;
    BOOL FieldDataAllocated;
    FAVector<int> BuildingTypes;
    FAVector<int> TerrainTypes;
    FAVector<int> UnitTypes;
    unsigned char OverlayPack[0x40000];
    unsigned char OverlayData[0x40000];
    TileStruct* IsoPackData;
    int IsoPackDataCount;
    INIClass INI;
    RECT Size;
    RECT LocalSize;
    TileData* TileDatas; // tile set realted, see 4BB920 validate the map, looks like tiles, dtor at 416FC0
    int TileDataCount; // tile set realted, see 4BB920 validate the map
    void* UndoRedoData;
    int UndoRedoDataCount; // undo redo count related
    int UndoRedoCurrentDataIndex; // undo redo count related, UndoRedoDataCount - 1
    int MoneyCount;
    FAVector<CStructureData> StructureDatas;
    FAVector<int> vector_801E8;
    FAVector<int> vector_801F8;
    FAVector<CTerrainData> TerrainDatas;
    FAVector<CInfantryData> InfantryDatas;
    FAVector<int> vector_80228;
    FAVector<int> vector_80238;
    unsigned char MapPreview[0x40000];
    BITMAPINFO MapPreviewInfo;
    int nSomeMapPreviewData_C0274;
    INIClass SomeTheaterINI; //maybe?
    int Unknown_C0380;
    int Unknown_C0384;
    int Unknown_C0388;
    int Unknown_C038C;
};
