#pragma once

#include <Helpers/EnumFlags.h>

#include <CINI.h>
#include <CObjectDatas.h>
#include <CPalette.h>

#include <Structures/FAVector.h>

enum class SaveMapFlag : int
{
    LoadFromINI = 0x0,
    ValidateMap = 0x1,
    UpdateMapFieldData = 0x2,
    UpdatePreview = 0x4,
    Description = 0x8,
};
MAKE_ENUM_FLAGS(SaveMapFlag);

enum FacingType
{
    FACING_NORTHEAST = 0,
    FACING_EAST,
    FACING_SOUTHEAST,
    FACING_SOUTH,
    FACING_SOUTHWEST,
    FACING_WEST,
    FACING_NORTHWEST,
    FACING_NORTH,
    FACING_COUNT,
    FACING_INVALID = -1
};

struct MapCoord
{
    static const MapCoord Facings[FACING_COUNT];

    auto operator<=>(const MapCoord& another) const = default;

    int X;
    int Y;
};
MapCoord& operator+=(MapCoord& l, const MapCoord& r);
MapCoord operator+(const MapCoord& l, const MapCoord& r);
MapCoord operator*(const MapCoord& coord, int factor);

struct MapRect
{
    int Left;
    int Top;
    int Width;
    int Height;
};

struct CellData
{
private:
    struct BaseNodeData
    {
        BaseNodeData() {}
        BaseNodeData(BaseNodeData& another) { JMP_THIS(0x475420); }
        ~BaseNodeData() {}

        BaseNodeData& operator=(BaseNodeData& another)
        {
            BuildingID = another.BuildingID;
            BasenodeID = another.BasenodeID;
            House = another.House;
            return *this;
        }

        int BuildingID;
        int BasenodeID;
        DECLARE_PROPERTY(ppmfc::CString, House);
    };

public:

    CellData() { JMP_THIS(0x49A120); }
    CellData(const CellData& another) { JMP_THIS(0x416EB0); }
    ~CellData() { JMP_THIS(0x416FC0); }

    CellData& operator=(const CellData& another) { new(this) CellData(another); return *this; }

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
    BaseNodeData BaseNode;
    unsigned char Overlay;
    unsigned char OverlayData; // [0, 59]
    unsigned short TileIndex;
    short Short_30;
    unsigned char TileSubIndex;
    unsigned char Height;
    unsigned char IceGrowth;
    short CellTag;
    short Tube;
    unsigned char TubeDataIndex;
    unsigned char StatusFlag;
    struct CellDataFlag
    {
        char NotAValidCell : 1;
        char IsHiddenCell : 1;
        char IgnoreAltImages : 1;
        char : 1;
        char AltIndex : 4;
    } Flag;
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
    short X;
    short Y;
    short Facing;
    unsigned char Strength;
    unsigned char PowerUpCount;
    ppmfc::CString PowerUp1;
    ppmfc::CString PowerUp2;
    ppmfc::CString PowerUp3;
};

struct TubeData
{
    unsigned short Short_0;
    unsigned short EnterX;
    unsigned short EnterY;
    unsigned short EnterFacing;
    unsigned short ExitX;
    unsigned short ExitY;
    char Directions[100];
};

struct ClipboardHeader
{
    int One_0;          // Not used in paste
    int Zero_4;         // Not used in paste
    int Zero_8;         // Not used in paste
    bool SomeBoolean_C; // Not used in paste
    int Width;
    int Height;
};

struct Clipboard
{
    BOOL IgnoreAltImages;
    unsigned char Overlay;
    unsigned char OverlayData;
    unsigned short TileIndex;
    unsigned short Short_30; // CellData Short_30
    unsigned char TileSubIndex;
    unsigned char Height;
    unsigned char IceGrowth;
    unsigned char Unknown_D; // 221 mostly, dunno what, cannot find it is being used
    unsigned short TileSet;
    unsigned char NthTileSetFile;
};

struct UndoRedoData
{
    int Unknown_0;
    int Unknown_4;
    int Unknown_8;
    int Unknown_C;
    int* Pointer_10;
    int* Pointer_14;
    int* Pointer_18;
    int* Pointer_1C;
    int* Pointer_20;
    int* Pointer_24;
    int* Pointer_28;
    int* Pointer_2C;
    int Unknown_30;
};

class NOVTABLE CMapData
{
public:
    static constexpr reference<CMapData, 0x72CBF8> const Instance{};

    static constexpr reference<bool, 0x5E7C08> const MapNotLoaded{};

