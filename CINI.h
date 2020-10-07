#include "FA2PP.h"

#include "../FA2sp/Logger.h"

#include "Structures/FAMap.h"

class INIEntryList
{
public:
	CString* GetValue(int index)
	{
		JMP_THIS(0x453590);
	}

	CString* GetKey(int index)
	{
		JMP_THIS(0x453650);
	}

	DWORD unknown_0;
	DWORD unknown_4;
	DWORD unknown_8;
	DWORD unknown_C;
	int Count;
};

class INISection
{
public:
	INISection() : Text("") {}
	INISection(const char* text) : Text(text) {}

	operator const char* const& () {
		return Text;
	}

public:
	DWORD unknown_0;
	DWORD unknown_4;
	DWORD unknown_8;
	const char* Text;
	INIEntryList Entries;
};

struct INIClassQueryPair
{
	INIClassQueryPair(const char* text) : Key(text) {}

	const char* Key;
	INISection Value;
};

struct INIClassReturnPair
{
	INIClassReturnPair* iterator;
	bool bNotFound;
};

class FAINIClass
{
private:
	std::FAMap<const char*, INISection> data;

public:
	

};

class INIClass
{
private:
	std::FAMap<const char*, INISection> data;

public:
	const char* GetString(const char* pSection, const char*pKey, const char* pDefault = "")
	{
		INISection& section = this->data[pSection];
		INIEntryList& entries = section.Entries;
		int& count = entries.Count;
		Logger::Debug("text = %s, COUNT = %d\n", section.Text ,count);
		for (int i = 0; i < count; ++i)
			if (*entries.GetKey(i) == pKey)
				return *entries.GetValue(i);
		return pDefault;
	}

	int GetInteger(const char* pSection, const char* pKey, int nDefault = 0) {
		auto const pStr = this->GetString(pSection, pKey, "");
		int ret = 0;
		if (sscanf_s(pStr, "%d", &ret) == 1)
			return ret;
		return nDefault;
	}

	float GetSingle(const char* pSection, const char* pKey, float nDefault = 0) {
		auto const pStr = this->GetString(pSection, pKey, "");
		float ret = 0;
		if (sscanf_s(pStr, "%f", &ret) == 1)
			return ret;
		return nDefault;
	}

	double GetDouble(const char* pSection, const char* pKey, double nDefault = 0) {
		auto const pStr = this->GetString(pSection, pKey, "");
		double ret = 0;
		if (sscanf_s(pStr, "%lf", &ret) == 1)
			return ret;
		return nDefault;
	}

	bool GetBool(const char* pSection, const char* pKey, bool nDefault = false) {
		auto const pStr = this->GetString(pSection, pKey, "");
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