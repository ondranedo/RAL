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
        float x, y;

        MouseMoved(float _x, float _y);
        static EventType getEventType() { return EventType::MOUSE_MOVED; }
    };

    struct MouseScrolled : public Event
    {
        float x, y;

        MouseScrolled(float _x, float _y);
        static EventType getEventType() { return EventType::MOUSE_SCROLLED; }
    };

    struct MousePressed : public Event
    {
        types::KeyCodes button;

        explicit MousePressed(types::KeyCodes _button);
        static EventType getEventType() { return EventType::MOUSE_PRESSED; }
    };

    struct MouseReleased : public Event
    {
        types::KeyCodes button;

        explicit MouseReleased(types::KeyCodes _button);
        static EventType getEventType() { return EventType::MOUSE_RELEASED; }
    };

} // RAL

#endif //!RAL_PROJECT_MOUSEEVENTS_H
