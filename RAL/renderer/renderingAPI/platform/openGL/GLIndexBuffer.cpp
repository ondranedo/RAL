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
#include "GLIndexBuffer.h"

#include <vendor/glad/include/glad/glad.h>

namespace RAL
{
    GLIndexBuffer::~GLIndexBuffer()
    {
        glDeleteBuffers(1, &m_id);
    }

    GLIndexBuffer::GLIndexBuffer()
    {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    }

    void GLIndexBuffer::setData(unsigned int *indices, unsigned int size, DrawUsage usage)
    {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices,
                     usage == DrawUsage::VOLATILE ? GL_STREAM_DRAW :
                     usage == DrawUsage::STATIC ? GL_STATIC_DRAW :
                     GL_DYNAMIC_DRAW);
    }

    void GLIndexBuffer::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    }

    void GLIndexBuffer::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
} // RAL