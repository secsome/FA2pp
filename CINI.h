#include "FA2PP.h"

#include "../FA2sp/Logger.h"

#include "Structures/FAMap.h"

class INISection
{
public:
	~INISection() {}
	void* __destructor__;
	std::FAMap<CString, CString> EntriesData;
	std::FAMap<unsigned int, CString> IndicesData;
};

class INIClass
{
private:
	std::FAMap<const char*, INISection> data;

public:
	CString GetString(const char* pSection, const char* pKey, const char* pDefault = "")
	{
		auto& bItr = data.find(pSection);
		if (bItr == data.end()) {
			Logger::Debug("SECTION NOT EXISTS\n");
			return pDefault;
		}
		
		INISection& section = bItr->second;
		auto& fItr = section.EntriesData.find(pKey);
		if (fItr == section.EntriesData.end())	return pDefault;
		return fItr->second;
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

class INIHeaderClass
{
private:
	DWORD unknown_0;
public:
	INIClass* file;
};