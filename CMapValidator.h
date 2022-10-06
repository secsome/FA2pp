#pragma once

#include "FA2PP.h"

class NOVTABLE CMapValidator : public ppmfc::CDialog
{
public:
	CMapValidator() JMP_THIS(0x4CEA50);
	~CMapValidator() JMP_THIS(0x426A60);

	// returns : can continue
	BOOL DoValidate() JMP_THIS(0x4CED70);

	int GetItemCount() const
	{
		return ::SendMessage(CLCResults.m_hWnd, LVM_GETITEMCOUNT, NULL, NULL);
	}

	// In vanilla FA2:
	// nType = 0 for Error
	// nType = 1 for Information
	int InsertItem(char* lpMessage, int nType) const
	{
		struct
		{
			UINT mask;
			int iItem;
			int iSubItem;
			UINT state;
			UINT stateMask;
			LPSTR pszText;
			int cchTextMax;
			int iImage;
			LPARAM lParam;
			int iIndent;
		} item;
		item.iSubItem = 0;
		item.mask = LVIF_TEXT | LVIF_IMAGE;
		item.iItem = GetItemCount();
		item.pszText = lpMessage;
		item.state = 0;
		item.stateMask = NULL;
		item.iImage = nType;
		item.lParam = NULL;
		return ::SendMessage(CLCResults.m_hWnd, LVM_INSERTITEM, NULL, reinterpret_cast<LPARAM>(&item));
	}

	//member properties
	DECLARE_PROPERTY(CImageList, CILImages);
	DECLARE_PROPERTY(CListCtrl, CLCResults);
};