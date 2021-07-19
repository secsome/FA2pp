#pragma once

#include <CINI.h>
#include <GlobalVars.h>
#include <CObjectDatas.h>

#include <Structures/FAVector.h>

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

    ppmfc::CString StringBuffer;
    int Unknown_4;
    int MapWidthPlusHeight;
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
    int Unknown_38;
    int Unknown_3C;
    int Unknown_40;
    int Unknown_44;
    int Unknown_48;
    int Unknown_4C;
    FAVector<int> BuildingTypes;
    FAVector<int> TerrainTypes;
    FAVector<int> UnitTypes;
    unsigned char OverlayPack[0x40000];
    unsigned char OverlayData[0x40000];
    unsigned char* IsoPackData; // size maybe 11*IsoPackEntryCount + 4
    int IsoPackEntryCount;
    INIClass INI;
    RECT Size;
    RECT LocalSize;
    int unknown_801C0;
    int unknown_801C4;
    void* UndoRedoData;
    int unknown_801CC;
    int unknown_801D0;
    int unknown_801D4;
    FAVector<CStructureData> StructureDatas;
    FAVector<int> vector_801E8;
    FAVector<int> vector_801F8;
    FAVector<int> vector_80208;
    FAVector<CInfantryData> InfantryDatas;
    FAVector<int> vector_80228;
    FAVector<int> vector_80238;
    unsigned char MapPreview[0x40000];
    BITMAPINFO MapPreviewInfo;
    int nSomeMapPreviewData_C0274;
    int Unknown_C0278;
    int Unknown_C027C;
    char gap_C0280[256];
    int Unknown_C0380;
    int Unknown_C0384;
    int Unknown_C0388;
    int Unknown_C038C;
};
