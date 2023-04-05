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
        glDeleteBuffers(1, &m_VB);
    }

    /**
     * Mode can be number from 1 to 3
     * 1: GL_STREAM_DRAW Data is set only once and used by the GPU few times
     * 2: GL_STATIC_DRAW Data is set only once and used many times
     * 3: GL_DYNAMIC_DRAW Data is changed a lot and used many times
    */
    //TODO ENUM GL_STREAM_DRAW = VOLATILE
    GLVertexBuffer::GLVertexBuffer(float *vertices,unsigned int size,unsigned char mode)
    {
        glGenBuffers(1, &m_VB);
        glBindBuffer(GL_ARRAY_BUFFER, m_VB);
        switch (mode)
        {
            case 1:
                glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STREAM_DRAW);
                break;
            case 2:
                glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
                break;
            case 3:
                glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
                break;
            default:
                RAL_LOG_FATAL("Wrong draw usage mode must be 1-3");
        }
    }

    void GLVertexBuffer::bindVB()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_VB);
    }

    void GLVertexBuffer::unbindVB()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};