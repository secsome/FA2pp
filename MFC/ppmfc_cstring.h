#pragma once

#include "ppmfc_forward.h"

_PPMFC_BEGIN

_PPMFC_STRUCT(CStringData)
{
    long nRefs;     // reference count
    int nDataLength;
    int nAllocLength;
    // TCHAR data[nAllocLength]

    TCHAR* data()
    {
        return (TCHAR*)(this + 1);
    }
};

_PPMFC_CLASS(CString)
{
public:
    CString() _PPMFC_THISCALL(0x406F70);
    CString(LPCTSTR lpch, int nLength) _PPMFC_THISCALL(0x54F598);
    CString(const CString & stringSrc) _PPMFC_THISCALL(0x555C84);
    CString(LPCSTR lpsz) _PPMFC_THISCALL(0x555F7D);
    CString(LPCWSTR lpsz) _PPMFC_THISCALL(0x555FCF);
    ~CString() _PPMFC_THISCALL(0x555F0F);

    CStringData* CString::GetData() const
        { ASSERT(m_pchData != NULL); return ((CStringData*)m_pchData) - 1; }
    int CString::GetLength() const
        { return GetData()->nDataLength; }
    int CString::GetAllocLength() const
        { return GetData()->nAllocLength; }
    BOOL CString::IsEmpty() const
        { return GetData()->nDataLength == 0; }

    const CString& operator=(TCHAR ch)
        _PPMFC_THISCALL(0x54F5CC);

    int Delete(int at, int length)
        _PPMFC_THISCALL(0x54F5E1);

    int Insert(int at, LPCSTR lpsz)
        _PPMFC_THISCALL(0x54F639);

    int Replace(LPCSTR from, LPCSTR to)
        _PPMFC_THISCALL(0x54F6EE);

    CString* Right(CString * stringMem, int at)
        _PPMFC_THISCALL(0x54F851);

    CString Right(int at)
        { CString ret; Right(&ret, at); return ret; }

    CString* Left(CString* stringMem, int at)
        _PPMFC_THISCALL(0x54F8CD);

    CString Left(int at)
        { CString ret; Left(&ret, at); return ret; }

    int ReverseFind(TCHAR ch) const
        _PPMFC_THISCALL(0x54F945);

    int Find(LPCTSTR lpszSub) const
        _PPMFC_THISCALL(0x54F967);

    int Find(LPCTSTR lpszSub, int from) const
        _PPMFC_THISCALL(0x54F975);

    void TrimRight()
        _PPMFC_THISCALL(0x54F9A0);

    void TrimLeft()
        _PPMFC_THISCALL(0x54F9EC);

    void Trim()
        { TrimLeft(); TrimRight(); }

    void AllocBuffer(int nLen)
        _PPMFC_THISCALL(0x555D7C);

    void FreeData()
        _PPMFC_THISCALL(0x555DFE);

    void Release()
        _PPMFC_THISCALL(0x555E46);

    static void _PPMFC_API Release(CStringData* pStringData)
        _PPMFC_STDCALL(0x555E77);

    void Empty()
        _PPMFC_THISCALL(0x555E9A);

    void CopyBeforeWrite()
        _PPMFC_THISCALL(0x555EB8);

    void AllocBeforeWrite(int nLen)
        _PPMFC_THISCALL(0x555EE6);

    void AllocCopy(CString& dest, int nCopyLen, int nCopyIndex, int nExtraLen) const
        _PPMFC_THISCALL(0x555F39);

    void AssignCopy(int nSrcLen, LPCTSTR lpszSrcData)
        _PPMFC_THISCALL(0x55601B);

    const CString& operator=(CString& str)
        _PPMFC_THISCALL(0x556048);

    const CString& operator=(LPCSTR lpsz)
        _PPMFC_THISCALL(0x556098);

    const CString& operator=(LPCWSTR lpsz)
        _PPMFC_THISCALL(0x5560BF);

    void ConcatCopy(int nSrc1Len, LPCTSTR lpszSrc1Data, int nSrc2Len, LPCTSTR lpszSrc2Data)
        _PPMFC_THISCALL(0x556100);

    friend CString _PPMFC_API operator+(const CString& string1,
        const CString& string2)
        _PPMFC_STDCALL(0x55613E);

    friend CString _PPMFC_API operator+(const CString& string, LPCTSTR lpsz)
        _PPMFC_STDCALL(0x5561A4);

    friend CString _PPMFC_API operator+(LPCTSTR lpsz, const CString& string)
        _PPMFC_STDCALL(0x556218);

    void ConcatInPlace(int nSrcLen, LPCTSTR lpszSrcData)
        _PPMFC_THISCALL(0x55628C);

    const CString& operator+=(LPCTSTR lpsz)
        _PPMFC_THISCALL(0x5562EB);

    const CString& operator+=(TCHAR ch)
        _PPMFC_THISCALL(0x556312);

    const CString& operator+=(const CString& string)
        _PPMFC_THISCALL(0x556327);

    LPTSTR GetBuffer(int nMinBufLength)
        _PPMFC_THISCALL(0x55633F);

    void ReleaseBuffer(int nNewLength = -1)
        _PPMFC_THISCALL(0x55638E);

    LPTSTR GetBufferSetLength(int nNewLength)
        _PPMFC_THISCALL(0x5563B6);

    int Find(TCHAR ch) const
        _PPMFC_THISCALL(0x5563D6);

    int Find(TCHAR ch, int from) const
        _PPMFC_THISCALL(0x5563E4);

    void MakeUpper()
        _PPMFC_THISCALL(0x556411);

    void MakeLower()
        _PPMFC_THISCALL(0x556423);

    void SetAt(int nIndex, TCHAR ch)
        _PPMFC_THISCALL(0x556435);

    BOOL LoadString(UINT nID)          // load from string resource, 255 chars max
        _PPMFC_THISCALL(0x556507);

    operator const char*() const
        { return m_pchData; }

    bool operator< (const CString& another) const
        { return strcmp(this->m_pchData, another) < 0; }

    LPTSTR m_pchData;   // pointer to ref counted string data


public:
    // Extra implements not contained in FA2

    CString CString::Mid(int nFirst) const
    {
        return Mid(nFirst, GetData()->nDataLength - nFirst);
    }

    CString CString::Mid(int nFirst, int nCount) const
    {
        // out-of-bounds requests return sensible things
        if (nFirst < 0)
            nFirst = 0;
        if (nCount < 0)
            nCount = 0;

        if (nFirst + nCount > GetData()->nDataLength)
            nCount = GetData()->nDataLength - nFirst;
        if (nFirst > GetData()->nDataLength)
            nCount = 0;

        CString dest;
        AllocCopy(dest, nCount, nFirst, 0);
        return dest;
    }

#ifdef _MAC
#define TCHAR_ARG   int
#define WCHAR_ARG   unsigned
#define CHAR_ARG    int
#else
#define TCHAR_ARG   TCHAR
#define WCHAR_ARG   WCHAR
#define CHAR_ARG    char
#endif

#if defined(_68K_) || defined(_X86_)
#define DOUBLE_ARG  _AFX_DOUBLE
#else
#define DOUBLE_ARG  double
#endif

#define FORCE_ANSI      0x10000
#define FORCE_UNICODE   0x20000

	void CString::FormatV(LPCTSTR lpszFormat, va_list argList)
	{
		ASSERT(AfxIsValidString(lpszFormat, FALSE));

		va_list argListSave = argList;

		// make a guess at the maximum length of the resulting string
		int nMaxLen = 0;
		for (LPCTSTR lpsz = lpszFormat; *lpsz != '\0'; lpsz = _tcsinc(lpsz))
		{
			// handle '%' character, but watch out for '%%'
			if (*lpsz != '%' || *(lpsz = _tcsinc(lpsz)) == '%')
			{
				nMaxLen += _tclen(lpsz);
				continue;
			}

			int nItemLen = 0;

			// handle '%' character with format
			int nWidth = 0;
			for (; *lpsz != '\0'; lpsz = _tcsinc(lpsz))
			{
				// check for valid flags
				if (*lpsz == '#')
					nMaxLen += 2;   // for '0x'
				else if (*lpsz == '*')
					nWidth = va_arg(argList, int);
				else if (*lpsz == '-' || *lpsz == '+' || *lpsz == '0' ||
					*lpsz == ' ')
					;
				else // hit non-flag character
					break;
			}
			// get width and skip it
			if (nWidth == 0)
			{
				// width indicated by
				nWidth = _ttoi(lpsz);
				for (; *lpsz != '\0' && _istdigit(*lpsz); lpsz = _tcsinc(lpsz))
					;
			}
			ASSERT(nWidth >= 0);

			int nPrecision = 0;
			if (*lpsz == '.')
			{
				// skip past '.' separator (width.precision)
				lpsz = _tcsinc(lpsz);

				// get precision and skip it
				if (*lpsz == '*')
				{
					nPrecision = va_arg(argList, int);
					lpsz = _tcsinc(lpsz);
				}
				else
				{
					nPrecision = _ttoi(lpsz);
					for (; *lpsz != '\0' && _istdigit(*lpsz); lpsz = _tcsinc(lpsz))
						;
				}
				ASSERT(nPrecision >= 0);
			}

			// should be on type modifier or specifier
			int nModifier = 0;
			switch (*lpsz)
			{
				// modifiers that affect size
			case 'h':
				nModifier = FORCE_ANSI;
				lpsz = _tcsinc(lpsz);
				break;
			case 'l':
				nModifier = FORCE_UNICODE;
				lpsz = _tcsinc(lpsz);
				break;

				// modifiers that do not affect size
			case 'F':
			case 'N':
			case 'L':
				lpsz = _tcsinc(lpsz);
				break;
			}

			// now should be on specifier
			switch (*lpsz | nModifier)
			{
				// single characters
			case 'c':
			case 'C':
				nItemLen = 2;
				va_arg(argList, TCHAR_ARG);
				break;
			case 'c' | FORCE_ANSI:
			case 'C' | FORCE_ANSI:
				nItemLen = 2;
				va_arg(argList, CHAR_ARG);
				break;
			case 'c' | FORCE_UNICODE:
			case 'C' | FORCE_UNICODE:
				nItemLen = 2;
				va_arg(argList, WCHAR_ARG);
				break;

				// strings
			case 's':
			{
				LPCTSTR pstrNextArg = va_arg(argList, LPCTSTR);
				if (pstrNextArg == NULL)
					nItemLen = 6;  // "(null)"
				else
				{
					nItemLen = lstrlen(pstrNextArg);
					nItemLen = MAX(1, nItemLen);
				}
				break;
			}

			case 'S':
			{
#ifndef _UNICODE
				LPWSTR pstrNextArg = va_arg(argList, LPWSTR);
				if (pstrNextArg == NULL)
					nItemLen = 6;  // "(null)"
				else
				{
					nItemLen = wcslen(pstrNextArg);
					nItemLen = MAX(1, nItemLen);
				}
#else
				LPCSTR pstrNextArg = va_arg(argList, LPCSTR);
				if (pstrNextArg == NULL)
					nItemLen = 6; // "(null)"
				else
				{
					nItemLen = lstrlenA(pstrNextArg);
					nItemLen = max(1, nItemLen);
				}
#endif
				break;
			}

			case 's' | FORCE_ANSI:
			case 'S' | FORCE_ANSI:
			{
				LPCSTR pstrNextArg = va_arg(argList, LPCSTR);
				if (pstrNextArg == NULL)
					nItemLen = 6; // "(null)"
				else
				{
					nItemLen = lstrlenA(pstrNextArg);
					nItemLen = MAX(1, nItemLen);
				}
				break;
			}

#ifndef _MAC
			case 's' | FORCE_UNICODE:
			case 'S' | FORCE_UNICODE:
			{
				LPWSTR pstrNextArg = va_arg(argList, LPWSTR);
				if (pstrNextArg == NULL)
					nItemLen = 6; // "(null)"
				else
				{
					nItemLen = wcslen(pstrNextArg);
					nItemLen = MAX(1, nItemLen);
				}
				break;
			}
#endif
			}

			// adjust nItemLen for strings
			if (nItemLen != 0)
			{
				nItemLen = MAX(nItemLen, nWidth);
				if (nPrecision != 0)
					nItemLen = MIN(nItemLen, nPrecision);
			}
			else
			{
				switch (*lpsz)
				{
					// integers
				case 'd':
				case 'i':
				case 'u':
				case 'x':
				case 'X':
				case 'o':
					va_arg(argList, int);
					nItemLen = 32;
					nItemLen = MAX(nItemLen, nWidth + nPrecision);
					break;

				case 'e':
				case 'f':
				case 'g':
				case 'G':
					va_arg(argList, DOUBLE_ARG);
					nItemLen = 128;
					nItemLen = MAX(nItemLen, nWidth + nPrecision);
					break;

				case 'p':
					va_arg(argList, void*);
					nItemLen = 32;
					nItemLen = MAX(nItemLen, nWidth + nPrecision);
					break;

					// no output
				case 'n':
					va_arg(argList, int*);
					break;

				default:
					ASSERT(FALSE);  // unknown formatting option
				}
			}

			// adjust nMaxLen for output nItemLen
			nMaxLen += nItemLen;
		}

		GetBuffer(nMaxLen);
		VERIFY(_vstprintf(m_pchData, lpszFormat, argListSave) <= GetAllocLength());
		ReleaseBuffer();

		va_end(argListSave);
	}

#ifdef TCHAR_ARG
#undef TCHAR_ARG
#endif
#ifdef WCHAR_ARG
#undef WCHAR_ARG
#endif
#ifdef CHAR_ARG
#undef CHAR_ARG
#endif
#ifdef DOUBLE_ARG
#undef DOUBLE_ARG
#endif
#ifdef FORCE_ANSI
#undef FORCE_ANSI
#endif
#ifdef FORCE_UNICODE
#undef FORCE_UNICODE
#endif

    void AFX_CDECL CString::Format(LPCTSTR lpszFormat, ...)
    {
        ASSERT(AfxIsValidString(lpszFormat, FALSE));

        va_list argList;
        va_start(argList, lpszFormat);
        FormatV(lpszFormat, argList);
        va_end(argList);
    }

    void AFX_CDECL CString::Format(UINT nFormatID, ...)
    {
        CString strFormat;
        VERIFY(strFormat.LoadString(nFormatID) != 0);

        va_list argList;
        va_start(argList, nFormatID);
        FormatV(strFormat, argList);
        va_end(argList);
    }

};

