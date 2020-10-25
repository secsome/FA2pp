#include "FA2PP.h"

#include "../FA2sp/Logger.h"

#include "Structures/FAMap.h"


// Remember that we cannot call CTOR or DTOR for any FAMap/FATree

class INISection {
public:
	~INISection() {
		JMP_THIS(0x4023B0);
	}

	void* __DTOR__;

	std::FAMap<CString, CString, 0x5D8CB0, 0x5D8CAC> EntriesDictionary;
	std::FAMap<unsigned int, CString, 0x5D8CA8, 0x5D8CA4> IndicesDictionary;
};

class INIClass
{
private:
	void* __DTOR__;
	std::FAMap<const char*, INISection, 0x5D8CB4, 0> data; // no idea about the nilrefs

public:

	// Quite dirty for now, cause our find isn't working for now......
	CString GetString(const char* pSection, const char* pKey, const char* pDefault = "") {
		//Logger::Debug("GetString Called! %s %s %s\n", pSection, pKey, pDefault);
		auto x = data.begin();
		while (strcmp(x->first, pSection) != 0)
		{
			if (x == data.end())	return pDefault;
			++x;
		}
		auto y = x->second.EntriesDictionary.begin();
		while (strcmp(y->first, pKey) != 0)
		{
			if (y == x->second.EntriesDictionary.end())	return pDefault;
			++y;
		}
		return y->second;
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