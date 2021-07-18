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
    ppmfc::CString Rotation;
    ppmfc::CString AttachedTag;
    ppmfc::CString VeterancyPercentage;
    ppmfc::CString Group;
    ppmfc::CString IsAboveGround;
    ppmfc::CString AutoNORecruitType;
    ppmfc::CString AutoYESRecruitType;
    int Flag;
};