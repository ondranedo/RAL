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
#include "core/utility/Logger.h"

namespace RAL
{

    GLVertexArray::~GLVertexArray()
    {
        glDeleteVertexArrays(1, &m_id);
    }

    GLVertexArray::GLVertexArray()
    {
        glGenVertexArrays(1, &m_id);
    }

    void GLVertexArray::bind() const
    {
        glBindVertexArray(m_id);
    }

    void GLVertexArray::unbind() const
    {
        glBindVertexArray(0);
    }

    void GLVertexArray::setLayout(std::initializer_list<LayoutType> layout)
    {
        m_layout = layout;
        m_offset = 0;
        m_fullLayoutSize = getFullLayoutSize();
        addVertexData();
    }

    GLenum GLVertexArray::getGLDataType(LayoutType element)
    {
        switch (element)
        {
            case LayoutType::FLOAT:
                return GL_FLOAT;
            case LayoutType::FLOAT2:
                return GL_FLOAT;
            case LayoutType::FLOAT3:
                return GL_FLOAT;
            case LayoutType::FLOAT4:
                return GL_FLOAT;
            case LayoutType::INT:
                return GL_INT;
            case LayoutType::INT2:
                return GL_INT;
            case LayoutType::INT3:
                return GL_INT;
            case LayoutType::INT4:
                return GL_INT;
        }
    }


    unsigned int GLVertexArray::getComponentSize(BufferLayout::LayoutType element)
    {
        switch (element)
        {
            case LayoutType::FLOAT:
                m_componentSize = 1;
                return 1;
            case LayoutType::FLOAT2:
                m_componentSize = 2;
                return 2;
            case LayoutType::FLOAT3:
                m_componentSize = 3;
                return 3;
            case LayoutType::FLOAT4:
                m_componentSize = 4;
                return 4;
            case LayoutType::INT:
                m_componentSize = 1;
                return 1;
            case LayoutType::INT2:
                m_componentSize = 2;
                return 2;
            case LayoutType::INT3:
                m_componentSize = 3;
                return 3;
            case LayoutType::INT4:
                m_componentSize = 4;
                return 4;
        }
    }

    void GLVertexArray::addVertexData()
    {
        m_attributeIndex=0;
        for (auto element : m_layout)
        {
            glEnableVertexAttribArray(m_attributeIndex);
            glVertexAttribPointer(m_attributeIndex,
                                  static_cast<GLint>(getComponentSize(element)),
                                  getGLDataType(element),
                                  GL_FALSE,
                                  6 * sizeof(float),
                                  (GLvoid *) (getOffset() * sizeof(float)));
            RAL_LOG_DEBUG("New attribute pointer created: Index:%d Component size:%d Offset:%d",m_attributeIndex,m_componentSize,m_offset);
            m_attributeIndex++;
        }
    }

    unsigned int GLVertexArray::getFullLayoutSize()
    {
        for (auto element: m_layout)
        {
            m_fullLayoutSize += getComponentSize(element);
        }
        return m_fullLayoutSize;
    }

    unsigned int GLVertexArray::getOffset()
    {
        if(firstCall){
            firstCall = false;
            return 0;
        }
        m_offset = m_offset + m_componentSize;
        return m_offset;
    }

};