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

#include <vendor/glad/gl_4.0_core_debug/include/glad/gl.h>
#include <vendor/glfw/include/GLFW/glfw3.h>

#include <renderer/renderingAPI/platform/openGL/GLTypes.h>
#include <algorithm>

namespace RAL
{

    void GLRenderingAPI::clear()
    {
        auto nor = [](uint8_t num) -> float { return static_cast<float>(num) / 255.0f; };
        glClearColor(nor(m_clearColour[0]), nor(m_clearColour[1]), nor(m_clearColour[2]), nor(m_clearColour[3]));
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
<<<<<<< refs/remotes/origin/renderer
        glDeleteVertexArrays(1,&m_vertexArray);
        glDeleteBuffers(1,&m_vertexBuffer);
        glDeleteBuffers(1,&m_indexBuffer);

        for(auto& program : m_programs)
            delete program.second;
        m_programs.clear();
=======
        glDeleteVertexArrays(1, &m_vertexArray);
        glDeleteBuffers(1, &m_vertexBuffer);
        glDeleteBuffers(1, &m_indexBuffer);
>>>>>>> TextureManager 😁😎🦄🐲
    }

    void GLRenderingAPI::draw()
    {
        m_activeProgram->setActive();
        setBindables();
        setAttributes();

        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_indicesCount), GL_UNSIGNED_INT, nullptr);
    }

<<<<<<< refs/remotes/origin/renderer
    void GLRenderingAPI::setBindables() {
        RAL_ASSERTRV(m_vertexBuffer, "Cannot draw to window %s VB is not set", m_window->getSpec().title);
        RAL_ASSERTRV(m_indexBuffer, "Cannot draw to window %s IB is not set", m_window->getSpec().title);
=======
    void GLRenderingAPI::setBindables()
    {
        RAL_ASSERTRV(m_vertexBuffer, "Cannot draw to window %s VB is not set", m_window->getSpec().m_title);
        RAL_ASSERTRV(m_indexBuffer, "Cannot draw to window %s IB is not set", m_window->getSpec().m_title);
>>>>>>> TextureManager 😁😎🦄🐲

        glBindVertexArray(m_vertexArray);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    }

<<<<<<< refs/remotes/origin/renderer
    void GLRenderingAPI::setAttributes() {
        GLsizei stride = m_vertexBufferLayout.getStride(), offset = 0;
        int index;
        stride += 8 - stride % 8; // TODO: make this configurable
        for (const auto &element: m_vertexBufferLayout.getLayout()) {
            // Get attrib index from program
            index = m_activeProgram->getAttribLocation(VertexBufferLayout::EntryTypeToString(element));
            if(index == -1)
            {
                RAL_LOG_FATAL("Attribute %s is not found in active GL program", VertexBufferLayout::EntryTypeToString(element).c_str());
                return;
            }

            // Setting attribute
=======
    void GLRenderingAPI::setAttributes()
    {
        GLsizei stride = m_vertexBufferLayout.getStride(), offset = 0, index = 0;
        stride += 8 - stride % 8; // padding to 8 bytes
        // TODO: Get index layout location directly from shader
        //       https://docs.gl/gl4/glGetAttribLocation
        for (const auto &element: m_vertexBufferLayout.getLayout())
        {
>>>>>>> TextureManager 😁😎🦄🐲
            glVertexAttribPointer(index,
                                  VertexBufferLayout::EntryTypeComponents(element),
                                  GLTypes::getGLType(VertexBufferLayout::EntryTypeToDataType(element)),
                                  VertexBufferLayout::EntryTypeShouldBeNormalized(element),
                                  stride, reinterpret_cast<void *>(offset));
            glEnableVertexAttribArray(index);
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

    void GLRenderingAPI::setWindowToDraw()
    {
        RAL_ASSERTRV(m_window, "Window is not set");
        m_window->makeContextCurrent();
        if (!gladLoadGL(reinterpret_cast<GLADloadfunc>(m_window->getProcAddress())))
        {
            RAL_LOG_FATAL("Failed to load GLAD");
            return;
        }
    }

    GLRenderingAPI::GLRenderingAPI() :
            m_vertexBufferLayout(),
            m_indexBuffer(0),
            m_vertexBuffer(0),
            m_vertexArray(0),
            m_indicesCount(0)
    {
    }

    void GLRenderingAPI::setProgram(uint16_t program) {
        if(m_programs.find(program) == m_programs.end()){
            RAL_LOG_ERROR("Program %d is not compiled", program);
            return;
        }
        m_activeProgram = m_programs[program];
    }

    void GLRenderingAPI::compileProgram(uint16_t id, const std::string &vertex, const std::string &fragment) {
        GLProgram* program = new GLProgram;
        if(program->compile(vertex, fragment))
        {
            m_programs[id] = program;
            RAL_LOG_DEBUG("Program %d compiled", id);
        }
        else
        {
            RAL_LOG_ERROR("Program %d compilation failed", id);
            delete program;
        }
    }

    void GLRenderingAPI::sendProgramData(const ProgramData &data) {

    }

    void GLRenderingAPI::sendProgramData(const ProgramData &data, const CustomProgramData &custom_data) {

    }
}