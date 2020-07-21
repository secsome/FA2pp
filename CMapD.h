#pragma once

#include "FA2PP.h"

class NOVTABLE CMapD : public FA2CDialog
{
public:
	CMapD() = default;

	//member properties
	CEdit				CETSize; // 92
	CComboBox	CCBTheater; // 152
	CString			CString_Width; // 212
	CString			CString_Height; // 216
};