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
    EventHandler Event::getHandler()
    {
        try
        {
            return m_header.eventHandler;
        } catch (...)
        {
            return EventHandler::NONE;
        }
    }

    EventType Event::getType()
    {
        try
        {
            return m_header.eventType;
        } catch (...)
        {
            return EventType::NONE;
        }
    }

};
