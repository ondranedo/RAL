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

#include "ProgramData.h"
#include <cstring>

namespace RAL {
    ProgramData::ProgramData() {
        std::memset(this, 0, sizeof(ProgramData));
    }

    CustomProgramData::CustomProgramData() : m_data() {}

    void CustomProgramData::addData(const std::string &in_shader_name, void *data, size_t size) {
         m_data.push_back({data, size, in_shader_name});
    }

    const std::vector<CustomProgramData::Data> &CustomProgramData::getData() const {
        return m_data;
    }
} // RAL