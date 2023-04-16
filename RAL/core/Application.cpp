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


#include "Application.h"

#include <core/FCM/FCM.h>
#include <core/layers/LayerManagerFactory.h>
#include <platfomLayer/window/WindowFactory.h>
#include <core/events/EventManagerFactory.h>
#include <core/events/eventTypes/WindowEvents.h>
#include <core/events/EventDispatcher.h>
#include <platfomLayer/window/Window.h>

#include <renderer/renderingAPI/platform/openGL/GLRenderingAPI.h>
#include <renderer/renderingAPI/buffers/VertexBufferLayout.h>
#include <renderer/renderingAPI/buffers/IndexBuffer.h>
#include <renderer/renderingAPI/buffers/VertexBuffer.h>

struct Vertex {
   float position[3];
   uint8_t colour[3];
};

namespace RAL {

    Vertex vertices[4] = {
            {{-0.5f, -0.5f, 0.0f},{0, 255, 0}},  // bottom left
            {{-0.5f, 0.5f, 0.0f}, {0, 0, 255}},  // top left
            {{0.5f, 0.5f, 0.0f},  {0, 255, 0}},  // top right
            {{0.5f, -0.5f, 0.0f}, {255, 0, 0}}   // bottom right
    };
    unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,  // first Triangle
            1, 2, 3   // second Triangle
    };

    Application::Application(const ConstructInfo& info) : m_fcm({}), m_running(true), m_game(nullptr) {
        RAL_LOG_DEBUG("Engine creation");

        m_fcm.addComponent(info.memory, "memory", true, false, false);
        m_fcm.addComponent(info.consoleInterpreter, "console", true, false, false);
        m_fcm.addFactory<EventManagerFactory>();
        m_fcm.addFactory<LayerManagerFactory>();
        m_fcm.addFactory<WindowFactory>();
        WindowSpec spec;
        spec.width = 800;
        spec.ratio = WindowRatio::RATIO_16_9;
        strcpy_s(spec.title, "RAL Engine");
        m_fcm.customComponentCreation<WindowFactory>("Window",spec);
        m_fcm.createComponents();

        m_game = createGame();
        m_game->setLayerManager(m_fcm.get<LayerManager>("LayerManager"));

        RAL_LOG_INFO("Engine is at possession of %zu components", m_fcm.getComponentCount());
    }

    Application::~Application()
    {
        RAL_LOG_DEBUG("Engine destruction");
        m_fcm.clearFactories();
    }

    void Application::inti() {
        RAL_LOG_DEBUG("Engine initialization");
        m_fcm.initComponents();

        auto layerCallback = m_fcm.get<LayerManager>("LayerManager")->getEventCallback();

        m_fcm.get<EventManager>("EventManager")->setUserEventCallback(layerCallback);
        m_fcm.get<EventManager>("EventManager")->setEngineEventCallback(RAL_BIND_CLASS_FUNCTION(onEvent));


        m_fcm.get<Window>("Window")->create();
        m_fcm.get<Window>("Window")->setEventCallback(m_fcm.get<EventManager>("EventManager")->getEventCallback());
        m_fcm.get<Window>("Window")->setTitle("RAL Engine");

        m_game->onStartup();
    }

    void Application::release() {
        RAL_LOG_DEBUG("Engine release");
        m_fcm.get<LayerManager>("LayerManager")->removeAllLayers();
        m_game->onShutdown();
        m_fcm.releaseComponents();
        delete m_game;
    }

    void Application::onEvent(Event *event) {
        EventDispatcher dispatcher(event);
        dispatcher.dispatch<Events::WindowClosed>([this](Events::WindowClosed* event)->bool{
            RAL_LOG_WARNING("Engine received WindowClosed event");
            m_running = false;
            return true;
        });
    }

    void Application::run() {
        RAL_LOG_INFO("Engine starting main loop");

        std::string vertexShaderSource = "#version 460 core\n"
                                         "layout (location = 0) in vec3 positionXYZ;\n"
                                         "layout (location = 1) in vec3 colourRGB;\n"
                                         "out vec3 ourColor;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = vec4(positionXYZ, 1.0);\n"
                                         "   ourColor = colourRGB;\n"
                                         "}";


        std::string fragmentShaderSource = "#version 460 core\n"
                                           "out vec4 FragColor;\n"
                                           "in vec3 ourColor;\n"
                                           "void main()\n"
                                           "{\n"
                                           "   FragColor = vec4(ourColor, 1.0f);\n"
                                           "}\n";

        GLRenderingAPI api;
        api.setWindow(m_fcm.get<Window>("Window"));
        api.init();
        api.clearColour(0x1e1e1e);
        IndexBuffer ib(indices, 6);
        VertexBuffer vb(vertices, sizeof(vertices), VertexBufferLayout({VertexBufferLayout::Entry::POS_XYZ, VertexBufferLayout::Entry::COLOUR_RGB}) );
        api.bind(vb);
        api.bind(ib);
        api.compileProgram(0, vertexShaderSource, fragmentShaderSource);
        api.setProgram(0);

        while(m_running)
        {
            m_game->onUpdate();
            m_fcm.updateComponents();
            ///
            api.clear();
            api.draw();
            m_fcm.get<Window>("Window")->swapBuffers();
            ///
            global::mainLogger.print();
        }

        api.release();
    }
} // RAL