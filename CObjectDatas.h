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
    ppmfc::CString X;
    ppmfc::CString Y;
    ppmfc::CString SubCell;
    ppmfc::CString Status;
    ppmfc::CString Facing;
    ppmfc::CString Tag;
    ppmfc::CString VeterancyPercentage;
    ppmfc::CString Group;
    ppmfc::CString IsAboveGround;
    ppmfc::CString AutoNORecruitType;
    ppmfc::CString AutoYESRecruitType;
    int Flag;
};

class CStructureData
{
public:
    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString X;
    ppmfc::CString Y;
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
    int Flag;
};

class CUnitData
{
public:
    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString X;
    ppmfc::CString Y;
    ppmfc::CString Facing;
    ppmfc::CString Status;
    ppmfc::CString Tag;
    ppmfc::CString VeterancyPercentage;
    ppmfc::CString Group;
    ppmfc::CString IsAboveGround;
    ppmfc::CString FollowsIndex;
    ppmfc::CString AutoNORecruitType;
    ppmfc::CString AutoYESRecruitType;
    int Flag;
};

class CAircraftData
{
public:
    ppmfc::CString House;
    ppmfc::CString TypeID;
    ppmfc::CString Health;
    ppmfc::CString X;
    ppmfc::CString Y;
    ppmfc::CString Facing;
    ppmfc::CString Status;
    ppmfc::CString Tag;
    ppmfc::CString VeterancyPercentage;
    ppmfc::CString Group;
    ppmfc::CString AutoNORecruitType;
    ppmfc::CString AutoYESRecruitType;
    int Flag;
};

class CTerrainData
{
public:
    ppmfc::CString TypeID;
    int X;
    int Y;
    int Flag;
};

class CSmudgeData
{
public:
    ppmfc::CString TypeID;
    int X;
    int Y;
    int Flag;
};