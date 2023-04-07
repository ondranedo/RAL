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

#include <core/FCM/FCM.h>
#include <core/layers/LayerManagerFactory.h>
#include <platfomLayer/window/WindowFactory.h>
#include <core/events/EventManagerFactory.h>

namespace RAL {
    Application::Application(const ConstructInfo& info) : m_fcm({}) {
        RAL_LOG_DEBUG("Engine creation");

        m_fcm.addComponent(info.memory, "memory", true, false, false);
        m_fcm.addComponent(info.consoleInterpreter, "console", true, false, false);
        m_fcm.addFactory<LayerManagerFactory>();
        m_fcm.addFactory<EventManagerFactory>();

        m_fcm.createComponents();
        RAL_LOG_INFO("Engine is at possession of %llu components", m_fcm.getComponentCount());
    }

    Application::~Application()
    {
        RAL_LOG_DEBUG("Engine destruction");
        m_fcm.clearFactories();
    }

    void Application::inti() {
        RAL_LOG_DEBUG("Engine initialization");
        m_fcm.initComponents();
    }

    void Application::release() {
        RAL_LOG_DEBUG("Engine release");

        m_fcm.releaseComponents();
    }

    void Application::onEvent(Event *event) {
        RAL_LOG_DEBUG("Engine received event");
    }

    void Application::run() {
        RAL_LOG_INFO("Engine starting main loop");

        m_fcm.updateComponents();
    }
} // RAL