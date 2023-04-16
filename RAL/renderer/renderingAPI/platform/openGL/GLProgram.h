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

#ifndef RAL_PROJECT_GLPROGRAM_H
#define RAL_PROJECT_GLPROGRAM_H

#include <core/memoryManager/Overload.h>
#include <renderer/renderingAPI/ProgramData.h>
#include <vector>
#include <tuple>
#include <string>
#include <optional>
#include <unordered_map>

namespace RAL {
    class GLProgram {
    public:
        GLProgram();
        ~GLProgram();

        // Compiles the program from the given vertex and fragment shader
        // return false if the compilation failed, true otherwise
        bool compile(const std::string& vertex, const std::string& fragment);

        // Binds the program to the current context
        void setActive();

        // Returns the index location of the attribute with the given name,
        // returns -1 if the attribute is not found
        int getAttribLocation(const std::string& name);

        // Checks if the program is valid and has been compiled successfully,
        // and sends the data to the program, if the program is not valid,
        // the data is not sent
        void sendData(void* data, size_t size, CustomProgramData::Type type, const std::string& name);

        // Converts the given GL symbolic constant type to the CustomProgramData::Type
        static CustomProgramData::Type getDataTypeFromGLType(unsigned int type);

#ifdef RAL_DEBUG
        void printUniformLayout();
        void printAttribLayout();
#endif
    private:
        std::optional<unsigned int> m_programID;
        // [] = {name, layout_index}
        std::vector<std::pair<std::string, uint8_t>> m_programAttribLayout;
        // [] = {name, data_type
        std::unordered_map<std::string, std::pair<CustomProgramData::Type, uint8_t>> m_programUniforms;
    };
};

#endif //RAL_PROJECT_GLPROGRAM_H
