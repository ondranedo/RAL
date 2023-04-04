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

#include <vendor/glad/include/glad/glad.h>
namespace RAL{

    GLVertexArray::~GLVertexArray(){
        glDeleteVertexArrays(1,&m_VA);
    }

    GLVertexArray::GLVertexArray()
    {
        glGenVertexArrays(1,&m_VA);
    }

    void GLVertexArray::bindVA()
    {
        glBindVertexArray(m_VA);
    }

    void GLVertexArray::unbindVA()
    {
        glBindVertexArray(m_VA);
    }

    void GLVertexArray::setLayout()
    {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }
};