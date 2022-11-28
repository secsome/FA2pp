#pragma once

#include "FA2PP.h"
#include "Structures/FAMap.h"

#include "MFC/ppmfc_cstring.h"

#include <vector>
#include <map>

// Forward Definations
class INISection;

struct INISectionEntriesComparator 
{ 
	bool operator()(const ppmfc::CString& s1, const ppmfc::CString& s2) const 
	{
		const int l1 = s1.GetLength();
		const int l2 = s2.GetLength();
		return l1 < l2 || l1 == l2 && strcmp(s1, s2) < 0;
		// JMP_STD(0x452230); 
	} 
};

// type definations
using INIDict = FAMap<ppmfc::CString, INISection, 0x5D8CB4, 0x5D8CE8>;
using INIStringDict = FAMap<ppmfc::CString, ppmfc::CString, 0x5D8CB0, 0x5D8CAC, INISectionEntriesComparator>;
using INIIndiceDict = FAMap<ppmfc::CString, unsigned int, 0x5D8CA8, 0x5D8CA4, INISectionEntriesComparator>;

struct FAINIMap
{
public:
	std::pair<INIDict::iterator, bool>*
		insert(std::pair<INIDict::iterator, bool>* ret, std::pair<ppmfc::CString, INISection>* section)
	{
		JMP_THIS(0x4026D0);
	}
};
struct FAINIEntriesMap
{
public:
	std::pair<INIStringDict::iterator, bool>*
		insert(std::pair<INIStringDict::iterator, bool>* ret, std::pair<ppmfc::CString, ppmfc::CString>* pair)
	{
		JMP_THIS(0x40A010);
	}
};

struct FAINICStringMap : private INIStringDict
{
	INIStringDict* CopyCTOR(INIStringDict* another)
		{ JMP_THIS(0x408070); }
};

struct FAINIIndiceMap : private INIIndiceDict
{
	INIIndiceDict* CopyCTOR(INIIndiceDict* another)
		{ JMP_THIS(0x4081F0); }
};

class NOVTABLE INISection 
{
public:
	INISection() { JMP_THIS(0x452880); }
	INISection(INISection& another) { JMP_THIS(0x4021C0); }
	virtual ~INISection() { JMP_THIS(0x452B20); }

	// Low efficiency warning
	ppmfc::CString* GetValueAt(unsigned int nIndex) { JMP_THIS(0x453590); }
	ppmfc::CString* GetKeyAt(unsigned int nIndex) { JMP_THIS(0x453650); }
public:
	INIStringDict& GetEntities()
		{ return *reinterpret_cast<INIStringDict*>(&this->EntitiesDictionary); }
	INIIndiceDict& GetIndices()
		{ return *reinterpret_cast<INIIndiceDict*>(&this->IndicesDictionary); }


private:
	// In fact we can use a union here. However, to make it
	// being more secured, just use a char array here and 
	// access it by using functions.
	char EntitiesDictionary[sizeof(INIStringDict)];
	char IndicesDictionary[sizeof(INIIndiceDict)];

	// INIStringDict EntitiesDictionary;
	// INIIndiceDict IndicesDictionary;
};

