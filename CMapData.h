#pragma once

#include <Helpers/EnumFlags.h>

#include <CINI.h>
#include <CObjectDatas.h>
#include <CPalette.h>
#include <CTileTypeClass.h>

#include <Structures/FAVector.h>

class Waypoints
{
public:
    static int __cdecl String_To_Waypoint(const char* a1) JMP_STD(0x4E5F30);
    static CString* __cdecl Waypoint_To_String(CString* pBuffer, int nWaypoint) JMP_STD(0x4E5F90);
};

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

    bool IsHidden() const
    {
        return Flag.IsHiddenCell || (*CTileTypeClass::Instance)[TileIndex == 0xFFFF ? 0 : TileIndex].IsHidden;
    }

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
    unsigned short TileIndexHiPart; // Obviously, the author of FA2 dunno it's a int32 in fact.
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
struct IsoMapPack4Entry
{
    short X;
    short Y;
    int TileIndex;
    unsigned char TileSubIndex;
    unsigned char Level;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct IsoMapPack5Entry
{
    short X;
    short Y;
    int TileIndex; // Yeah, it's int32, but FA2's author dunno that.
    unsigned char TileSubIndex;
    unsigned char Level;
    unsigned char IceGrowth; // Unused in RA2/YR
};
#pragma pack(pop)

struct CBuildingTypeData
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

struct CTubeData
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
    unsigned short TileIndexHiPart;
    unsigned char TileSubIndex;
    unsigned char Height;
    unsigned char IceGrowth;
    unsigned char Unknown_D; // 221 mostly, dunno what, cannot find it is being used
    unsigned short TileSet;
    unsigned char NthTileSetFile;
};

struct UndoRedoData
{
    int Left;
    int Top;
    int Bottom;
    int Right;
    int* IgnoreAltImages;
    unsigned char* Overlay;
    unsigned char* OverlayData;
    unsigned short* TileIndex;
    unsigned short* TileIndexHiPart;
    unsigned char* TilesubIndex;
    unsigned char* Height;
    unsigned char* IceGrowth;
    unsigned char* AltIndex;
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
    template <typename T>
    void GetMapPreview(T*& pBuffer, LPBITMAPINFO lpBitmapInfo, int& nStride)
    {
        return GetMapPreview((void*&)pBuffer, lpBitmapInfo, nStride);
    }

    void ResizeMap(int L, int T, int W, int H) { JMP_THIS(0x4C45F0); }

    void Pack(bool UpdatePreview = false, bool Description = false) { JMP_THIS(0x49F7A0); }
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

    void UpdateTypeDatas() { JMP_THIS(0x4AD930); }

    // Again! FA2 coordinate system is just the reverse of the game's.
    // In FA2pp we just keep FA2's coordinate system naming all the time!
    inline int GetCoordIndex(int X, int Y) { return X + Y * MapWidthPlusHeight; }  
    inline int GetXFromCoordIndex(int CoordIndex) { return CoordIndex % MapWidthPlusHeight; }
    inline int GetYFromCoordIndex(int CoordIndex) { return CoordIndex / MapWidthPlusHeight; }
    inline bool IsCoordInMap(int X, int Y)
    {
        return
            X > 0 && Y > 0 &&
            X + Y > Size.Width &&
            X + Y <= Size.Width + 2 * Size.Height &&
            (Y < Size.Width || X > Y - Size.Width) &&
            (X < Size.Width || X < Y + Size.Width);
    }
    inline bool IsCoordInMap(int CoordIndex) 
    { 
        return IsCoordInMap(GetXFromCoordIndex(CoordIndex), GetYFromCoordIndex(CoordIndex)); 
    }

    void SetTileAt(unsigned nIndex, unsigned int nTileCount, char nTileSubIndex = 0) { JMP_THIS(0x416550); }

