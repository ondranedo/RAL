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
#ifndef RAL_PROJECT_WINDOWEVENTS_H
#define RAL_PROJECT_WINDOWEVENTS_H

#include "core/events/Event.h"

namespace RAL::Events {
    struct WindowResized : public Event
    {
        unsigned int x, y;

        WindowResized(unsigned int _x, unsigned int _y): x(_x), y(_y) {
            m_header.eventHandler = EventHandler::ENGINE;
            m_header.eventType = EventType::WINDOW_RESIZED;
        }
        static EventType getEventType() { return EventType::WINDOW_RESIZED; }
    };

    struct WindowClosed : public Event
    {
        WindowClosed() {
            m_header.eventHandler = EventHandler::ENGINE;
            m_header.eventType = EventType::WINDOW_CLOSED;
        }
        static EventType getEventType() { return EventType::WINDOW_CLOSED; }
    };

    struct WindowFocus : public Event
    {
        WindowFocus() {
            m_header.eventHandler = EventHandler::ENGINE;
            m_header.eventType = EventType::WINDOW_FOCUS;
        }
        static EventType getEventType() { return EventType::WINDOW_FOCUS; }
    };

    struct WindowLostFocus : public Event
    {
        WindowLostFocus(){
            m_header.eventHandler = EventHandler::ENGINE;
            m_header.eventType = EventType::WINDOW_LOST_FOCUS;
        }
        static EventType getEventType() { return EventType::WINDOW_LOST_FOCUS; }
    };

    struct WindowMoved : public Event
    {
        double x, y;
        WindowMoved(double _x, double _y): x(_x), y(_y) {
            m_header.eventHandler = EventHandler::ENGINE;
            m_header.eventType = EventType::WINDOW_MOVED;
        }
        static EventType getEventType() { return EventType::WINDOW_MOVED; }
    };

} // RAL
#endif //!RAL_PROJECT_WINDOWEVENTS_H
