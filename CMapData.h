#pragma once

#include <CINI.h>
#include <CObjectDatas.h>
#include <CPalette.h>

#include <Structures/FAVector.h>

struct CellData_BaseNodeData
{
    int BuildingID;
    int BasenodeID;
    ppmfc::CString House;
};

struct CellData
{
    short Unit;
    short Infantry[3];
    short Aircraft;
    short Structure;
    short TypeListIndex; // for BuildingType, it's -65536+{idx in list}, for TerrainType, it's some fucking number, or it's -1
    short Terrain;
    int TerrainType;
    short Smudge;
    int SmudgeType;
    short Waypoint;
    CellData_BaseNodeData BaseNode;
    unsigned char Overlay;
    unsigned char OverlayData; // [0, 59]
    short TileIndex;
    short Short_30;
    unsigned char TileSubIndex;
    unsigned char Height;
    unsigned char IceGrowth;
    short CellTag;
    short Tube;
    unsigned char TubeDataIndex;
    unsigned char StatusFlag;
    unsigned char LAT; // uses high 4 bit, see https://modenc.renegadeprojects.com/images/ConnectingLATSetSubTileSelection.png
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

struct StructureData
{
    ColorStruct HouseColor;
    ppmfc::CString ID;
    short Y;
    short X;
    short Facing;
    unsigned char Strength;
    unsigned char PowerUpCount;
    ppmfc::CString PowerUp1;
    ppmfc::CString PowerUp2;
    ppmfc::CString PowerUp3;
};

struct TubeData
{
    __int16 Unknown_0;
    __int16 DestY;
    __int16 DestX;
    __int16 TubeDir;
    __int16 Unknown_8; // X related?
    char Data[102];
};

class NOVTABLE CMapData
{
public:
    static constexpr reference<CMapData, 0x72CBF8> const Instance{};

    static constexpr reference<bool, 0x5E7C08> const MapNotLoaded{};

    static constexpr reference<int, 0x5E7C54> const WaterSet{};
    static constexpr reference<int, 0x5E7C68> const SlopeSetPieces{};
    static constexpr reference<int, 0x5E7C6C> const RampSmooth{};
    static constexpr reference<int, 0x5E7C70> const CliffSetCount{};
    static constexpr reference<int, 0x5E7C74> const CliffSet{};
    static constexpr reference<int, 0x5E7C50> const Cliff2{};
    static constexpr reference<int, 0x7EDEF0> const Ramps2Count{};
    static constexpr reference<int, 0x7EDEF4> const Morphable2Count{};
    static constexpr reference<int, 0x7EDEF8> const Morphable2{};
    static constexpr reference<int, 0x7EDEFC> const Ramps2{};
    static constexpr reference<int, 0x7EDF00> const RampBase{};
    static constexpr reference<int, 0x7EDF04> const RampBaseCount{};

    void UpdateMapFieldData(bool bFlag) { JMP_THIS(0x49C280); }
    CINI* UpdateCurrentDocument() { JMP_THIS(0x49C260); }
    static CINI* GetMapDocument(bool bUpdateMapField = false)
    {
        if (bUpdateMapField)
            Instance->UpdateMapFieldData(1);
        return &Instance->INI;
    }

    const wchar_t* QueryUIName(const char* pRegName) { JMP_THIS(0x4B2610); }
    static ppmfc::CString GetUIName(const char* pRegName) { return ppmfc::CString(Instance->QueryUIName(pRegName)); }

    void LoadMap(const char* pMapPath) { JMP_THIS(0x49D2C0); }
    void UnpackData() { JMP_THIS(0x49EE50); } // called in LoadMap

    void InitializeBuildingTypes(const char* ID) { JMP_THIS(0x4B5460); } // use nullptr to reload all

    // FA2 magics
    int GetCoordIndex(int X, int Y) { return Y + X * MapWidthPlusHeight; }  
    int GetXFromCoordIndex(int CoordIndex) { return CoordIndex / MapWidthPlusHeight; }
    int GetYFromCoordIndex(int CoordIndex) { return CoordIndex % MapWidthPlusHeight; }

    void GetStructureData(int structureID, StructureData* pRet) { JMP_THIS(0x4C3C20); }
    TubeData* GetTubeData(int tubeID) { JMP_THIS(0x4753C0); }

    ppmfc::CString* FindAvailableOwner(ppmfc::CString* buffer, int nUnknown, bool bUseCountries)
    {
        JMP_THIS(0x49B2D0);
    }
    ppmfc::CString FindAvailableOwner(int nUnknown, bool bUseCountries)
    {
        ppmfc::CString ret;
        this->FindAvailableOwner(&ret, nUnknown, bUseCountries);
        return ret;
    }

    ppmfc::CString StringBuffer;
    BOOL Initialized; // Maybe? It's data related, if this is false, UnitData, StructureData and so on will be called for loading?
    int MapWidthPlusHeight;
    CellData TempCellData;
    BOOL FieldDataAllocated;
    FAVector<int> BuildingTypes;
    FAVector<int> TerrainTypes;
    FAVector<int> UnitTypes;
    unsigned char Overlay[0x40000];
    unsigned char OverlayData[0x40000];
    TileStruct* IsoPackData;
    int IsoPackDataCount;
    CINI INI;
    RECT Size;
    RECT LocalSize;
    CellData* CellDatas; // see 4BB920 validate the map, dtor at 416FC0
    int CellDataCount; // see 4BB920 validate the map
    void* UndoRedoData;
    int UndoRedoDataCount; // undo redo count related
    int UndoRedoCurrentDataIndex; // undo redo count related, UndoRedoDataCount - 1
    int MoneyCount;
    FAVector<StructureData> StructureDatas; // being used in 4C3C20
    FAVector<TubeData> TubeDatas; // see 4753C0, might be TUBE related
    FAVector<int> vector_801F8;
    FAVector<CTerrainData> TerrainDatas;
    FAVector<CInfantryData> InfantryDatas;
    FAVector<CUnitData> UnitDatas; // Seems never used except DTOR
    FAVector<int> vector_80238;    // Seems never used except DTOR
    unsigned char MapPreview[0x40000];
    BITMAPINFO MapPreviewInfo;
    int nSomeMapPreviewData_C0274;
    CINI SomeTheaterINI; //maybe?
    int Unknown_C0380;
    int Unknown_C0384;
    int Unknown_C0388;
    int Unknown_C038C;
};
