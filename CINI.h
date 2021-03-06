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
using INIDict = FAMap<ppmfc::CString, INISection, 0x5D8CB4, 0>;
using INIStringDict = FAMap<const char*, const char*, 0x5D8CB0, 0x5D8CAC, INISectionEntriesComparator>;
using INIIndiceDict = FAMap<const char*, unsigned int, 0x5D8CA8, 0x5D8CA4, INISectionEntriesComparator>;

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

class INISection {
public:
	INISection() { JMP_THIS(0x452880); }
	INISection(INISection& another) { JMP_THIS(0x4021C0); }
	~INISection() { JMP_THIS(0x452B20); }

private:
	void* vftable_align; // for align
public:
	INIStringDict EntitiesDictionary;
	INIIndiceDict IndicesDictionary;
};

class INIClass
{
private:
	// ~INIClass() { JMP_THIS(0x4527E0); }

private:
	void* vftable_align; // for align
public:
	INIDict Dict; // no idea about the nilrefs
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
		FAINIMap* mapptr = reinterpret_cast<FAINIMap*>(&Dict);
		mapptr->insert(ret, ins);
		return ret;
	}

	std::pair<INIStringDict::iterator, bool> InsertPair(INIStringDict& dict, const char* pKey, const char* pValue)
	{
		FAINIEntriesMap* ptrmap = reinterpret_cast<FAINIEntriesMap*>(&dict);
		std::pair<ppmfc::CString, ppmfc::CString> ins = std::make_pair(pKey, pValue);
		std::pair<INIStringDict::iterator, bool> ret;
		ptrmap->insert(ret, ins);
		return ret;
	}

	static ppmfc::CString GetAvailableIndex()
	{
		ppmfc::CString ret;
		GetAvailableIndex(&ret);
		return ret;
	}

	static ppmfc::CString GetAvailableKey(const char* pSection)
	{
		ppmfc::CString ret;
		GetAvailableKey(&ret, pSection);
		return ret;
	}

	int GetKeyCount(const char* pSection)
	{
		auto itr = Dict.find(pSection);
		if (itr != Dict.end())
			return itr->second.EntitiesDictionary.size();
		return 0;
	}

	ppmfc::CString GetKeyName(const char* pSection, int nIndex)
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

	bool SectionExists(const char* pSection)
	{
		return Dict.find(pSection) != Dict.end();
	}
	
	bool KeyExists(const char* pSection, const char* pKey)
	{
		if (auto section = GetSection(pSection))
			return section->EntitiesDictionary.find(pKey) != section->EntitiesDictionary.end();
		return false;
	}

	// Something is wrong.
	// Might blow FA2 up (for most times kek)
	// I might remake it some times later
	bool WriteString(const char* pSection, const char* pKey, const char* pValue)
	{
		auto itr = Dict.find(pSection);
		if (itr == Dict.end())	return false;
		auto& dict = itr->second.EntitiesDictionary;
		auto pair = InsertPair(dict, pKey, pValue);
		if (!pair.second)
			((ppmfc::CString*) & pair.first->second)->AssignCopy(strlen(pValue), pValue);
		return true;
	}

	INISection* GetSection(const char* pSection)
	{
		auto itr = Dict.find(pSection);
		if (itr != Dict.end())
			return &itr->second;
		return nullptr;
	}

	ppmfc::CString* TryGetString(const char* pSection, const char* pKey) {
		auto itrSection = Dict.find(pSection);
		if (itrSection != Dict.end()) {
			auto pEntries = &itrSection->second.EntitiesDictionary;
			auto itrKey = pEntries->find(pKey);
			if (itrKey != pEntries->end())
				return (ppmfc::CString*)(&itrKey->second);
		}
		return nullptr;
	}

	ppmfc::CString GetString(const char* pSection, const char* pKey, const char* pDefault = "") {
		if (auto const pStr = TryGetString(pSection, pKey))
			return *pStr;
		else
			return pDefault;
	}

	int GetInteger(const char* pSection, const char* pKey, int nDefault = 0) {
		ppmfc::CString& pStr = this->GetString(pSection, pKey, "");
		int ret = 0;
		if (sscanf_s(pStr, "%d", &ret) == 1)
			return ret;
		return nDefault;
	}

	float GetSingle(const char* pSection, const char* pKey, float nDefault = 0) {
		ppmfc::CString& pStr = this->GetString(pSection, pKey, "");
		float ret = 0;
		if (sscanf_s(pStr, "%f", &ret) == 1)
			return ret;
		return nDefault;
	}

	double GetDouble(const char* pSection, const char* pKey, double nDefault = 0) {
		ppmfc::CString& pStr = this->GetString(pSection, pKey, "");
		double ret = 0;
		if (sscanf_s(pStr, "%lf", &ret) == 1)
			return ret;
		return nDefault;
	}

	bool GetBool(const char* pSection, const char* pKey, bool nDefault = false) {
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

	COLORREF GetColor(const char* pSection, const char* pKey, COLORREF nDefault = 0xFFFFFF) {
		ppmfc::CString& pStr = this->GetString(pSection, pKey, "");
		struct { byte R, G, B, Zero; } ret;
		ret.Zero = 0;
		if (sscanf_s(pStr, "%hhu,%hhu,%hhu", &ret.R, &ret.G, &ret.B) == 3)
			return *reinterpret_cast<COLORREF*>(&ret);
		return nDefault;
	}

	std::map<unsigned int, ppmfc::CString> ParseIndiciesData(const char* pSection)
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