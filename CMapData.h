#pragma once

#include <CINI.h>
#include <GlobalVars.h>

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
    int unknown_800A0;
    int unknown_800A4;
    int unknown_800A8;
    int unknown_800AC;
    int unknown_800B0;
    int unknown_800B4;
    int unknown_800B8;
    int unknown_800BC;
    int unknown_800C0;
    int unknown_800C4;
    void* UndoRedoData;
    int unknown_800CC;
    int unknown_800D0;
    int unknown_800D4;
    int unknown_800D8;
    int unknown_800DC;
    int unknown_800E0;
    int unknown_800E4;
    int unknown_800E8;
    int unknown_800EC;
    int unknown_800F0;
    int unknown_800F4;
    int unknown_800F8;
    int unknown_800FC;
    int unknown_80100;
    int unknown_80104;
    int unknown_80108;
    int unknown_8010C;
    int unknown_80110;
    int unknown_80114;
    int unknown_80118;
    int unknown_8011C;
    int unknown_80120;
    int unknown_80124;
    int unknown_80128;
    int unknown_8012C;
    int unknown_80130;
    int unknown_80134;
    int unknown_80138;
    int unknown_8013C;
    int unknown_80140;
    int unknown_80144;
    int unknown_80148;
    int unknown_8014C;
    int unknown_80150;
    int unknown_80154;
    int unknown_80158;
    int unknown_8015C;
    int unknown_80160;
    int unknown_80164;
    int unknown_80168;
    int unknown_8016C;
    int unknown_80170;
    int unknown_80174;
    int unknown_80178;
    int unknown_8017C;
    int unknown_80180;
    int unknown_80184;
    int unknown_80188;
    int unknown_8018C;
    int unknown_80190;
    int unknown_80194;
    int unknown_80198;
    int unknown_8019C;
    int unknown_801A0;
    int unknown_801A4;
    int unknown_801A8;
    int unknown_801AC;
    int unknown_801B0;
    int unknown_801B4;
    int unknown_801B8;
    int unknown_801BC;
    int unknown_801C0;
    int unknown_801C4;
    int unknown_801C8;
    int unknown_801CC;
    int unknown_801D0;
    int unknown_801D4;
    int unknown_801D8;
    int unknown_801DC;
    int unknown_801E0;
    int unknown_801E4;
    int unknown_801E8;
    int unknown_801EC;
    int unknown_801F0;
    int unknown_801F4;
    int unknown_801F8;
    int unknown_801FC;
    int unknown_80200;
    int unknown_80204;
    int unknown_80208;
    int unknown_8020C;
    int unknown_80210;
    int unknown_80214;
    int unknown_80218;
    int unknown_8021C;
    int unknown_80220;
    int unknown_80224;
    int unknown_80228;
    int unknown_8022C;
    int unknown_80230;
    int unknown_80234;
    int unknown_80238;
    int unknown_8023C;
    int unknown_80240;
};
