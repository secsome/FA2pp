#pragma once

#include "FA2PP.h"
#include "Structures/FAMap.h"

#include <fstream>

// We can only use C++14 standard for now since our FATree & FAMap
// was a mess, and higher standards are more strict and we cannot
// pass the complie for some reason.
// secsome - 2020/11/3

// Remember that we cannot call CTOR or DTOR for any FAMap/FATree
// cause nil & nilrefs haven't been analysed yet.
// Consider to use : auto& iRules = GlobalVars::INIFiles::Rules();

class INIMapFieldUpdate
{
private:
	static constexpr DWORD _H = 0x72CBF8;
	struct _S
	{
		static void UpdateMapFieldData(int flag)
		{
			JMP_THIS(0x49C280);
		}
	};
	
public:
	static void UpdateMapFieldData(int flag)
	{
		_S* _X = (_S*)_H;
		_X->UpdateMapFieldData(flag);
	}
};

class INISectionEntriesComparator
{
public:
	
	static bool __stdcall __compare(CString* a1, CString* a2)
	{
		JMP_STD(0x452230);
	}

	bool operator()(const CString& s1, const CString& s2) const
	{
		return __compare((CString*)&s1, (CString*)&s2);
	}
};

class INISection {
private:
	/*~INISection() {
		JMP_THIS(0x4023B0);
	}*/

	void* __DTOR__; // for align
public:
	std::FAMap<CString, CString, 0x5D8CB0, 0x5D8CAC, INISectionEntriesComparator> EntriesDictionary;

	// Be careful, better not to use this one for some reason.
	// Cause I've never tested it.
	// secsome - 2020/11/3
	std::FAMap<unsigned int, CString, 0x5D8CA8, 0x5D8CA4> IndicesDictionary;
};

class INIClass
{
private:
	void* __DTOR__; // for align
	std::FAMap<CString, INISection, 0x5D8CB4, 0> data; // no idea about the nilrefs

public:

	static INIClass* GetMapDocument(bool bUpdateMapField = false)
	{
		if(bUpdateMapField)
			INIMapFieldUpdate::UpdateMapFieldData(1);
		return reinterpret_cast<INIClass*>(0x7ACC80);
	}

	// Debug function
	std::FAMap<CString, INISection, 0x5D8CB4, 0>& GetMap()
	{
		return data;
	}

	bool DebugToFile(const char* path)
	{
		std::ofstream fout;
		fout.open(path, std::ios::out);
		if (!fout.is_open())
			return false;
		for (auto& itrsec : data)
		{
			fout << "[" << itrsec.first << "]\n";
			for (auto& entries : itrsec.second.EntriesDictionary)
			{
				fout << entries.first << "=" << entries.second << "\n";
			}
			fout << "\n";
		}
		fout.flush();
		fout.close();
		return true;
	}


	bool SectionExists(const char* pSection)
	{
		return data.find(pSection) != data.end();
	}

	// use it like this to avoid CTOR and crash:
	// auto &iSection = iINI.GetSection("E1");
	// secsome - 2020/11/3
	INISection& GetSection(const char* pSection)
	{
		auto itr = data.find(pSection);
		if (itr != data.end())
			return itr->second;
		return data.begin()->second;
	}

	CString GetString(const char* pSection, const char* pKey, const char* pDefault = "") {
		auto itrSection = data.find(pSection);
		if (itrSection != data.end()) {
			auto pEntries = &itrSection->second.EntriesDictionary;
			auto itrKey = pEntries->find(pKey);
			if (itrKey != pEntries->end())
				return itrKey->second;
		}
		return pDefault;
	}

	int GetInteger(const char* pSection, const char* pKey, int nDefault = 0) {
		CString& pStr = this->GetString(pSection, pKey, "");
		int ret = 0;
		if (sscanf_s(pStr, "%d", &ret) == 1)
			return ret;
		return nDefault;
	}

	float GetSingle(const char* pSection, const char* pKey, float nDefault = 0) {
		CString& pStr = this->GetString(pSection, pKey, "");
		float ret = 0;
		if (sscanf_s(pStr, "%f", &ret) == 1)
			return ret;
		return nDefault;
	}

	double GetDouble(const char* pSection, const char* pKey, double nDefault = 0) {
		CString& pStr = this->GetString(pSection, pKey, "");
		double ret = 0;
		if (sscanf_s(pStr, "%lf", &ret) == 1)
			return ret;
		return nDefault;
	}

	bool GetBool(const char* pSection, const char* pKey, bool nDefault = false) {
		CString& pStr = this->GetString(pSection, pKey, "");
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
};