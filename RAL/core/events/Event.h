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

#ifndef RAL_PROJECT_EVENT_H
#define RAL_PROJECT_EVENT_H

#include <typeinfo>
#include <core/utility/Types.h>

namespace RAL
{

    enum class EventHandler : unsigned char
    {
        NONE, USER, ENGINE
    };
    enum class EventType : unsigned char
    {
        NONE, WINDOW_RESIZED, WINDOW_CLOSED, WINDOW_FOCUS, WINDOW_LOST_FOCUS, WINDOW_MOVED,
        KEY_PRESSED, KEY_RELEASED,
        MOUSE_PRESSED, MOUSE_RELEASED, MOUSE_MOVED, MOUSE_SCROLLED
    };

    class Event
    {
    protected:
        struct Header
        {
            bool handled: 1;
            EventHandler eventHandler: 3;
            EventType eventType: 8;

            Header();
        };

    public:
        Event();
        virtual ~Event() = default;
        [[nodiscard]] EventHandler getHandler() const;
        [[nodiscard]] EventType getType() const;
        [[nodiscard]] bool isHandled() const;
        void setHandled(bool _handled);
        [[nodiscard]] std::string getEventTypeString() const;

    protected:
        Header m_header;
    };
} // RAL

#endif //!RAL_PROJECT_EVENT_H
