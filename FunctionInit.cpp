#include "Drawing.h"

#include "CMixFile.h"
#include "CLoading.h"
#include "CCRC.h"
#include "CShpFile.h"
#include "CFinalSunApp.h"

HSVClass::operator RGBClass() const
{
	if (S == 0u)
		return { V, V, V };

	unsigned char region = H / 43;
	unsigned char remainder = (H - (region * 43)) * 6;

	unsigned char p = (V * (255 - S)) >> 8;
	unsigned char q = (V * (255 - ((S * remainder) >> 8))) >> 8;
	unsigned char t = (V * (255 - ((S * (255 - remainder)) >> 8))) >> 8;

	switch (region) {
	case 0:
		return { V, t, p };
	case 1:
		return { q, V, p };
	case 2:
		return { p, V, t };
	case 3:
		return { p, q, V };
	case 4:
		return { t, p, V };
	default:
		return { V, p, q };
	}
}
RGBClass::operator HSVClass() const
{
	int hue;
	int saturation;
	int value;
	int red = R;
	int green = G;
	int blue = B;

	hue = 0;

	value = red > green ? red : green;
	if (blue > value) value = blue;

	int white = red < green ? red : green;
	if (blue < white) white = blue;

	saturation = 0;
	if (value)
		saturation = ((value - white) * 255) / value;

	if (saturation != 0)
	{
		unsigned int tmp = value - white;
		unsigned int r1 = ((value - red) * 255) / tmp;
		unsigned int g1 = ((value - green) * 255) / tmp;
		unsigned int b1 = ((value - blue) * 255) / tmp;

		if (value == red)
			if (white == green)
				tmp = 5 * 256 + b1;
			else
				tmp = 1 * 256 - g1;
		else
			if (value == green)
				if (white == blue)
					tmp = 1 * 256 + r1;
				else
					tmp = 3 * 256 - b1;
			else
				if (white == red)
					tmp = 3 * 256 + g1;
				else
					tmp = 5 * 256 - r1;
		hue = tmp / 6;
	}

	return { (unsigned char)hue, (unsigned char)saturation, (unsigned char)value };
}

struct FakeString
{
	void assign(const char* src, unsigned int len) { JMP_THIS(0x4556A0); }
	void _Tidy(bool bUnk) { JMP_THIS(0x43A650); }
	char _Grow(unsigned int N, bool Trim) { JMP_THIS(0x43A650); }

	char allocator;
	char* _Ptr;
	unsigned int _Len;
	unsigned int _Res;
};

struct FakeCccFile
{
public:
	FakeCccFile(bool open = false) { JMP_THIS(0x5298C0); }
	~FakeCccFile() { JMP_THIS(0x5298F0); }
	int open(unsigned int crc, Cmix_file* pMix) { JMP_THIS(0x529900); }
	int open(FakeString* name) { JMP_THIS(0x529A30); }
	void close() { JMP_THIS(0x529D00); }

	void* vfptr;
	bool DataLoaded;
	bool Attached;
	unsigned char* Data;
	void* vfptr2;
	HANDLE Handle;
	bool IsOpen;
	int Pointer;
	void* MixFile;
	bool IsOpen2;
	int Offset;
	int Pointer2;
	bool ReadOnOpen;
	unsigned int FileSize;
};

struct FakeMixFile
{
	int read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead) { JMP_THIS(0x529B80); }
};

void* CLoading::ReadWholeFile(const char* filename, DWORD* pDwSize)
{
	ppmfc::CString filepath = CFinalSunApp::FilePath();
	filepath += filename;
	HANDLE hFile = CreateFile(filepath, GENERIC_READ, FILE_SHARE_READ, nullptr,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwSize = GetFileSize(hFile, nullptr);
		auto pBuffer = GameCreateArray<unsigned char>(dwSize);
		if (pDwSize)
			*pDwSize = dwSize;
		ReadFile(hFile, pBuffer, dwSize, nullptr, nullptr);
		CloseHandle(hFile);
		return pBuffer;
	}

	auto nMix = CLoading::Instance->SearchFile(filename);
	if (CMixFile::HasFile(filename, nMix))
	{
		auto pFile = (FakeCccFile*)0x8204B8;
		char temp[0x34];
		memcpy(temp, pFile, 0x34);
		if (CMixFile::LoadSHP(filename, nMix))
		{
			auto pBuffer = GameCreateArray<unsigned char>(pFile->FileSize);
			memcpy(pBuffer, pFile->Data, pFile->FileSize);
			if (pDwSize)
				*pDwSize = pFile->FileSize;
			if (pFile->IsOpen2)
				pFile->close();
			memcpy(pFile, temp, 0x34);
			return pBuffer;
		}
		else
		{
			if (pFile->IsOpen2)
				pFile->close();
			memcpy(pFile, temp, 0x34);
			return nullptr;
		}
	}

	return nullptr;
}

bool CLoading::HasFile(ppmfc::CString filename)
{
	ppmfc::CString filepath = CFinalSunApp::FilePath();
	filepath += filename;
	HANDLE hFile = CreateFile(filepath, GENERIC_READ, FILE_SHARE_READ, nullptr,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);
		return true;
	}
	auto nMix = CLoading::Instance->SearchFile(filename);
	return CMixFile::HasFile(filename, nMix);
}

