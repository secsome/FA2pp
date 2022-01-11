#pragma once

#include "FA2PP.h"

class NOVTABLE CMapD : public ppmfc::CDialog
{
public:
	CMapD() = default;

	//member properties
	ppmfc::CEdit				CETSize; // 92
	ppmfc::CComboBox	CCBTheater; // 152
	ppmfc::CString			CString_Width; // 212
	ppmfc::CString			CString_Height; // 216
};