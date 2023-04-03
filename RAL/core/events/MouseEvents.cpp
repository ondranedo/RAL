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
#include "MouseEvents.h"

namespace RAL::Events {
    MouseReleased::MouseReleased(types::KeyCodes _button) : button(_button) {
        m_header.eventHandler = EventHandler::USER;
        m_header.eventType = EventType::MOUSE_RELEASED;
    }

    MouseMoved::MouseMoved(float _x, float _y) : x(_x), y(_y) {
        m_header.eventHandler = EventHandler::USER;
        m_header.eventType = EventType::MOUSE_MOVED;
    }

    MouseScrolled::MouseScrolled(float _x, float _y) : x(_x), y(_y) {
        m_header.eventHandler = EventHandler::USER;
        m_header.eventType = EventType::MOUSE_SCROLLED;
    }

    MousePressed::MousePressed(types::KeyCodes _button) : button(_button){
        m_header.eventHandler = EventHandler::USER;
        m_header.eventType = EventType::MOUSE_PRESSED;
    }
} // RAL
