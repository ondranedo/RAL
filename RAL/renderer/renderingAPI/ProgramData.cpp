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
#include <core/utility/Types.h>

namespace RAL {
    ProgramData::ProgramData() {
        std::memset(this, 0, sizeof(ProgramData));
    }

    CustomProgramData::CustomProgramData() : m_data() {}

    void CustomProgramData::addData(void* data, size_t size, Type type, const std::string& in_shader_name) {
         m_data.push_back({data, type, size, in_shader_name});
    }

    const std::vector<CustomProgramData::Data> &CustomProgramData::getData() const {
        return m_data;
    }

    uint8_t CustomProgramData::typeSize(CustomProgramData::Type type) {
        switch (type) {
            case Type::FLOAT: return sizeof(float);
            case Type::VEC2: return sizeof(float) * 2;
            case Type::VEC3: return sizeof(float) * 3;
            case Type::VEC4: return sizeof(float) * 4;
            case Type::MAT4: return sizeof(float) * 16;
            case Type::INT: return sizeof(int);
            case Type::BOOL: return sizeof(bool);
            case Type::UINT: return sizeof(uint32_t);
            case Type::UVEC2: return sizeof(uint32_t) * 2;
            case Type::UVEC3: return sizeof(uint32_t) * 3;
            case Type::UVEC4: return sizeof(uint32_t) * 4;
        }
        RAL_LOG_ERROR("Unknown CustomProgramData type size");
        return 0;
    }

    std::string CustomProgramData::typeToString(CustomProgramData::Type type) {
        switch (type) {
            case Type::FLOAT: return "float";
            case Type::VEC2:  return "vec2";
            case Type::VEC3:  return "vec3";
            case Type::VEC4:  return "vec4";
            case Type::MAT4:  return "mat4";
            case Type::INT:   return "int";
            case Type::BOOL:  return "bool";
            case Type::UINT:  return "unsigned int";
            case Type::UVEC2: return "uvec2";
            case Type::UVEC3: return "uvec3";
            case Type::UVEC4: return "uvec4";
        }
        RAL_LOG_ERROR("Unknown CustomProgramData type size");
        return "unknown";
    }
} // RAL