    static constexpr reference<int, 0x5E7C48> const CliffWaters2{};
    static constexpr reference<int, 0x5E7C4C> const Cliffs2Count{};
    static constexpr reference<int, 0x5E7C50> const Cliff2{};
    static constexpr reference<int, 0x5E7C54> const WaterSet{};
    static constexpr reference<int, 0x5E7C68> const SlopeSetPieces{};
    static constexpr reference<int, 0x5E7C6C> const RampSmooth{};
    static constexpr reference<int, 0x5E7C70> const CliffSetCount{};
    static constexpr reference<int, 0x5E7C74> const CliffSet{};
    
    static constexpr reference<FAMap<int, int, 0x5D8CB8, 0>, 0x7EDDC8> MarbleMadnessDatas{};

    static constexpr reference<int, 0x7EDDC0> const ShorePieces{};
    static constexpr reference<int, 0x7EDEF0> const Ramps2Count{};
    static constexpr reference<int, 0x7EDEF4> const Morphable2Count{};
    static constexpr reference<int, 0x7EDEF8> const Morphable2{};
    static constexpr reference<int, 0x7EDEFC> const Ramps2{};
    static constexpr reference<int, 0x7EDF00> const RampBase{};
    static constexpr reference<int, 0x7EDF04> const RampBaseCount{};

    void UpdateFieldInfantryData(bool bMapToINI) JMP_THIS(0x4A2AB0); // MapToINI not implemented 
    void UpdateFieldAircraftData(bool bMapToINI) JMP_THIS(0x4A4270); // MapToINI not implemented
    void UpdateFieldStructureData(bool bMapToINI) JMP_THIS(0x4A4A40); // MapToINI not implemented
    void UpdateFieldTerrainData(bool bMapToINI, int nSomeIdx = -1) JMP_THIS(0x4A5850); // MapToINI not implemented
    void UpdateFieldUnitData(bool bMapToINI) JMP_THIS(0x4A6040); // MapToINI not implemented
    void UpdateFieldWaypointData(bool bMapToINI) JMP_THIS(0x4A67D0); // MapToINI not implemented 
    void UpdateFieldBasenodeData(bool bMapToINI) JMP_THIS(0x4A6FB0); // MapToINI not implemented 
    void UpdateFieldOverlayData(bool bMapToINI) JMP_THIS(0x4A7830);
    void UpdateFieldCelltagData(bool bMapToINI) JMP_THIS(0x4A7930); // MapToINI not implemented 
    void UpdateFieldTubeData(bool bMapToINI) JMP_THIS(0x4BA5F0); // MapToINI not implemented 
    void UpdateMapFieldData(bool bMapToINI) JMP_THIS(0x4B4810); // MapToINI not implemented 
    void UpdateFieldSmudgeData(bool bMapToINI, int nSomeIdx = -1) JMP_THIS(0x4C9FA0); // MapToINI not implemented 

    void UpdateSize() { JMP_THIS(0x49AA30); }
    void InitMinimap() { JMP_THIS(0x4C3D40); }
    void UpdateMapPreviewAt(int X, int Y) { JMP_THIS(0x4A23A0); }
    void GetMapPreview(void*& pBuffer, LPBITMAPINFO lpBitmapInfo, int& nStride) { JMP_THIS(0x4C3DF0); }
    void* GetMapPreview(LPBITMAPINFO lpBitmapInfo)
    {
        int nStride;
        void* pRet = nullptr;
        this->GetMapPreview(pRet, lpBitmapInfo, nStride);
        return pRet;
    }

    void ResizeMap(int L, int T, int W, int H) { JMP_THIS(0x4C45F0); }

    void UpdateINIFile(SaveMapFlag eFlags) { JMP_THIS(0x49C280); }
    CINI* UpdateCurrentDocument() { JMP_THIS(0x49C260); }
    static CINI* GetMapDocument(bool bUpdateMapField = false)
    {
        if (bUpdateMapField)
            Instance->UpdateINIFile(SaveMapFlag::ValidateMap);
        return &Instance->INI;
    }

    bool IsMultiOnly() { JMP_THIS(0x4C30C0); }

    const wchar_t* QueryUIName(const char* pRegName) { JMP_THIS(0x4B2610); }
    inline static ppmfc::CString GetUIName(const char* pRegName) { return ppmfc::CString(Instance->QueryUIName(pRegName)); }

    void LoadMap(const char* pMapPath) { JMP_THIS(0x49D2C0); }
    void UnpackData() { JMP_THIS(0x49EE50); } // called in LoadMap

    // use nullptr to reload all
    void InitializeBuildingTypes(const char* ID) { JMP_THIS(0x4B5460); } 
    void InitializeTerrainTypes(const char* ID) { JMP_THIS(0x4B6D00); }
    void InitializeSmudges(const char* ID) { JMP_THIS(0x4CA7E0); }

    void TypesInit_4AD930() { JMP_THIS(0x4AD930); }

