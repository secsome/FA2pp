#pragma once

#include "FA2PP.h"
#include "FAString.h"
#include "Structures/FAMap.h"

#include "MFC/ppmfc_cstring.h"

#include <vector>
#include <map>

// Consider to use : auto& iRules = GlobalVars::INIFiles::Rules();

// Forward Definations
class INISection;
class INIClass;

struct INISectionEntriesComparator 
{ 
	bool operator()(const ppmfc::CString& s1, const ppmfc::CString& s2) const { JMP_STD(0x452230); } 
};

// type definations
using INIDict = FAMap<ppmfc::CString, INISection, 0x5D8CB4, 0x5D8CE8>;
using INIStringDict = FAMap<ppmfc::CString, ppmfc::CString, 0x5D8CB0, 0x5D8CAC, INISectionEntriesComparator>;
using INIIndiceDict = FAMap<ppmfc::CString, unsigned int, 0x5D8CA8, 0x5D8CA4, INISectionEntriesComparator>;

struct FAINIMap
{
public:
	std::pair<INIDict::iterator, bool>*
		insert(std::pair<INIDict::iterator, bool>& ret, std::pair<ppmfc::CString, INISection>& section)
	{
		JMP_THIS(0x4026D0);
	}
};
struct FAINIEntriesMap
{
public:
	std::pair<INIStringDict::iterator, bool>*
		insert(std::pair<INIStringDict::iterator, bool>& ret, std::pair<ppmfc::CString, ppmfc::CString>& pair)
	{
		JMP_THIS(0x40A010);
	}
};

class NOVTABLE INISection {
public:
	INISection() { JMP_THIS(0x452880); }
	INISection(INISection& another) { JMP_THIS(0x4021C0); }
	virtual ~INISection() { JMP_THIS(0x452B20); }

public:
	INIStringDict EntitiesDictionary;
	INIIndiceDict IndicesDictionary;
};

class NOVTABLE INIClass
{
private:
	// ~INIClass() { JMP_THIS(0x4527E0); }

private:
	void* vftable_align; // for align
public:
	INIDict Dict;
	char Path[MAX_PATH];

	static ppmfc::CString* GetAvailableIndex(ppmfc::CString* ret)
		{ JMP_STD(0x446520); }

	static ppmfc::CString* GetAvailableKey(ppmfc::CString* ret,const char* pSection)
		{ JMP_STD(0x499E80); }

public:
	std::pair<INIDict::iterator, bool> InsertSection(ppmfc::CString pSection, INISection& section)
	{
		std::pair<ppmfc::CString, INISection> ins = std::make_pair(pSection, section);
		std::pair<INIDict::iterator, bool> ret;
		reinterpret_cast<FAINIMap*>(&Dict)->insert(ret, ins);
		return ret;
	}

	std::pair<INIStringDict::iterator, bool> InsertPair(INIStringDict& dict, ppmfc::CString pKey, ppmfc::CString pValue)
	{
		std::pair<ppmfc::CString, ppmfc::CString> ins = std::make_pair(pKey, pValue);
		std::pair<INIStringDict::iterator, bool> ret;
		reinterpret_cast<FAINIEntriesMap*>(&dict)->insert(ret, ins);
		return ret;
	}

	static ppmfc::CString GetAvailableIndex()
	{
		ppmfc::CString ret;
		GetAvailableIndex(&ret);
		return ret;
	}

	static ppmfc::CString GetAvailableKey(ppmfc::CString pSection)
	{
		ppmfc::CString ret;
		GetAvailableKey(&ret, pSection);
		return ret;
	}

	int GetKeyCount(ppmfc::CString pSection)
	{
		auto itr = Dict.find(pSection);
		if (itr != Dict.end())
			return itr->second.EntitiesDictionary.size();
		return 0;
	}

	ppmfc::CString GetKeyName(ppmfc::CString pSection, int nIndex)
	{
		auto itr = Dict.find(pSection);
		if (itr != Dict.end())
		{
			auto& EntriesMap = itr->second.EntitiesDictionary;
			auto result = EntriesMap.begin();
			int idx = 0;
			while (result != EntriesMap.end())
			{
				if (idx == nIndex)
					return result->first;
				++idx;
				++result;
			}
		}
		return "";
	}

	bool SectionExists(ppmfc::CString pSection)
	{
		return Dict.find(pSection) != Dict.end();
	}
	
