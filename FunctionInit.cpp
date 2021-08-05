#include "Drawing.h"
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

#include "CMixFile.h"
#include "CLoading.h"
#include "GlobalVars.h"
#include "CCRC.h"
struct FakeCccFile
{
public:
	FakeCccFile(bool open = false) { JMP_THIS(0x5298C0); }
	~FakeCccFile() { JMP_THIS(0x5298F0); }
	int open(unsigned int crc, Cmix_file* pMix) { JMP_THIS(0x529900); }
	void close() { JMP_THIS(0x529D00); }

	void* vfptr;
	bool DataLoaded;
	bool Attached;
	unsigned char* Data;
	unsigned char _GAP[36];
	unsigned int FileSize;
};
void* CLoading::ReadWholeFile(ppmfc::CString filename)
{
	ppmfc::CString filepath = GlobalVars::FilePath();
	filepath += filename;
	HANDLE hFile = CreateFile(filepath, GENERIC_READ, FILE_SHARE_READ, nullptr,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwSize = GetFileSize(hFile, nullptr);
		auto pBuffer = GameCreateArray<unsigned char>(dwSize);
		ReadFile(hFile, pBuffer, dwSize, nullptr, nullptr);
		CloseHandle(hFile);
		return pBuffer;
	}

	auto nMix = GlobalVars::Dialogs::CLoading->SearchFile(filename);
	if (CMixFile::HasFile(filename, nMix))
	{
		CMixFile::ExtractFile(filename, filepath, nMix);
		HANDLE hFile = CreateFile(filepath, GENERIC_READ, FILE_SHARE_READ, nullptr,
			OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			DWORD dwSize = GetFileSize(hFile, nullptr);
			auto pBuffer = GameCreateArray<unsigned char>(dwSize);
			ReadFile(hFile, pBuffer, dwSize, nullptr, nullptr);
			CloseHandle(hFile);
			DeleteFile(filepath);
			return pBuffer;
		}
	}

	return nullptr;
}

bool CLoading::HasFile(ppmfc::CString filename)
{
	ppmfc::CString filepath = GlobalVars::FilePath();
	filepath += filename;
	HANDLE hFile = CreateFile(filepath, GENERIC_READ, FILE_SHARE_READ, nullptr,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);
		return true;
	}
	auto nMix = GlobalVars::Dialogs::CLoading->SearchFile(filename);
	return CMixFile::HasFile(filename, nMix);
}

