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


#include "event.h"

namespace RAL
{
    EventHandler Event::getHandler() const
    {
        return m_header.eventHandler;
    }

    EventType Event::getType() const
    {
        return m_header.eventType;
    }

    Event::Event() {
        m_header.eventHandler = EventHandler::NONE;
        m_header.eventType = EventType::NONE;
        m_header.handled = false;
    }

    bool Event::isHandled() const {
        return m_header.handled;
    }

    void Event::setHandled(bool _handled) {
        m_header.handled = _handled;
    }

    [[nodiscard]] std::string Event::getEventTypeString() const {
        switch (m_header.eventType) {
            case EventType::NONE: return "NONE";
            case EventType::WINDOW_RESIZED: return "WINDOW_RESIZED";
            case EventType::WINDOW_CLOSED: return "WINDOW_CLOSED";
            case EventType::WINDOW_FOCUS: return "WINDOW_FOCUS";
            case EventType::WINDOW_LOST_FOCUS: return "WINDOW_LOST_FOCUS";
            case EventType::WINDOW_MOVED: return "WINDOW_MOVED";
            case EventType::KEY_PRESSED: return "KEY_PRESSED";
            case EventType::KEY_RELEASED: return "KEY_RELEASED";
            case EventType::MOUSE_PRESSED: return "MOUSE_PRESSED";
            case EventType::MOUSE_RELEASED: return "MOUSE_RELEASED";
            case EventType::MOUSE_MOVED: return "MOUSE_MOVED";
            case EventType::MOUSE_SCROLLED: return "MOUSE_SCROLLED";
            default: return "UNKNOWN";
        }
    }

    Event::Header::Header() {
        eventHandler = EventHandler::NONE;
        eventType = EventType::NONE;
        handled = false;
    }
};