//BOOL _PPMFC_API AfxExtractSubString(CString& rString, LPCTSTR lpszFullString,
//    int iSubString, TCHAR chSep = '\n')
//    _PPMFC_STDCALL(0x5565B2);
//
//void _PPMFC_API AfxFormatStrings(CString& rString, UINT nIDS,
//    LPCTSTR const* rglpsz, int nString)
//    _PPMFC_STDCALL(0x55FBB7);
//
//void _PPMFC_API AfxFormatStrings(CString& rString, LPCTSTR lpszFormat,
//    LPCTSTR const* rglpsz, int nString)
//    _PPMFC_STDCALL(0x55FBF1);
//
//void _PPMFC_API AfxFormatString1(CString& rString, UINT nIDS, LPCTSTR lpsz1)
//    _PPMFC_STDCALL(0x55FCF0);
//
//void _PPMFC_API AfxFormatString2(CString& rString, UINT nIDS,
//    LPCTSTR lpsz1, LPCTSTR lpsz2)
//    _PPMFC_STDCALL(0x55FD07);

_PPMFC_END

// HASH
#include <string>
namespace std
{
	template<>
	struct hash<ppmfc::CString>
	{
		std::size_t operator()(ppmfc::CString const& s) const noexcept
		{
			return std::hash<std::string>()((LPCSTR)s);
		}
	};
}