class NOVTABLE CINI
{
public:
	static constexpr reference<CINI, 0x7EDDD8> const Rules{}; // rulesmd.ini / rules.ini
	static constexpr reference<CINI, 0x7EDCA8> const Art{}; // artmd.ini / art.ini
	static constexpr reference<CINI, 0x7ED960> const Turtorial{}; // turtorial.ini
	static constexpr reference<CINI, 0x7EDA78> const Sound{}; // soundmd.ini / sound.ini
	static constexpr reference<CINI, 0x7ED848> const Eva{}; // evamd.ini / eva.ini
	static constexpr reference<CINI, 0x7ED730> const Theme{}; // thememd.ini / theme.ini
	static constexpr reference<CINI, 0x7EDB90> const Ai{}; // aimd.ini / ai.ini
	static constexpr reference<CINI, 0x7ED3E8> const Temperate{}; // temperatmd.ini / temperat.ini
	static constexpr reference<CINI, 0x7ED2D0> const Snow{}; // snowmd.ini / snow.ini
	static constexpr reference<CINI, 0x7ED1B8> const Urban{}; // urbanmd.ini / urban.ini
	static constexpr reference<CINI, 0x7ED0A0> const NewUrban{}; // urbannmd.ini
	static constexpr reference<CINI, 0x7ECF88> const Lunar{}; // lunarmd.ini
	static constexpr reference<CINI, 0x7ECE70> const Desert{}; // desertmd.ini
	static constexpr reference<CINI, 0x7ED618> const FAData{}; // FAData.ini
	static constexpr reference<CINI, 0x7ED500> const FALanguage{}; // FALanguage.ini
	// static constexpr reference<CINI, 0x72CBF8> const UINameHolder{}; // Holds Stringtable
	static constexpr reference<CINI, 0x7ACC80> const CurrentDocument{}; // Current map file, without update
	static constexpr reference<CINI*, 0x7EE03C> const CurrentTheater{}; // Current theater file

public:
	CINI() { JMP_THIS(0x452270); }
	virtual ~CINI() { JMP_THIS(0x4527E0); }

	DECLARE_PROPERTY(INIDict, Dict);
	char Path[MAX_PATH];

	static ppmfc::CString* GetAvailableIndex(ppmfc::CString* ret)
		{ JMP_STD(0x446520); }

	static ppmfc::CString* GetAvailableKey(ppmfc::CString* ret,const char* pSection)
		{ JMP_STD(0x499E80); }

public:
	void Release() { JMP_THIS(0x4527E0); } // DTOR
	int ClearAndLoad(const char* lpPath, int nUnused = 0) { JMP_THIS(0x4526D0); }
	bool WriteToFile(const char* lpPath) { JMP_THIS(0x4536B0); }
	// return values:
	// 0 for success
	// 1 for path not available
	// 2 for fail to read file
	int ParseINI(const char* lpPath, bool bTrimSpace, int nUnused = 0) { JMP_THIS(0x452CC0); }

	std::pair<INIDict::iterator, bool> InsertSection(ppmfc::CString pSection, INISection* section)
	{
		std::pair<ppmfc::CString, INISection> ins = std::make_pair(pSection, *section);
		std::pair<INIDict::iterator, bool> ret;
		reinterpret_cast<FAINIMap*>(&Dict)->insert(&ret, &ins);
		return ret;
	}

	std::pair<INIStringDict::iterator, bool> InsertPair(INIStringDict& dict, ppmfc::CString pKey, ppmfc::CString pValue)
	{
		std::pair<ppmfc::CString, ppmfc::CString> ins = std::make_pair(pKey, pValue);
		std::pair<INIStringDict::iterator, bool> ret;
		reinterpret_cast<FAINIEntriesMap*>(&dict)->insert(&ret, &ins);
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
			return itr->second.GetEntities().size();
		return 0;
	}

	ppmfc::CString GetKeyAt(ppmfc::CString lpSection, int nIndex)
	{
		if (auto pSection = GetSection(lpSection))
			if (nIndex < pSection->GetEntities().size())
				return *pSection->GetKeyAt(nIndex);

		return "";
	}

	ppmfc::CString GetValueAt(ppmfc::CString lpSection, int nIndex)
	{
		if (auto pSection = GetSection(lpSection))
			if (nIndex < pSection->GetEntities().size())
				return *pSection->GetValueAt(nIndex);

		return "";
	}

	bool SectionExists(ppmfc::CString pSection)
	{
		return Dict.find(pSection) != Dict.end();
	}
	
	bool KeyExists(ppmfc::CString pSection, ppmfc::CString pKey)
	{
		if (auto section = GetSection(pSection))
			return section->GetEntities().find(pKey) != section->GetEntities().end();
		return false;
	}
	
