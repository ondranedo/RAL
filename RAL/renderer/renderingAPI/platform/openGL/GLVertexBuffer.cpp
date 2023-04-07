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

#include <vendor/glad/include/glad/glad.h>
#include <core/utility/Asserts.h>

namespace RAL
{
    GLVertexBuffer::~GLVertexBuffer()
    {
        glDeleteBuffers(1, &m_id);
    }

    GLVertexBuffer::GLVertexBuffer()
    {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void GLVertexBuffer::setData(float *vertices, unsigned int size, DrawUsage usage)
    {
        glBufferData(GL_ARRAY_BUFFER, size, vertices,
                     usage == DrawUsage::VOLATILE ? GL_STREAM_DRAW :
                     usage == DrawUsage::STATIC ? GL_STATIC_DRAW :
                     GL_DYNAMIC_DRAW);
    }

    void GLVertexBuffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void GLVertexBuffer::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};