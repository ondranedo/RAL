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
#include <renderer/renderingAPI/platform/openGL/OpenGL.h>

namespace RAL
{
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
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
        Window *window, *window1;
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
        GLVertexArray va;
        GLVertexBuffer vb(vertices, sizeof(vertices),2);
        rAPI.init();
        va.bindVA();
        vb.bindVB();
        va.setLayout();
        global::mainLogger.print();
        while (1)
        {
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            rAPI.useDefaultProgram();
            glDrawArrays(GL_TRIANGLES, 0, 3);
            window->swapBuffers();
            window->update();

        }
        window->destroy();
        window->release();
        factory.destroy(window);
    }
} // RAL