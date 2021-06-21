#pragma once

#include <CINI.h>
#include <GlobalVars.h>

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
    FAVector<int> vector_80218;
    FAVector<int> vector_80228;
    FAVector<int> vector_80238;
    int unknown_80248;
    int unknown_8024C;
    int unknown_80250;
    int unknown_80254;
    int unknown_80258;
    int unknown_8025C;
    int unknown_80260;
    int unknown_80264;
    int unknown_80268;
    int unknown_8026C;
    int unknown_80270;
    int unknown_80274;
    int unknown_80278;
    int unknown_8027C;
    int unknown_80280;
    int unknown_80284;
    int unknown_80288;
    int unknown_8028C;
    int unknown_80290;
    int unknown_80294;
    int unknown_80298;
    int unknown_8029C;
    int unknown_802A0;
    int unknown_802A4;
    int unknown_802A8;
    int unknown_802AC;
    int unknown_802B0;
    int unknown_802B4;
    int unknown_802B8;
    int unknown_802BC;
    int unknown_802C0;
    int unknown_802C4;
    int unknown_802C8;
    int unknown_802CC;
    int unknown_802D0;
    int unknown_802D4;
    int unknown_802D8;
    int unknown_802DC;
    int unknown_802E0;
    int unknown_802E4;
    int unknown_802E8;
    int unknown_802EC;
    int unknown_802F0;
    int unknown_802F4;
    int unknown_802F8;
    int unknown_802FC;
    int unknown_80300;
    int unknown_80304;
    int unknown_80308;
    int unknown_8030C;
    int unknown_80310;
    int unknown_80314;
    int unknown_80318;
    int unknown_8031C;
    int unknown_80320;
    int unknown_80324;
    int unknown_80328;
    int unknown_8032C;
    int unknown_80330;
    int unknown_80334;
    int unknown_80338;
    int unknown_8033C;
    int unknown_80340;
    int unknown_80344;
};
