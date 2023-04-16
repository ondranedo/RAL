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

#ifndef RAL_PROJECT_PROGRAMDATA_H
#define RAL_PROJECT_PROGRAMDATA_H

#include <core/memoryManager/Overload.h>
#include <cstdint>
#include <string>
#include <vector>

namespace RAL {
    // This uniform parameters are used in all programs.
    // Program can have more parameters, but they are not used in all programs,
    // so you have to specify CustomProgramData
    struct ProgramData {
        void* MVP;
        void* colour;
        void* metallicity;
        void* roughness;
        void* luminance;
        void* luminanceColour;

        size_t MVPSize;
        size_t colourSize;
        size_t metallicitySize;
        size_t roughnessSize;
        size_t luminanceSize;
        size_t luminanceColourSize;

        // TODO: Important for shader documentation
        const char* MVPName = "u_MVP";
        const char* colourName = "u_colour";
        const char* metallicityName = "u_metallicity";
        const char* roughnessName = "u_roughness";
        const char* luminanceName = "u_luminance";
        const char* luminanceColourName = "u_luminanceColour";

        ProgramData();
    };

    class CustomProgramData {
    public:
        enum class Type : uint8_t {
            UNKNOWN,
            FLOAT, VEC2, VEC3, VEC4,
            MAT4, INT, BOOL,
            UINT, UVEC2, UVEC3, UVEC4,
            SAMPLER2D
        };
    private:
        struct Data {
            void* data;
            Type type;
            size_t size;
            std::string uniform_name;
        };
    public:
        CustomProgramData();

        void addData(void* data, size_t size, Type type, const std::string& in_shader_name);
        [[nodiscard]] const std::vector<Data>& getData() const;
        static uint8_t typeSize(Type type);
        static std::string typeToString(Type type);
    private:
        std::vector<Data> m_data;
    };
} // RAL

#endif //RAL_PROJECT_PROGRAMDATA_H
