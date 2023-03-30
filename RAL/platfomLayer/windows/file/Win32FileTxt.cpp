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
#include "Win32FileTxt.h"
#include <core/utility/Asserts.h>
#include <cstdio>
#include <vector>

namespace RAL::Win32 {
    Win32FileTxt::Win32FileTxt() = default;
    Win32FileTxt::~Win32FileTxt() = default;

    std::optional<std::vector<std::string>> Win32FileTxt::read() const {
        RAL_ASSERTR(m_file != nullptr,{}, "file is not open!");
        RAL_ASSERTR(m_mode == Mode::Read || m_mode == Mode::ReadWrite,{}, "file %s is not open in read mode!", m_path.c_str());
        std::optional<std::vector<std::string>> data(1);
        bool isRead = false;
        auto line = readLine();
        do
        {
            if (line.has_value()) { 
                data->push_back(line.value()); 
                isRead = true; 
                line = readLine();
            }
        }
        while(line.has_value());
        if(!isRead) data.reset();
        return data;
    }

    std::optional<std::string> Win32FileTxt::readLine() const {
        RAL_ASSERTR(m_file != nullptr,{}, "file is not open!");
        RAL_ASSERTR(m_mode == Mode::Read || m_mode == Mode::ReadWrite,{}, "file %s is not open in read mode!", m_path.c_str());
        std::optional<std::string> line = "";
        char c, isRead = 0;
        while((c = std::fgetc(m_file))!=EOF){
            isRead = 1;
            if(c=='\n') break;
            line->push_back(c);
        }
        if(!isRead) line.reset();
        return line;
    }

    void Win32FileTxt::write(const std::vector<std::string> &data) const {
        RAL_ASSERTRV(m_file != nullptr, "file is not open!");
        RAL_ASSERTRV(m_mode == Mode::Write || m_mode == Mode::ReadWrite || m_mode == Mode::Append, "file %s is not open in write/append mode!", m_path.c_str());
        for(const auto& line : data) {
            std::fprintf(m_file, "%s\n", line.c_str());
        }
    }

    void Win32FileTxt::write(const std::string &data) const {
        RAL_ASSERTRV(m_file != nullptr, "file is not open!");
        RAL_ASSERTRV(m_mode == Mode::Write || m_mode == Mode::ReadWrite || m_mode == Mode::Append, "file %s is not open in write/append mode!", m_path.c_str());
        std::fprintf(m_file, "%s\n", data.c_str());
    }

    void Win32FileTxt::reset() const {
        RAL_ASSERTRV(m_file != nullptr, "file is not open!");
        std::rewind(m_file);
    }

    const char *Win32FileTxt::getModeInFormat(File::Mode mode) {
        switch (mode) {
            case File::Mode::Read:      return "r";
            case File::Mode::Write:     return "w";
            case File::Mode::ReadWrite: return "w+";
            case File::Mode::Append:    return "a";
            default:
                RAL_ASSERTR(false, "r", "unknown file mode!, defaulting to read");
        }
    }
};
// RAL

#endif //!RAL_WINDOWS