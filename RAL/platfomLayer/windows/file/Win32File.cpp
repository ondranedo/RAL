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


#include "Win32File.h"
#include <core/utility/Asserts.h>

namespace RAL {
    Win32::Win32File::Win32File() : m_file(nullptr) {}

    Win32::Win32File::~Win32File() {
        RAL_ASSERT(m_file == nullptr, "File %s is not closed!, closing file...", m_path.c_str());
        if(m_file) close();
    }

    void Win32::Win32File::open(const std::string &path, File::Mode mode) {
        RAL_ASSERTRV(m_file == nullptr, "file %s is already open!", m_path.c_str());
        m_file = fopen(path.c_str(), getModeInFormat(mode));
        m_path = path;
        m_mode = mode;
        RAL_ASSERT(m_file != nullptr, "file is not open!, path: %s probably not valid", path.c_str());
    }

    void Win32::Win32File::close() {
        RAL_ASSERTRV(m_file != nullptr, "file is not open!");
        fclose(m_file);
        m_file = nullptr;
        m_path = "";
        m_mode = File::Mode::None;
    }
} // RAL