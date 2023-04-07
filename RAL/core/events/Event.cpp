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

    Event::Header::Header() {
        eventHandler = EventHandler::NONE;
        eventType = EventType::NONE;
        handled = false;
    }
};
