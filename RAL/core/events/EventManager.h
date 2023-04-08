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
#ifndef RAL_PROJECT_EVENTMANAGER_H
#define RAL_PROJECT_EVENTMANAGER_H

#include <core/baseClass/BaseComponent.h>
#include <core/events/Event.h>
#include <functional>
#include <queue>

#define RAL_BIND_CLASS_FUNCTION(name) [this](auto && p) { name(std::forward<decltype(p)>(p)); }
#define RAL_EVENT_MANAGER_QUEUE_SIZE 1000
namespace RAL {
    class EventManager final : public BaseComponent {
    public:
        using EventCallback = std::function<void(Event*)>;

        EventManager();
        ~EventManager() override;

        void init() override;
        void release() override;
        void update() override;

        EventCallback getEventCallback();
        void setUserEventCallback(const EventCallback& callback);
        void setEngineEventCallback(const EventCallback& callback);

    private:
        void enqueueEvent(Event* event);
        void handleEvents();
        void dispatchEvent(Event * event);

    private:
        std::queue<Event*> m_eventQueue;
        EventCallback m_userCallback;
        EventCallback m_engineCallback;
    };
} // RAL

#endif //!RAL_PROJECT_EVENTMANAGER_H
