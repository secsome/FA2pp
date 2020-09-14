#pragma once

#include "Helpers/ASMMacros.h"

class FAStringAImpl;

class FAStringPtr {
public:
	FAStringPtr() = default;
	FAStringPtr(char* ptr) : ptr(ptr) {}

	operator FAStringAImpl* () {
		return ptr ? reinterpret_cast<FAStringAImpl*>(ptr - 12) : nullptr;
	}

	operator const char* const () {
		return ptr;
	}

	char* ptr{ nullptr };
};

class FAStringAImpl
{
public:
	FAStringAImpl() = default;

	operator FAStringPtr () {
		return FAStringPtr(&Text);
	}

	int RefCount{ 1 };
	int Size{ 1 };
	int MaxSize{ 1 };
	char Text{ '\0' };
};

class FAString
{
public:
	FAString() : pImpl(*(char**)0x5D4498) {}

	FAString(const char* text) { // CString::CString(CString *this, LPCSTR lpString)
		JMP_THIS(0x555F7D);
	}

	FAString(const wchar_t* text) { // CString::CString(CString *this, LPCWSTR lpWideCharStr)
		JMP_THIS(0x555FCF);
	}

	FAString(const FAString& other) {
		*this = other;
	}

	FAString& operator=(const FAString& other) { // CString::CString(class CString const &)
		JMP_THIS(0x555C84);
	}

	~FAString() { // CString::~CString(CString *__hidden this)
		JMP_THIS(0x555F0F);
	}

	char const* c_str() const noexcept {
		return pImpl.ptr;
	}

	operator char const* const& () const noexcept {
		return pImpl.ptr;
	}

	//private:
	FAStringPtr pImpl;
};
