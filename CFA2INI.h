#pragma once

#include "../FA2Copy.h"
#include "FA2PP.h"
#include "../Macro.h"

#include <unordered_map>

class NOVTABLE INIPair
{
public:
    explicit INIPair();
    explicit INIPair(LPCSTR pKey, LPCSTR pValue);
    ~INIPair();

    LPCSTR GetKey();
    LPCSTR GetValue();

    void SetValue(LPCSTR pValue);
    
    int GetIntValue();
    bool GetBoolValue();
    double GetDoubleValue();

    static INIPair NullPair();
private:
    LPCSTR Key;
    LPCSTR Value;
};

class NOVTABLE INIEntity
{
public:
    explicit INIEntity();
    explicit INIEntity(LPCSTR pSection);
    ~INIEntity();

    LPCSTR GetSection();

    bool AddPair(INIPair pPair, bool pAllowMerge);
    bool RemovePair(LPCSTR pKey);
    INIPair GetPair(LPCSTR pKey);

    INIPair operator[](LPCSTR pName);

    static INIEntity NullEntity();
private:
    LPCSTR Section;
    std::unordered_map<LPCSTR, INIPair> Datas;
};

class NOVTABLE INIFile
{
public:
    explicit INIFile(LPCSTR pPath);
    ~INIFile();

    void Initialize();

    bool AddSection(INIEntity pEntity, bool pAllowMerge);
    bool RemoveSection(LPCSTR pSection);
    INIEntity GetSection(LPCSTR pSection);

    INIEntity operator[](LPCSTR pSection);
private:
    bool IsInitialized = false;
    bool IsOpened = false;
    std::unordered_map<LPCSTR, INIEntity> Datas;
    CStdioFile* File = nullptr;
};

#if 0
class NOVTABLE CFA2INI
{
public:
    BYTE PlaceHolder[280];
};


DEFINE_HOOK(40A010, CFA2INI_GetpKey, 5)
{
    GET_STACK(CString*, pKey, 8);
    GET_STACK(int*, ukn, 4);
    //logger::Debug(__FUNCTION__" : %s %d\n", *pKey, *ukn);

    return 0;
}
#endif