#pragma once

#include "Helpers/Macro.h"

class CVxlFile
{
public:

    bool __cdecl LoadVXLFile(const char* path, int nMix) { JMP_STD(0x526360); }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="notused"></param>
    /// <param name="bSomeExtraDraw"></param>
    /// <param name="rotationX">5.2359877 mostly, 300 degrees</param>
    /// <param name="rotationY">0</param>
    /// <param name="rotationZ">(90 + 45*facing) degree to radian</param>
    /// <param name="pBuffer">Output Buffer</param>
    /// <param name="OutX"></param>
    /// <param name="OutY"></param>
    /// <param name="ZAdjust"></param>
    /// <param name="a10"></param>
    /// <param name="a11"></param>
    /// <param name="a12"></param>
    /// <param name="a13"></param>
    /// <param name="a14"></param>
    /// <returns></returns>
    bool __cdecl DrawVXLFacing(int notused, int bSomeExtraDraw, float rotationX, float rotationY, float rotationZ,
        unsigned char*& pBuffer, int* OutX, int* OutY, int ZAdjust, int a10, int a11, int a12, int a13, int a14)
        { JMP_STD(0x526F50); }
};