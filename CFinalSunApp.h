#pragma once

#include "FA2PP.h"

class NOVTABLE CFinalSunApp : public FA2CWinApp
{
public:
	static constexpr reference<char, 0x72A738, 260> const ExePath{}; // Where FA2.exe locates
	static constexpr reference<char, 0x72A530, 260> const MapPath{}; // Where current map locates 
	static constexpr reference<char, 0x72A634, 260> const FilePath{}; // Where mix files locates

	static constexpr reference<UINT, 0x7EE034> const ClipboardFormat{};

	CFinalSunApp() = default;

	//member properties
	
};