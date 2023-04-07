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
#include "KeyEvents.h"

namespace RAL::Events {
    KeyPressed::KeyPressed(RAL::Types::KeyCodes _key) : key(_key){
        m_header.eventHandler = EventHandler::USER;
        m_header.eventType = EventType::KEY_PRESSED;
    }

    KeyReleased::KeyReleased(Types::KeyCodes _key) : key(_key){
        m_header.eventHandler = EventHandler::USER;
        m_header.eventType = EventType::KEY_RELEASED;
    }
}
