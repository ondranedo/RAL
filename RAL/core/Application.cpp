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

#include <glad/glad.h>
#include "Application.h"
#include <core/utility/Logger.h>
#include <platfomLayer/window/Window.h>
#include <platfomLayer/window/WindowFactory.h>
#include <renderer/renderingAPI/platform/openGL/GLVertexArray.h>
#include <renderer/renderingAPI/platform/openGL/GLVertexBuffer.h>
#include <renderer/renderingAPI/platform/openGL/GLIndexBuffer.h>
#include <renderer/renderingAPI/platform/openGL/GLRenderingAPI.h>

namespace RAL
{
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


    Application::Application()
    {
        RAL_LOG_DEBUG("Application created");
    }

    Application::~Application()
    {
        RAL_LOG_DEBUG("Application destroyed");
    }

    void Application::run()
    {

        RAL_LOG_DEBUG("Application running");
        Window *window;
        WindowFactory factory;
        WindowSpec spec;
        strcpy(spec.m_title, "Ahoj");
        spec.m_height = 800;
        spec.m_width = 500;
        spec.m_created = false;
        window = factory.create(spec);
        window->init();
        window->create();
        window->makeContextCurrent();
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        {
            RAL_LOG_FATAL("Failed to initialize GLAD");
        }

        GLRenderingAPI rAPI;
        rAPI.init();
        GLVertexArray va;
        va.bind();
        GLVertexBuffer vb(vertices, sizeof(vertices), Buffer::DrawUsage::STATIC);
        GLIndexBuffer ib(indices, sizeof(indices), Buffer::DrawUsage::STATIC);
        va.setLayout();
        global::mainLogger.print();
        while (1)
        {
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            rAPI.useDefaultProgram();
            va.bind();
            //glDrawArrays(GL_TRIANGLES,0,6);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            window->swapBuffers();
            window->update();

        }
        window->destroy();
        window->release();
        factory.destroy(window);
    }
} // RAL