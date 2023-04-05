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

// Last version of this file: 2023-04-05_20:17

/*
 * Event are used to communicate between different parts of the engine.
 * Some events are handled by the engine, some are handled by the user.
 * User event are sent to layers, one by one. If the event is not handled
 * by the layer, it is passed to the next layer.
 *
 */

#ifndef RAL_PROJECT_EVENT_H
#define RAL_PROJECT_EVENT_H

#include "Keycodes.h"

namespace RAL {
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

    class Event {
    protected:
        struct Header {
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

    protected:
        Header m_header;
    };

    namespace Events {
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
            Types::KeyCodes button;

            explicit MousePressed(Types::KeyCodes _button);
            static EventType getEventType() { return EventType::MOUSE_PRESSED; }
        };

        struct MouseReleased : public Event
        {
            Types::KeyCodes button;

            explicit MouseReleased(Types::KeyCodes _button);
            static EventType getEventType() { return EventType::MOUSE_RELEASED; }
        };
    }
};

#endif //!RAL_PROJECT_EVENT_H