    // FA2 magics
    inline int GetCoordIndex(int X, int Y) { return X + Y * MapWidthPlusHeight; }  
    inline int GetXFromCoordIndex(int CoordIndex) { return CoordIndex % MapWidthPlusHeight; }
    inline int GetYFromCoordIndex(int CoordIndex) { return CoordIndex / MapWidthPlusHeight; }
    inline bool IsCoordInMap(int X, int Y)
    {
        return
            X + Y > this->Size.Width &&
            X - Y < this->Size.Width &&
            Y - X < this->Size.Width &&
            X + Y <= this->Size.Width + 2 * this->Size.Height;
    }

    void sub_416550(unsigned nIndex, unsigned int nTileCount, bool bUnk = false) { JMP_THIS(0x416550); }

    void SetStructureData(CStructureData* pData, LPCSTR lpNewTypeID, LPCSTR lpNewHouse, int nCoord, ppmfc::CString Unk1)
        { JMP_THIS(0x4ACB60); }
    void DeleteStructureData(int structureID) { JMP_THIS(0x4A8FB0); }
    void QueryStructureData(int structureID, CStructureData& data) { JMP_THIS(0x4AADB0); }
    void SetInfantryData(CInfantryData* pData, LPCSTR lpNewTypeID, LPCSTR lpNewHouse, int nCoord, int ManualinfID)
        { JMP_THIS(0x4AC210); }
    void DeleteInfantryData(int infID) { JMP_THIS(0x4A7B60); }
    void QueryInfantryData(int infID, CInfantryData& data) { JMP_THIS(0x4AEC30); }
    void SetUnitData(CUnitData* pData, LPCSTR lpNewTypeID, LPCSTR lpNewHouse, int nCoord, ppmfc::CString Unk1)
        { JMP_THIS(0x4B0B30); }
    void DeleteUnitData(int unitID) { JMP_THIS(0x4A87A0); }
    void QueryUnitData(int unitID, CUnitData& data) { JMP_THIS(0x4AED40); }
    void SetAircraftData(CAircraftData* pData, LPCSTR lpNewTypeID, LPCSTR lpNewHouse, int nCoord, ppmfc::CString Unk1)
        { JMP_THIS(0x4B0060); }
    void DeleteAircraftData(int aircraftID) { JMP_THIS(0x4A98B0); }
    void QueryAircraftData(int aircraftID, CAircraftData& data) { JMP_THIS(0x4AF430); }

    void GetStructureData(int structureID, StructureData* pRet) { JMP_THIS(0x4C3C20); } // Type
    TubeData* GetTubeData(int tubeID) { JMP_THIS(0x4753C0); }
    void AddTube(TubeData* pTubeData) { JMP_THIS(0x4BAF20); }

    ppmfc::CString* FindAvailableOwner(ppmfc::CString* buffer, int nUnknown, bool bUseCountries) { JMP_THIS(0x49B2D0); }
    inline ppmfc::CString FindAvailableOwner(int nUnknown, bool bUseCountries)
    {
        ppmfc::CString ret;
        this->FindAvailableOwner(&ret, nUnknown, bUseCountries);
        return ret;
    }

    inline CellData* GetCellAt(int nIndex) { return &this->CellDatas[nIndex]; }
    inline CellData* GetCellAt(int X, int Y) { return this->GetCellAt(this->GetCoordIndex(X, Y)); }
    inline CellData* TryGetCellAt(int nIndex) 
    {
        if (nIndex < this->CellDataCount)
            return this->GetCellAt(nIndex);
        else
        {
            this->TempCellData.Flag.NotAValidCell = 1;
            return &this->TempCellData;
        }
    }
    inline CellData* TryGetCellAt(int X,int Y){ return this->TryGetCellAt(this->GetCoordIndex(X, Y)); }

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
    MapRect Size;
    MapRect LocalSize; // Visible Area
    CellData* CellDatas; // see 4BB920 validate the map, dtor at 416FC0
    int CellDataCount; // see 4BB920 validate the map
    UndoRedoData* UndoRedoData;
    int UndoRedoDataCount;
    int UndoRedoCurrentDataIndex;
    int MoneyCount;
    FAVector<StructureData> StructureDatas; // being used in 4C3C20
    FAVector<TubeData> TubeDatas; // see 4753C0
    FAVector<CSmudgeData> SmudgeDatas;
    FAVector<CTerrainData> TerrainDatas;
    FAVector<CInfantryData> InfantryDatas;
    FAVector<CUnitData> UnitDatas;
    FAVector<CStructureData> BuildingDatas; // Never being really used in fact, but can be guessed from 4CDDE0
    unsigned char MapPreviewData[0x40000];
    BITMAPINFO MapPreviewInfo;
    int MapPreviewStride;
};
