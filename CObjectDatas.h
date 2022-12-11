#pragma once

#include <MFC/ppmfc_cstring.h>

enum class ObjectType
{
    Infantry = 0,
    Structure = 1,
    Aircraft = 2,
    Unit = 3,
    Overlay = 4,
    Celltag = 5,
    Waypoints = 6
};

class CInfantryData
{
public:
    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString Y;
    ppmfc::CString X;
    ppmfc::CString SubCell;
    ppmfc::CString Status;
    ppmfc::CString Facing;
    ppmfc::CString Tag;
    ppmfc::CString VeterancyPercentage;
    ppmfc::CString Group;
    ppmfc::CString IsAboveGround;
    ppmfc::CString AutoNORecruitType;
    ppmfc::CString AutoYESRecruitType;
    bool Flag : 1;
};

class CBuildingData
{
public:
    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString Y;
    ppmfc::CString X;
    ppmfc::CString Facing;
    ppmfc::CString Tag;
    ppmfc::CString AISellable;
    ppmfc::CString AIRebuildable;
    ppmfc::CString PoweredOn;
    ppmfc::CString Upgrades;
    ppmfc::CString SpotLight;
    ppmfc::CString Upgrade1;
    ppmfc::CString Upgrade2;
    ppmfc::CString Upgrade3;
    ppmfc::CString AIRepairable;
    ppmfc::CString Nominal;
    bool Flag : 1;
};

class CUnitData
{
public:
    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString Y;
    ppmfc::CString X;
    ppmfc::CString Facing;
    ppmfc::CString Status;
    ppmfc::CString Tag;
    ppmfc::CString VeterancyPercentage;
    ppmfc::CString Group;
    ppmfc::CString IsAboveGround;
    ppmfc::CString FollowsIndex;
    ppmfc::CString AutoNORecruitType;
    ppmfc::CString AutoYESRecruitType;
    bool Flag : 1;
};

class CAircraftData
{
public:
    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString Y;
    ppmfc::CString X;
    ppmfc::CString Facing;
    ppmfc::CString Status;
    ppmfc::CString Tag;
    ppmfc::CString VeterancyPercentage;
    ppmfc::CString Group;
    ppmfc::CString AutoNORecruitType;
    ppmfc::CString AutoYESRecruitType;
    bool Flag : 1;
};

class CTerrainData
{
public:
    ppmfc::CString TypeID;
    int Y;
    int X;
    bool Flag : 1;
};

class CSmudgeData
{
public:
    ppmfc::CString TypeID;
    int Y;
    int X;
    bool Flag : 1;
};

static_assert(sizeof(CInfantryData) == 0x3C);
static_assert(sizeof(CBuildingData) == 0x48);
static_assert(sizeof(CUnitData) == 0x3C);
static_assert(sizeof(CAircraftData) == 0x34);
static_assert(sizeof(CTerrainData) == 0x10);
static_assert(sizeof(CSmudgeData) == 0x10);
