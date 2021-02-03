#pragma once

#include "../FA2PP.h"

namespace FA2MFC
{
    class CPaintDC
    {
    public:
        CPaintDC(CWnd* pWnd)
        {
            JMP_THIS(0x558C2A);
        }

        ~CPaintDC()
        {
            JMP_THIS(0x558C9C);
        }

        operator ::CPaintDC*()
        {
            return (::CPaintDC*)(this);
        }
    };
}