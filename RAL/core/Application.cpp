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

#include <vendor/glad/include/glad/glad.h>
#include "Application.h"

#include <core/FCM/FCM.h>
#include <core/layers/LayerManagerFactory.h>
#include <platfomLayer/window/WindowFactory.h>
#include <core/events/EventManagerFactory.h>
#include <core/events/eventTypes/WindowEvents.h>
#include <core/events/EventDispatcher.h>

namespace RAL {
    Application::Application(const ConstructInfo& info) : m_fcm({}), m_running(true), m_game(nullptr) {
        RAL_LOG_DEBUG("Engine creation");

        m_fcm.addComponent(info.memory, "memory", true, false, false);
        m_fcm.addComponent(info.consoleInterpreter, "console", true, false, false);
        m_fcm.addFactory<EventManagerFactory>();
        m_fcm.addFactory<LayerManagerFactory>();
        m_fcm.addFactory<WindowFactory>();

        m_fcm.createComponents();

        m_game = createGame();
        m_game->setLayerManager(m_fcm.get<LayerManager>("LayerManager"));

        RAL_LOG_INFO("Engine is at possession of %zu components", m_fcm.getComponentCount());
    }
    
    Application::Application(const ConstructInfo& info)
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
    
    Application::~Application()
    {
        RAL_LOG_DEBUG("Application destroyed");
    }

    void Application::run()
    {

        while(m_running)
        {
            m_game->onUpdate();
            m_fcm.updateComponents();

            global::mainLogger.print();
        }

    }
} // RAL