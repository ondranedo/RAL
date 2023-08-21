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

#ifdef RAL_WINDOWS
#include "Win32FileBin.h"
#include <core/utility/Asserts.h>
#include <cstdio>

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

    size_t Win32FileBin::readInto(void *dest, size_t elementSize, size_t elementCount) {
        RAL_ASSERTR(m_file != nullptr,{}, "file is not open!");
        RAL_ASSERTR(m_mode == Mode::Read || m_mode == Mode::ReadWrite,{}, "file %s is not open in read mode!", m_path.c_str());
        RAL_ASSERTR(dest != nullptr,{}, "no allocated memory to write into!");

        return std::fread(dest, elementSize, elementCount, m_file);
    }

    size_t Win32FileBin::readInto(void *dest, size_t elementSize) {
        RAL_ASSERTR(m_file != nullptr,{}, "file is not open!");
        RAL_ASSERTR(m_mode == Mode::Read || m_mode == Mode::ReadWrite,{}, "file %s is not open in read mode!", m_path.c_str());
        RAL_ASSERTR(dest != nullptr,{}, "no allocated memory to write into!");

        return std::fread(dest, elementSize, 1, m_file);
    }

    void Win32FileBin::writeFrom(const void *src, size_t elementSize, size_t elementCount) {
        RAL_ASSERTRV(m_file != nullptr, "file is not open!");
        RAL_ASSERTRV(m_mode == Mode::Write || m_mode == Mode::ReadWrite || m_mode == Mode::Append, "file %s is not open in write/append mode!", m_path.c_str());

        std::fwrite(src, elementSize, elementCount, m_file);
    }

    void Win32FileBin::writeFrom(const void *src, size_t elementSize) {
        RAL_ASSERTRV(m_file != nullptr, "file is not open!");
        RAL_ASSERTRV(m_mode == Mode::Write || m_mode == Mode::ReadWrite || m_mode == Mode::Append, "file %s is not open in write/append mode!", m_path.c_str());

        std::fwrite(src, elementSize, 1, m_file);
    }

    Win32FileBin::~Win32FileBin() = default;

    Win32FileBin::Win32FileBin() = default;
}
#endif //!RAL_WINDOWS