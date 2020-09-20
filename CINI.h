#pragma once

//#include "../FA2.h"

#include "Helpers/ASMMacros.h"
#include "FAString.h"
#include "FA2PP.h"

#include "../FA2sp/Logger.h"

// presumed ini section?
class UnknownA
{
public:
	UnknownA()
	{
		JMP_THIS(0x452880);
	}

	UnknownA(const UnknownA& other) {
		*this = other;
	}

	UnknownA& operator=(const UnknownA& other) {
		JMP_THIS(0x4021C0);
	}

	~UnknownA()
	{
		JMP_THIS(0x452B20);
	}

	char unknown_0[36];
};

template <typename T>
class INIClassQuery
{
public:
	INIClassQuery(const FAString& query) : Query(query), Data(T()) {}

	INIClassQuery(const FAString& query, const T& data) : Query(query), Data(data) {}

	~INIClassQuery() {
		// member destructors called automatically
	}

	operator const char* const& () {
		return Query;
	}

private:
	FAString Query;
	T Data;
};

template <typename T>
struct INIQueryResult
{
	INIQueryResult() : Value(nullptr), Found(false) {}

	T* Value;
	bool Found;
};

template <typename T>
class FALink
{
public:
	T unknown_0;
	T unknown_4;
	T unknown_8;
};

class INIClassHelpers
{
protected:
	template <typename T, typename Helper, DWORD FuncAddr>
	INIQueryResult<T> Query(const char* const& section) {
		INIQueryResult<T> desc;
		INIClassQuery<Helper> query(section);
		return *Query<T, FuncAddr>(desc, query);
	}

	template <typename T, DWORD FuncAddr>
	INIQueryResult<T>* Query(INIQueryResult<T>& unk, const char* const& section)
	{
		static const DWORD FuncAddr_ = FuncAddr;
		JMP_THIS(FuncAddr_);
	}
};

class INIEntry {
public:
	DWORD unknown_0[4];
	FAString Value;
};

class INIEntries : private INIClassHelpers
{
public:
	INIEntry* GetItem(const char* const& section) {
		return Query<INIEntry, FAString, 0x40A010>(section).Value; // GetSectionDescriptor(section).Value;
	}

	DWORD unknown_0;
};

class INIEntryList
{
public:
	FAString* GetValue(int index)
	{
		JMP_THIS(0x453590);
	}

	FAString* GetKey(int index)
	{
		JMP_THIS(0x453650);
	}

	DWORD unknown_0;
	DWORD unknown_4;
	DWORD unknown_8;
	DWORD unknown_C;
	int Count;
};

class INISection : public FALink<void*>
{
public:
	INISection(const char* text) : Text(text) {}

	operator const char* const& () {
		return Text;
	}

public:
	const char* Text;
	INIEntryList Entries;
};

class INIUnknown
{
public:
	DWORD unknown_0[5];
	INIEntries Items;
};




class INIClass : private INIClassHelpers
{
public:
	INISection* GetSection(const char* const& section) {
		return Query<INISection, UnknownA, 0x4026D0>(section).Value; /*GetSectionDescriptor(section).Value;*/
	}

	bool HasSection(const char* const& section) {
		return Query<INISection, UnknownA, 0x4026D0>(section).Found; //GetSectionDescriptor(section).Found;
	}

	INIUnknown* GetEntries(const char* const& section) {
		return Query<INIUnknown, UnknownA, 0x407DA0>(section).Value; /*XXX(section).Value;*/
	}

private:

public:
	// Several useful wrappers
	CString GetString(const char* pSection, const char* pKey, const char* pDefault) { // slower , but exactly
		CString res;
		if (auto const sectionptr = this->GetSection(pSection))
		{
			auto& entryList = sectionptr->Entries;
			if (auto const entryCount = entryList.Count)
			{
				for (int i = 0; i < entryCount; ++i)
					if (auto pStr = entryList.GetKey(i))
						if (*reinterpret_cast<CString*>(pStr) == pKey)
						{
							res = *entryList.GetValue(i);
							return res;
						}
			}
		}
		return pDefault;
	}

	CString GetString(const char* pSection, const char* pKey) { // return pKey if not found, stupid
		CString res;
		if (auto const pEntries = this->GetEntries(pSection))
			if (auto const pItem = pEntries->Items.GetItem(pKey))
				res = pItem->Value;
		return res;
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
		switch(toupper(static_cast<unsigned char>(*pStr)))
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
	int unknown;
public:
	INIClass* file;
};