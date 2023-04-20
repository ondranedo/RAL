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
#include "Renderer2D.h"

#include <vendor/glad/include/glad/glad.h>
#include <vendor/glfw/include/GLFW/glfw3.h>

#include <renderer/renderingAPI/platform/openGL/GLRenderingAPI.h>
#include <renderer/renderer2d/Renderer2D.h>


namespace RAL {

    float vertices[] = {
            // positions         // colors
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
            -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // top left
            0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right

    };
    unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,  // first Triangle
            1, 2, 3   // second Triangle
    };

    void Renderer2D::renderLoop() {
        /// Vojtuv codik
        glClearColor(34.0f/255.0f, 34.0f/255.0f, 34.0f/255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        m_renderingAPI->useDefaultProgram();
        //m_vertexArray->bind();
        m_indexBuffer->bind();
        m_vertexBuffer->bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void Renderer2D::addData(VertexBuffer* vertex, IndexBuffer* index) {

    }

    void Renderer2D::init() {
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        {
            RAL_LOG_FATAL("Failed to initialize GLAD");
        }
        m_vertexArray = new GLVertexArray;
        m_renderingAPI = new GLRenderingAPI;
        m_vertexBuffer = new GLVertexBuffer;
        m_indexBuffer = new GLIndexBuffer;
        m_renderingAPI->init();
        //m_vertexArray->bind();
        m_vertexBuffer->setData(vertices, sizeof(vertices), Buffer::DrawUsage::STATIC);
        m_indexBuffer->setData(indices, sizeof(indices), Buffer::DrawUsage::STATIC);
        m_vertexArray->setLayout({BufferLayout::LayoutType::FLOAT3,BufferLayout::LayoutType::FLOAT3});
    }

    void Renderer2D::release() {
        delete m_vertexArray;
        delete m_renderingAPI;
        delete m_vertexBuffer;
        delete m_indexBuffer;
    }

    void Renderer2D::update() {

    }

    Renderer2D::Renderer2D() {

    }
} // RAL