	bool KeyExists(ppmfc::CString pSection, ppmfc::CString pKey)
	{
		if (auto section = GetSection(pSection))
			return section->EntitiesDictionary.find(pKey) != section->EntitiesDictionary.end();
		return false;
	}

	/// <summary>
	/// Write a string to the ini dict.
	/// </summary>
	/// <param name="pSection"></param>
	/// <param name="pKey"></param>
	/// <param name="pValue"></param>
	/// <returns>Whether this value has existed.</returns>
	bool WriteString(ppmfc::CString pSection, ppmfc::CString pKey, ppmfc::CString pValue)
	{
		bool bExisted = true;
		
		auto itr = InsertSection(pSection, INISection());
		if (itr.second)
			bExisted = false;

		auto itr2 = InsertPair(itr.first->second.EntitiesDictionary, pKey, ppmfc::CString());
		if (itr2.second)
			bExisted = false;

		new(&itr2.first->second) ppmfc::CString(pValue);

		return bExisted;
	}

	INISection* GetSection(ppmfc::CString pSection)
	{
		auto itr = Dict.find(pSection);
		if (itr != Dict.end())
			return &itr->second;
		return nullptr;
	}

	ppmfc::CString* TryGetString(ppmfc::CString pSection, ppmfc::CString pKey) {
		auto itrSection = Dict.find(pSection);
		if (itrSection != Dict.end()) {
			auto pEntries = &itrSection->second.EntitiesDictionary;
			auto itrKey = pEntries->find(pKey);
			if (itrKey != pEntries->end())
				return (ppmfc::CString*)(&itrKey->second);
		}
		return nullptr;
	}

	ppmfc::CString GetString(ppmfc::CString pSection, ppmfc::CString pKey, ppmfc::CString pDefault = "") {
		if (auto const pStr = TryGetString(pSection, pKey))
			return *pStr;
		else
			return pDefault;
	}

	int GetInteger(ppmfc::CString pSection, ppmfc::CString pKey, int nDefault = 0) {
		ppmfc::CString& pStr = this->GetString(pSection, pKey, "");
		int ret = 0;
		if (sscanf_s(pStr, "%d", &ret) == 1)
			return ret;
		return nDefault;
	}

	float GetSingle(ppmfc::CString pSection, ppmfc::CString pKey, float nDefault = 0) {
		ppmfc::CString& pStr = this->GetString(pSection, pKey, "");
		float ret = 0;
		if (sscanf_s(pStr, "%f", &ret) == 1)
			return ret;
		return nDefault;
	}

	double GetDouble(ppmfc::CString pSection, ppmfc::CString pKey, double nDefault = 0) {
		ppmfc::CString& pStr = this->GetString(pSection, pKey, "");
		double ret = 0;
		if (sscanf_s(pStr, "%lf", &ret) == 1)
			return ret;
		return nDefault;
	}

	bool GetBool(ppmfc::CString pSection, ppmfc::CString pKey, bool nDefault = false) {
		ppmfc::CString& pStr = this->GetString(pSection, pKey, "");
		switch (toupper(static_cast<unsigned char>(*pStr)))
		{
		case '1':
		case 'T':
		case 'Y':
			return true;
		case '0':
		case 'F':
		case 'N':
			return false;
		default:
			return nDefault;
		}
	}

	COLORREF GetColor(ppmfc::CString pSection, ppmfc::CString pKey, COLORREF nDefault = 0xFFFFFF) {
		ppmfc::CString& pStr = this->GetString(pSection, pKey, "");
		struct { byte R, G, B, Zero; } ret;
		ret.Zero = 0;
		if (sscanf_s(pStr, "%hhu,%hhu,%hhu", &ret.R, &ret.G, &ret.B) == 3)
			return *reinterpret_cast<COLORREF*>(&ret);
		return nDefault;
	}

	std::map<unsigned int, ppmfc::CString> ParseIndiciesData(ppmfc::CString pSection)
	{
		std::map<unsigned int, ppmfc::CString> ret;
		auto& section = Dict.find(pSection);
		if (section == Dict.end())
			return ret;
		std::map<unsigned int, ppmfc::CString> tmp;
		for (auto& ent : section->second.EntitiesDictionary)
		{
			auto& indexDict = section->second.IndicesDictionary;
			auto& idxitr = indexDict.find(ent.first);
			if (idxitr != indexDict.end())
				tmp[idxitr->second] = idxitr->first;
		}
		size_t idx = 0;
		for (auto& x : tmp)
			ret[idx++] = x.second;

		return ret;
	}
};