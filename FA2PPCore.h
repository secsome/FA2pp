#pragma once

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

//Assembly macros
#include "Helpers/ASMMacros.h"

#include <Memory.h>

#include <wchar.h>
#include <cstdio>

//Not gettable/settable members
#define PROTECTED_PROPERTY(type,name)\
	protected:\
		type name; \
	public:

/*
Operation: The Cleansing
These two replace a function's implementation.
R0 is used for functions which return a numeric value or a pointer.
RX is for functions without a return type.
Functions that return struct instances will have to be written manually.
I chose short names to keep things clean.
Example usage:
virtual int foo(int bar) R0;
virtual void alla(double malla) RX;
*/

#define R0 {return 0;}
#define RX {}
#define RT(type) {return type();}

#define NOVTABLE __declspec(novtable)

#define SAFE_RELEASE(ptr) {if(!ptr) delete[] ptr;}

struct noinit_t final {};