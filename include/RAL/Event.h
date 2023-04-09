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

// Last version of this file: 2023-04-08_17:26

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
#include "MemoryOverload.h"
#include <string>
#include <functional>

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
        [[nodiscard]] std::string getEventTypeString() const;

    protected:
        Header m_header;
    };

    class EventDispatcher {
    public:
        explicit EventDispatcher(Event* event);
        template<class T>
        void dispatch(const std::function<bool(T*)>& fn);

    private:
        Event* m_event;
    };

    template<class T>
    void EventDispatcher::dispatch(const std::function<bool(T*)>& fn) {
        //RAL_ASSERT(m_event != nullptr, "Event is null, cannot dispatch null pointer");
        if(m_event->getType() == T::getEventType() && !m_event->isHandled())
        {
            m_event->setHandled(fn(dynamic_cast<T*>(m_event)));
        }
    }

    namespace Events {
        struct KeyPressed : public Event {
            Types::Codes key;
            bool repeat: 1;

            explicit KeyPressed(RAL::Types::Codes _key, bool repeat) : key(_key), repeat(repeat) {
                m_header.eventHandler = EventHandler::USER;
                m_header.eventType = EventType::KEY_PRESSED;
            }

            static EventType getEventType() { return EventType::KEY_PRESSED; }
        };

        struct KeyReleased : public Event {
            Types::Codes key;

            explicit KeyReleased(Types::Codes _key) : key(_key) {
                m_header.eventHandler = EventHandler::USER;
                m_header.eventType = EventType::KEY_RELEASED;
            }
            static EventType getEventType() { return EventType::KEY_RELEASED; }
        };

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
            Types::Codes button;

            explicit MousePressed(Types::Codes _button) : button(_button){
                m_header.eventHandler = EventHandler::USER;
                m_header.eventType = EventType::MOUSE_PRESSED;
            }
            static EventType getEventType() { return EventType::MOUSE_PRESSED; }
        };

        struct MouseReleased : public Event
        {
            Types::Codes button;

            explicit MouseReleased(Types::Codes _button) : button(_button) {
                m_header.eventHandler = EventHandler::USER;
                m_header.eventType = EventType::MOUSE_RELEASED;
            }
            static EventType getEventType() { return EventType::MOUSE_RELEASED; }
        };
    }
};

#endif //!RAL_PROJECT_EVENT_H
