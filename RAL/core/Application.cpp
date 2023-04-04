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

namespace RAL
{
    const char *vertexShaderSource = "#version 460 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";

    const char *fragmentShaderSource = "#version 460 core\n"
                                       "out vec4 FragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                       "}\n\0";
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

        unsigned int vertexShader, fragmentShader, shaderProgram;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            RAL_LOG_FATAL("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
        }
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            RAL_LOG_FATAL("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED");
        }
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
            RAL_LOG_FATAL("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        RAL_LOG_DEBUG("Shader compiled");
        GLVertexArray va;
        GLVertexBuffer vb(vertices, sizeof(vertices),2);
        va.bindVA();
        vb.bindVB();
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        RAL_LOG_DEBUG("Va,Vb success");
        global::mainLogger.print();
        while (1)
        {
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glUseProgram(shaderProgram);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            window->swapBuffers();
            window->update();

        }
        window->destroy();
        window->release();
        factory.destroy(window);
    }
} // RAL