#include "FA2PP.h"

#include "../FA2sp/Logger.h"

#include "Structures/FAMap.h"


//class INIEntryList
//{
//public:
//	CString* GetValue(int index)
//	{
//		JMP_THIS(0x453590);
//	}
//
//	CString* GetKey(int index)
//	{
//		JMP_THIS(0x453650);
//	}
//
//	DWORD unknown_0;
//	DWORD unknown_4;
//	DWORD unknown_8;
//	DWORD unknown_C;
//	int Count;
//};
//
//class INISection
//{
//public:
//	INISection() : Text("") {}
//	INISection(const char* text) : Text(text) {}
//
//	operator const char* const& () {
//		return Text;
//	}
//
//public:
//	DWORD unknown_0;
//	DWORD unknown_4;
//	DWORD unknown_8;
//	const char* Text;
//	INIEntryList Entries;
//};

class INISection {
private:
	void* __DTOR__;
public:
	std::FAMap<CString, CString> EntriesDictionary;
	std::FAMap<unsigned int, CString> IndicesDictionary;
};
class INIClass
{
private:
	std::FAMap<const char*, INISection> data;

public:
	CString GetString(const char* pSection, const char*pKey, const char* pDefault = ""){
		return pDefault;}

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