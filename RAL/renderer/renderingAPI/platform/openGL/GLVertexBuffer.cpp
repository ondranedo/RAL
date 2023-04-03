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
#include "GLVertexBuffer.h"

namespace RAL
{
    GLVertexBuffer::~GLVertexBuffer()
    {
        glDeleteBuffers(1,&m_VB);
    }

    GLVertexBuffer::GLVertexBuffer(const void* vertices)
    {
        glGenBuffers(1,&m_VB);
        glBindBuffer(GL_ARRAY_BUFFER,m_VB);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW);
    }

    void GLVertexBuffer::bindVB()
    {
        glBindBuffer(GL_ARRAY_BUFFER,m_VB);
    }

    void GLVertexBuffer::unbindVB()
    {
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }
};