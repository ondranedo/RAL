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

    GLVertexBuffer::GLVertexBuffer(float *vertices,unsigned int size,DrawUsage usage)
    {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        switch (usage)
        {
            case DrawUsage::VOLATILE:
                glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STREAM_DRAW);
                break;
            case DrawUsage::STATIC:
                glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
                break;
            case DrawUsage::DYNAMIC:
                glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
                break;
        }
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