    void SetBuildingData(CBuildingData* pData, LPCSTR lpNewTypeID, LPCSTR lpNewHouse, int nCoord, ppmfc::CString Unk1)
        { JMP_THIS(0x4ACB60); }
    void DeleteBuildingData(int bldID) { JMP_THIS(0x4A8FB0); }
    void GetBuildingData(int bldID, CBuildingData& data) { JMP_THIS(0x4AADB0); }
    void SetInfantryData(CInfantryData* pData, LPCSTR lpNewTypeID, LPCSTR lpNewHouse, int nCoord, int ManualinfID)
        { JMP_THIS(0x4AC210); }
    void DeleteInfantryData(int infID) { JMP_THIS(0x4A7B60); }
    void GetInfantryData(int infID, CInfantryData& data) { JMP_THIS(0x4AEC30); }
    void SetUnitData(CUnitData* pData, LPCSTR lpNewTypeID, LPCSTR lpNewHouse, int nCoord, ppmfc::CString Unk1)
        { JMP_THIS(0x4B0B30); }
    void DeleteUnitData(int unitID) { JMP_THIS(0x4A87A0); }
    void GetUnitData(int unitID, CUnitData& data) { JMP_THIS(0x4AED40); }
    void SetAircraftData(CAircraftData* pData, LPCSTR lpNewTypeID, LPCSTR lpNewHouse, int nCoord, ppmfc::CString Unk1)
        { JMP_THIS(0x4B0060); }
    void DeleteAircraftData(int aircraftID) { JMP_THIS(0x4A98B0); }
    void GetAircraftData(int aircraftID, CAircraftData& data) { JMP_THIS(0x4AF430); }

    void GetBuildingTypeData(int bldTypeID, CBuildingTypeData* pRet) { JMP_THIS(0x4C3C20); }
    CTubeData* GetTubeData(int tubeID) { JMP_THIS(0x4753C0); }
    void AddTube(CTubeData* pTubeData) { JMP_THIS(0x4BAF20); }

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
    // ID -> ArrayIndex
    FAMap<ppmfc::CString, int, 0x5D8CD0, 0x5D8CCC> BuildingTypes;
    FAMap<ppmfc::CString, int, 0x5D8CD0, 0x5D8CCC> TerrainTypes;
    FAMap<ppmfc::CString, int, 0x5D8CD0, 0x5D8CCC> SmudgeTypes;
    unsigned char Overlay[0x40000];
    unsigned char OverlayData[0x40000];
    IsoMapPack5Entry* IsoPackData;
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
    FAVector<CBuildingTypeData> BuildingTypeDatas; // being used in 4C3C20
    FAVector<CTubeData> TubeDatas; // see 4753C0
    FAVector<CSmudgeData> SmudgeDatas;
    FAVector<CTerrainData> TerrainDatas;
    FAVector<CInfantryData> InfantryDatas;
    FAVector<CUnitData> UnitDatas;
    FAVector<CBuildingData> BuildingDatas; // Never being really used in fact, but can be guessed from 4CDDE0
    unsigned char MapPreviewData[0x40000];
    BITMAPINFO MapPreviewInfo;
    int MapPreviewStride;
};

class CellDataEnumerator
{
public:
    explicit CellDataEnumerator(){ }

    explicit operator bool() const 
    {
        return NextX < CMapData::Instance->MapWidthPlusHeight&& NextY < CMapData::Instance->MapWidthPlusHeight;
    }

    CellData& operator*() 
    {
        return *this->operator->();
    }

    const CellData& operator*() const 
    {
        return *this->operator->();
    }

    // FA2 Coordinate is just the reverse of the games'
    int GetX() const
    {
        return CMapData::Instance->GetYFromCoordIndex(NextCell);
    }
    int GetY() const
    {
        return CMapData::Instance->GetXFromCoordIndex(NextCell);
    }

    CellData* operator->() const 
    {
        return CMapData::Instance->GetCellAt(GetX(), GetY());
    }

    CellDataEnumerator& operator++() 
    {
        if (NextColumn)
        {
            ++NextY;
            --NextX;
            --NextColumn;
            NextCell -= (CMapData::Instance->MapWidthPlusHeight - 1);
        }
        else
        {
            const int y = NextY;
            const int x = NextX;
            NextX = y;
            NextY = x;
            if ((x + y - CMapData::Instance->Size.Width - 1) % 2 != 0)
            {
                NextColumn = CMapData::Instance->Size.Width - 1;
                NextX = y + 1;
            }
            else
            {
                NextColumn = CMapData::Instance->Size.Width - 2;
                NextY = x + 1;
            }
            NextCell = CMapData::Instance->MapWidthPlusHeight * NextX + NextY;
        }
        return *this;
    }

    CellDataEnumerator operator++(int) 
    {
        auto const old = *this;
        ++*this;
        return old;
    }

private:
    int NextX{ CMapData::Instance->Size.Width };
    int NextY{ 1 };
    int NextColumn{ CMapData::Instance->Size.Width - 1 };
    int NextCell{ CMapData::Instance->MapWidthPlusHeight * CMapData::Instance->Size.Width + 1 };
};