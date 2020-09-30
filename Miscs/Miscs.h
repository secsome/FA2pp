#pragma once

#include "../FA2PP.h"

namespace Miscs {
    void TrimIndex(CString& string) {
        string.TrimLeft();
        string.TrimRight();
        int spaceIndex = string.Find(' ');
        if (spaceIndex > 0)
            string = string.Mid(0, spaceIndex);
    }
}