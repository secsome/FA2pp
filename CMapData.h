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
    int unknown_4;
    int MapWidthPlusHeight;
    char gap_huge[524412];
    INIClass INI;
    int unknown_801A0;
    int unknown_801A4;
    int unknown_801A8;
    int unknown_801AC;
    RECT rect_801B0;
    int unknown_801C0;
    int unknown_801C4;
    void* UndoRedoData;
    int unknown_801CC;
    int unknown_801D0;
    int unknown_801D4;
    FAVector<int> vector_801D8;
    FAVector<int> vector_801E8;
    FAVector<int> vector_801F8;
    FAVector<int> vector_80208;
    FAVector<CInfantryData> InfantryDatas;
    FAVector<int> vector_80228;
    FAVector<int> vector_80238;
    unsigned char MapPreview[0x40000];
    BITMAPINFO MapPreviewInfo;
    int SomeNumber;
    char gap[256];
};
