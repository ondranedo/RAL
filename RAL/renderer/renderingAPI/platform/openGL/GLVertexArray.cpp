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
#include "GLVertexArray.h"

#include <core/utility/Logger.h>
#include <vendor/glad/include/glad/glad.h>

namespace RAL {

    GLVertexArray::~GLVertexArray() {
        glDeleteVertexArrays(1, &m_id);
    }

    GLVertexArray::GLVertexArray() {
        glGenVertexArrays(1, &m_id);
    }

    void GLVertexArray::bind() const {
        glBindVertexArray(m_id);
    }

    void GLVertexArray::unbind() const {
        glBindVertexArray(0);
    }
}