	INISection* AddSection(ppmfc::CString pSectionName)
	{
		if (SectionExists(pSectionName))
			return nullptr;

		auto pSection = GameCreate<INISection>();

		auto itr = InsertSection(pSectionName, pSection);

		return &itr.first->second;
	}

	/// <summary>
	/// Write a string to the ini dict.
	/// </summary>
	/// <param name="pSection"></param>
	/// <param name="pKey"></param>
	/// <param name="pValue"></param>
	/// <returns>Whether this value has existed. If pSection or pKey is empty, it will return false as well.</returns>
	bool WriteString(ppmfc::CString pSection, ppmfc::CString pKey, ppmfc::CString pValue)
	{
		if (pSection.IsEmpty() || pKey.IsEmpty())
			return false;

		bool bExisted = true;
		
		auto section = GameCreate<INISection>();
		auto itr = InsertSection(pSection, section);
		GameDelete(section);

		if (itr.second)
			bExisted = false;

		auto itr2 = InsertPair(itr.first->second.GetEntities(), pKey, ppmfc::CString());
		if (itr2.second)
			bExisted = false;

		new(&itr2.first->second) ppmfc::CString(pValue);

		return bExisted;
	}

	int WriteBase64String(ppmfc::CString pSection, const char* data, int slen)
	{
		int line = 1;
		ppmfc::CString key;
		ppmfc::CString value;
		while (slen > 0)
		{
			const int len = slen < 70 ? slen : 70;
			key.Format("%d", line++);
			value.AssignCopy(len, data);

			WriteString(pSection, key, value);

			data += len;
			slen -= len;
		}

		return line - 1;
	}

	bool WriteString(INISection* pSection, ppmfc::CString pKey, ppmfc::CString pValue)
	{
		bool bExisted = true;

		auto itr = InsertPair(pSection->GetEntities(), pKey, ppmfc::CString());
		if (itr.second)
			bExisted = false;

		new(&itr.first->second) ppmfc::CString(pValue);

		return bExisted;
	}

	bool DeleteSection(ppmfc::CString pSection)
	{
		auto itr = Dict.find(pSection);
		if (itr != Dict.end())
		{
			Dict.manual_erase(itr);
			itr->second.~INISection();
			return true;
		}
		return false;
	}

	bool DeleteKey(ppmfc::CString pSection, ppmfc::CString pKey)
	{
		if (auto section = GetSection(pSection))
		{
			auto itr = section->GetEntities().find(pKey);
			if (itr != section->GetEntities().end())
			{
				section->GetEntities().manual_erase(itr);
				itr->second.~CString();
				return true;
			}
		}
		return false;
	}

	bool DeleteKey(INISection* pSection, ppmfc::CString pKey)
	{
		auto itr = pSection->GetEntities().find(pKey);
		if (itr != pSection->GetEntities().end())
		{
			pSection->GetEntities().manual_erase(itr);
			itr->second.~CString();
			return true;
		}
		return false;
	}

	INISection* GetSection(ppmfc::CString pSection)
	{
		auto itr = Dict.find(pSection);
		if (itr != Dict.end())
			return &itr->second;
		return nullptr;
	}

	ppmfc::CString GetStringAt(ppmfc::CString pSection, unsigned int nIndex, ppmfc::CString pDefault = "") {
		if (auto section = GetSection(pSection))
			return *section->GetValueAt(nIndex);
		return pDefault;
	}

	ppmfc::CString* TryGetString(ppmfc::CString pSection, ppmfc::CString pKey) {
		auto itrSection = Dict.find(pSection);
		if (itrSection != Dict.end()) {
			auto pEntries = &itrSection->second.GetEntities();
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

	CPoint GetPoint(ppmfc::CString pSection, ppmfc::CString pKey, CPoint nDefault = { 0,0 })
	{
		ppmfc::CString& pStr = this->GetString(pSection, pKey, "");
		CPoint ret = { 0,0 };
		if (sscanf_s(pStr, "%d,%d", &ret.x, &ret.y) == 2)
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
		for (auto& ent : section->second.GetEntities())
		{
			auto& indexDict = section->second.GetIndices();
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