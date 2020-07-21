#include "CFA2INI.h"

#pragma region INIPair

INIPair::INIPair() = default;

INIPair::INIPair(LPCSTR pKey, LPCSTR pValue = "")
{
    Key = pKey;
    Value = pValue;
}

INIPair::~INIPair() = default;

void INIPair::SetValue(LPCSTR pValue)
{
    Value = pValue;
}

LPCSTR INIPair::GetKey()
{
    return Key;
}

LPCSTR INIPair::GetValue()
{
    return Value;
}

int INIPair::GetIntValue()
{
    int ret = 0;
    sprintf((char*)Value, "%d", &ret);
    return ret;
}

double INIPair::GetDoubleValue()
{
    double ret = 0.000000;
    sprintf((char*)Value, "%lf", &ret);
    return ret;
}

bool INIPair::GetBoolValue()
{
    CString lowerValue = Value;
    lowerValue.MakeLower();
    lowerValue.TrimLeft();
    lowerValue.TrimRight();
    return lowerValue == "yes" || lowerValue == "true" || lowerValue == "1";
}

INIPair INIPair::NullPair()
{
    INIPair ret(nullptr, nullptr);
    return ret;
}
#pragma endregion

#pragma region INIEntity
INIEntity::INIEntity() = default;

INIEntity::INIEntity(LPCSTR pSection)
{
    Section = pSection;
}

INIEntity::~INIEntity() = default;

bool INIEntity::AddPair(INIPair pPair, bool pAllowMerge = false)
{
    if (Datas.find(pPair.GetKey()) == Datas.end())  return false;
    Datas[pPair.GetKey()] = pPair;
    return true;
}

LPCSTR INIEntity::GetSection()
{
    return Section;
}

bool INIEntity::RemovePair(LPCSTR pKey)
{
    if (Datas.find(pKey) != Datas.end())   return false;
    Datas.erase(pKey);
    return true;
}

INIPair INIEntity::GetPair(LPCSTR pKey)
{
    const auto pResult = Datas.find(pKey);
    if (pResult != Datas.end())
        return pResult->second;
    return INIPair::NullPair();
}

INIPair INIEntity::operator[](LPCSTR pName)
{
    const auto pResult = Datas.find(pName);
    if (pResult != Datas.end())
        return pResult->second;
    return INIPair::NullPair();
}

INIEntity INIEntity::NullEntity()
{
    return *new INIEntity(nullptr);
}
#pragma endregion

#pragma region INIFile
INIFile::INIFile(LPCSTR pPath)
{
    if (!File->Open(pPath, CFile::modeReadWrite))
        IsOpened = false;
}

INIFile::~INIFile()
{
    IsOpened = false;
    IsInitialized = false;
    File->Close();
}

void INIFile::Initialize()
{
    if (!IsOpened)   return;
    CString pLineStr;
    INIEntity* newEntity = nullptr;
    while (!File->ReadString(pLineStr))
    {
        pLineStr.TrimLeft();
        pLineStr.TrimRight();
        if (int pStrLength = pLineStr.GetLength() > 0)
        {
            int startIdx = pLineStr.Find('[');
            int endIdx = pLineStr.Find(']');
            if (startIdx == 0 && endIdx > 0)
            {
                if (int subLen = endIdx - startIdx > 1 && startIdx != -1 && endIdx != -1)
                {
                    Datas[newEntity->GetSection()] = *newEntity;
                    LPCSTR sectionName = pLineStr.Mid(startIdx, subLen);
                    newEntity = new INIEntity(sectionName);
                }
            }
            else
            {
                int equalIdx = pLineStr.Find('=');
                int commentIdx = pLineStr.Find(';');
                CString* tmp = new CString(pLineStr.Mid(0, equalIdx));
                tmp->TrimRight();
                LPCSTR key = *tmp;
                tmp = new CString(pLineStr.Mid(equalIdx + 1, commentIdx));
                LPCSTR value = *tmp;
                newEntity->AddPair(*new INIPair(key, value));
            }
        }
    }
    IsInitialized = true;
}

bool INIFile::AddSection(INIEntity pEntity, bool pAllowMerge = false)
{
    if (!IsInitialized)  return false;
    if (Datas.find(pEntity.GetSection()) != Datas.end())
    {
        if (!pAllowMerge)    return false;
        for (auto entity : Datas)
        {

        }
    }
    else Datas[pEntity.GetSection()] = pEntity;
    return true;
}

bool INIFile::RemoveSection(LPCSTR pSection)
{
    if (!IsInitialized)  return false;
    if (Datas.find(pSection) == Datas.end())  return false;
    Datas.erase(pSection);
    return true;
}

INIEntity INIFile::GetSection(LPCSTR pSection)
{
    if (!IsInitialized)  return INIEntity::NullEntity();
    if (Datas.find(pSection) == Datas.end())   return INIEntity::NullEntity();
    return Datas[pSection];
}

INIEntity INIFile::operator[](LPCSTR pSection)
{
    if (!IsInitialized)  return INIEntity::NullEntity();
    if (Datas.find(pSection) == Datas.end())   return INIEntity::NullEntity();
    return Datas[pSection];
}
#pragma endregion
