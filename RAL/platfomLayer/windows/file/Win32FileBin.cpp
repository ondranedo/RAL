/////////////////////////////////////////////////////////
// Copyright (C) 2023                                  //
// Ondřej Nedojedlý (https://www.github.com/ondranedo),//
// Matyáš Noska (https://www.github.com/sutiama),      //
// Vojtěch Šokala (https://github.com/Karnatour),      //
// Adam Wiszczor (https://github.com/1nome).           //
//                                                     //
// This file is part of `RAL_PROJECT` project          //
// which is released under `GNU General Public         //
// License v3.0` license.                              //
// See file `LICENSE` for full license details.        //
/////////////////////////////////////////////////////////

#include "Win32FileBin.h"
#include <core/utility/Asserts.h>

namespace RAL::Win32{
    const char *Win32FileBin::getModeInFormat(File::Mode mode) {
        switch (mode) {
            case File::Mode::Read:      return "rb";
            case File::Mode::Write:     return "wb";
            case File::Mode::ReadWrite: return "wb+";
            case File::Mode::Append:    return "ab";
            default:
                RAL_ASSERTR(false, "rb", "unknown file mode!, defaulting to read");
        }
    }

    void Win32FileBin::reset() const {
        RAL_ASSERTRV(m_file != nullptr, "file is not open!");
        std::rewind(m_file);
    }

    Win32FileBin::~Win32FileBin() = default;

    Win32FileBin::Win32FileBin() = default;
}