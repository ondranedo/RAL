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
#include "GLRenderingAPI.h"
#include <core/utility/Logger.h>

#include <vendor/glad/include/glad/glad.h>
#include <vendor/glfw/include/GLFW/glfw3.h>
namespace RAL
{

    void GLRenderingAPI::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void GLRenderingAPI::clearColour(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        auto nor = [](uint8_t num)->float{return static_cast<float>(num)/255.0f;};
        glClearColor(nor(r),nor(g),nor(b),nor(a));
    }

    void GLRenderingAPI::init()
    {
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            RAL_LOG_FATAL("Failed to load GLAD");
            return;
        }
        glGenVertexArrays(1, &m_VA);
        glGenBuffers(1, &m_VB);
        glGenBuffers(1, &m_IB);
        glBindVertexArray(m_VA);
    }

    void GLRenderingAPI::release()
    {
        glDeleteVertexArrays(1,&m_VA);
        glDeleteBuffers(1,&m_VB);
        glDeleteBuffers(1,&m_IB);
    }

    void GLRenderingAPI::draw()
    {
        if(!(m_isVBDataSet && m_isIBDataSet)){
            RAL_LOG_FATAL("Cannot draw elements VB or IB is not set");
        }
        glBindVertexArray(m_VA);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IB);
        glBindBuffer(GL_ARRAY_BUFFER, m_VB);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3* sizeof(float),(void*) 0);
        glDrawElements(GL_TRIANGLES,static_cast<GLsizei>(m_indiciesCount),GL_UNSIGNED_INT, nullptr);
    }

    void GLRenderingAPI::bind(const IndexBuffer &indexBuffer)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IB);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(indexBuffer.getSize()), indexBuffer.getData(),
                     Buffer::Usage::STATIC == indexBuffer.getDrawUsage() ? GL_STATIC_DRAW :
                     Buffer::Usage::DYNAMIC == indexBuffer.getDrawUsage() ? GL_DYNAMIC_DRAW :
                     GL_STREAM_DRAW);
        m_indiciesCount = indexBuffer.getIndeciesCount();
        m_isIBDataSet = true;

    }

    void GLRenderingAPI::bind(const VertexBuffer &vertexBuffer)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_VB);
        glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertexBuffer.getSize()), vertexBuffer.getData(),
                     Buffer::Usage::STATIC == vertexBuffer.getDrawUsage() ? GL_STATIC_DRAW :
                     Buffer::Usage::DYNAMIC == vertexBuffer.getDrawUsage() ? GL_DYNAMIC_DRAW :
                     GL_STREAM_DRAW);
        m_isVBDataSet = true;
    }

    void GLRenderingAPI::unbind(const IndexBuffer &indexBuffer)
    {

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        m_IB = 0;
        m_indiciesCount = 0;
        m_isIBDataSet = false;
    }

    void GLRenderingAPI::unbind(const VertexBuffer &vertexBuffer)
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        m_VB = 0;
        m_isVBDataSet = false;
    }
}