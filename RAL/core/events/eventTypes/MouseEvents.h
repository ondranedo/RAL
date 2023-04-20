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
#ifndef RAL_PROJECT_MOUSEEVENTS_H
#define RAL_PROJECT_MOUSEEVENTS_H

#include "core/events/Event.h"

namespace RAL::Events {
    struct MouseMoved : public Event
    {
        double x, y;

        MouseMoved(double _x, double _y) : x(_x), y(_y) {
            m_header.eventHandler = EventHandler::USER;
            m_header.eventType = EventType::MOUSE_MOVED;
        }
        static EventType getEventType() { return EventType::MOUSE_MOVED; }
    };

    struct MouseScrolled : public Event
    {
        double x, y;

        MouseScrolled(double _x, double _y) : x(_x), y(_y) {
            m_header.eventHandler = EventHandler::USER;
            m_header.eventType = EventType::MOUSE_SCROLLED;
        }
        static EventType getEventType() { return EventType::MOUSE_SCROLLED; }
    };

    struct MousePressed : public Event
    {
        Types::IOCode button;

        explicit MousePressed(Types::IOCode _button) : button(_button){
            m_header.eventHandler = EventHandler::USER;
            m_header.eventType = EventType::MOUSE_PRESSED;
        }
        static EventType getEventType() { return EventType::MOUSE_PRESSED; }
    };

    struct MouseReleased : public Event
    {
        Types::IOCode button;

        explicit MouseReleased(Types::IOCode _button) : button(_button) {
            m_header.eventHandler = EventHandler::USER;
            m_header.eventType = EventType::MOUSE_RELEASED;
        }
        static EventType getEventType() { return EventType::MOUSE_RELEASED; }
    };

} // RAL
#endif //!RAL_PROJECT_MOUSEEVENTS_H
