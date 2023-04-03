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
#include "EventManager.h"

#include <core/memoryManager/Overload.h>
#include <core/utility/Logger.h>
#include <core/utility/Asserts.h>

namespace RAL {
    void EventManager::init() {

    }

    void EventManager::release() {

    }

    void EventManager::update() {
        handleEvents();
    }

    EventManager::EventCallback EventManager::getEventCallback() {
        return [this](auto && p) { enqueueEvent(std::forward<decltype(p)>(p)); };
    }

    void EventManager::enqueueEvent(Event* event) {
        m_eventQueue.push(event);
        if(m_eventQueue.size() > 1000) {
            RAL_LOG_WARNING("Event queue is full, mandatory queue dump, consider increasing queue size");
            handleEvents();
        }
    }

    void EventManager::handleEvents() {
        while(!m_eventQueue.empty()) {
            auto event = m_eventQueue.front();
            m_eventQueue.pop();
            dispatchEvent(event);
            delete event;
        }
    }

    void EventManager::dispatchEvent(Event *event) {
        if(event->getHandler() == EventHandler::ENGINE) {
            RAL_ASSERTRV(m_engineCallback != nullptr, "Engine event callback not set");
            m_engineCallback(event);
        }
        if(event->getHandler() == EventHandler::USER) {
            RAL_ASSERTRV(m_engineCallback != nullptr, "User event callback not set");
            m_userCallback(event);
        }
    }

    void EventManager::setUserEventCallback(const EventManager::EventCallback &callback) {
        RAL_ASSERT(m_userCallback == nullptr, "User event callback already set")
        m_userCallback = callback;
    }

    void EventManager::setEngineEventCallback(const EventManager::EventCallback &callback) {
        RAL_ASSERT(m_engineCallback == nullptr, "Engine event callback already set")
        m_engineCallback = callback;
    }

    EventManager::EventManager() : m_engineCallback(nullptr), m_userCallback(nullptr), m_eventQueue(std::queue<Event*>()){}

    EventManager::~EventManager() {
        if(!m_eventQueue.empty()) {
            RAL_LOG_WARNING("Engine event queue not empty, dumping queue");
            handleEvents();
        }
    }
} // RAL
