#pragma once

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long dword;
typedef unsigned __int64 qword;
// typedef byte fourcc[4];

#include <cstring>

// std::string in VC6
class xcc_string
{
public:
	xcc_string(const char* str = "")
	{
		assign(str, strlen(str));
	}

	~xcc_string() JMP_THIS(0x43A410);

	xcc_string& operator=(const char* src)
	{
		return assign(src, strlen(src));
	}

	xcc_string& operator=(const xcc_string& str)
	{
		return assign(str, 0, 0xFFFFFFFF);
	}

	xcc_string& operator+=(char ch)
	{
		return append(1, ch);
	}

	const char* c_str() const
	{
		return _Ptr;
	}

protected:
	xcc_string& append(size_t dlen, char ch) JMP_THIS(0x528E70);
	xcc_string& assign(const char* src, size_t len) JMP_THIS(0x4556A0);
	xcc_string& assign(const xcc_string& another, size_t lenMin, size_t lenMax) JMP_THIS(0x43A450);

private:
	// std::allocator<char> allocator;
	char allocator{ 0 };
	char* _Ptr{ nullptr };
	size_t _Len{ 0 };
	size_t _Res{ 0 };
};