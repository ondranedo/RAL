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

    GLIndexBuffer::GLIndexBuffer(unsigned int *indices, unsigned int size, DrawUsage usage)
    {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
        switch (usage)
        {
            case DrawUsage::VOLATILE:
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STREAM_DRAW);
                break;
            case DrawUsage::STATIC:
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
                break;
            case DrawUsage::DYNAMIC:
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_DYNAMIC_DRAW);
                break;
        }
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