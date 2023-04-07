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
#include "WindowEvents.h"

namespace RAL::Events {
    WindowResized::WindowResized(unsigned int _x, unsigned int _y): x(_x), y(_y) {
        m_header.eventHandler = EventHandler::ENGINE;
        m_header.eventType = EventType::WINDOW_RESIZED;
    }

    WindowClosed::WindowClosed() {
        m_header.eventHandler = EventHandler::ENGINE;
        m_header.eventType = EventType::WINDOW_CLOSED;
    }

    WindowFocus::WindowFocus() {
        m_header.eventHandler = EventHandler::ENGINE;
        m_header.eventType = EventType::WINDOW_FOCUS;
    }

    WindowLostFocus::WindowLostFocus() {
        m_header.eventHandler = EventHandler::ENGINE;
        m_header.eventType = EventType::WINDOW_LOST_FOCUS;
    }

    WindowMoved::WindowMoved() {
        m_header.eventHandler = EventHandler::ENGINE;
        m_header.eventType = EventType::WINDOW_MOVED;
    }
} // RAL
