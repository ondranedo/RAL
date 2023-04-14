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
#include <vector>
#include <tuple>
#include <string>
#include <optional>

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

    private:
        std::optional<unsigned int> m_programID;
        std::vector<std::pair<std::string, uint8_t>> m_programAttribLayout;
    };
};

#endif //RAL_PROJECT_GLPROGRAM_H
