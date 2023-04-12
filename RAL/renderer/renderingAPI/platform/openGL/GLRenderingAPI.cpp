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

#include <renderer/renderingAPI/platform/openGL/GLTypes.h>

namespace RAL
{

    void GLRenderingAPI::clear()
    {
        auto nor = [](uint8_t num)->float{return static_cast<float>(num)/255.0f;};
        glClearColor(nor(m_clearColour[0]),nor(m_clearColour[1]),nor(m_clearColour[2]),nor(m_clearColour[3]));
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void GLRenderingAPI::init()
    {
        glGenVertexArrays(1, &m_vertexArray);
        glGenBuffers(1, &m_vertexBuffer);
        glGenBuffers(1, &m_indexBuffer);
        glBindVertexArray(m_vertexArray);
    }

    void GLRenderingAPI::release()
    {
        glDeleteVertexArrays(1,&m_vertexArray);
        glDeleteBuffers(1,&m_vertexBuffer);
        glDeleteBuffers(1,&m_indexBuffer);
    }

    void GLRenderingAPI::draw()
    {
        setBindables();
        // TODO: set shader, !do not compile shader every frame!
        //       compile shader only when shader is changed, or when shader is not compiled yet
        //       shader ID should be stored in hashmap of compiled shaders
        setAttributes();

        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_indicesCount), GL_UNSIGNED_INT, nullptr);
    }

    void GLRenderingAPI::setBindables() {
        RAL_ASSERTRV(m_vertexBuffer, "Cannot draw to window %s VB is not set", m_window->getSpec().m_title);
        RAL_ASSERTRV(m_indexBuffer, "Cannot draw to window %s IB is not set", m_window->getSpec().m_title);

        glBindVertexArray(m_vertexArray);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    }

    void GLRenderingAPI::setAttributes() {
        GLsizei stride = m_vertexBufferLayout.getStride(), offset = 0, index = 0;
        stride+= 8 - stride %8 ; // padding to 8 bytes
        // TODO: Get index layout location directly from shader
        //       https://docs.gl/gl4/glGetAttribLocation
        for (const auto &element: m_vertexBufferLayout.getLayout()) {
            glVertexAttribPointer(index,
                                  VertexBufferLayout::EntryTypeComponents(element),
                                  GLTypes::getGLType(VertexBufferLayout::EntryTypeToDataType(element)),
                                  GL_FALSE, // TODO: make this configurable
                                  stride, reinterpret_cast<void *>(offset));
            glEnableVertexAttribArray(index++);
            offset += VertexBufferLayout::EntryTypeSize(element);
        }
    }

    void GLRenderingAPI::bind(const IndexBuffer &indexBuffer)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(indexBuffer.getSize()), indexBuffer.getData(),
                     Buffer::Usage::STATIC == indexBuffer.getDrawUsage() ? GL_STATIC_DRAW :
                     Buffer::Usage::DYNAMIC == indexBuffer.getDrawUsage() ? GL_DYNAMIC_DRAW :
                     GL_STREAM_DRAW);
        m_indicesCount = indexBuffer.getIndeciesCount();
    }

    void GLRenderingAPI::bind(const VertexBuffer &vertexBuffer)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertexBuffer.getSize()), vertexBuffer.getData(),
                     Buffer::Usage::STATIC == vertexBuffer.getDrawUsage() ? GL_STATIC_DRAW :
                     Buffer::Usage::DYNAMIC == vertexBuffer.getDrawUsage() ? GL_DYNAMIC_DRAW :
                     GL_STREAM_DRAW);
        m_vertexBufferLayout = vertexBuffer.getLayout();
    }

    void GLRenderingAPI::setWindowToDraw() {
        RAL_ASSERTRV(m_window, "Window is not set");
        m_window->makeContextCurrent();
        if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(m_window->getProcAddress()))){
            RAL_LOG_FATAL("Failed to load GLAD");
            return;
        }
    }

    GLRenderingAPI::GLRenderingAPI():
    m_vertexBufferLayout(),
    m_indexBuffer(0),
    m_vertexBuffer(0),
    m_vertexArray(0),
    m_indicesCount(0)
    {
    }
}