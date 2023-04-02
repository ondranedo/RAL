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
#include <cstring>
#include <iostream>
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

            Header()
            {
                eventHandler = EventHandler::NONE;
                eventType = EventType::NONE;
                handled = 0;
            }
        };

    public:
        EventHandler getHandler();

        EventType getType();

    protected:
        Header m_header;
    };


    template<typename T>
    class EventTL : public Event
    {
    public:
        struct EventMouseMoved : public EventTL<EventMouseMoved>
        {
            float m_x, m_y;

            EventMouseMoved(float x, float y) : m_x(x), m_y(y) {}
        };

        struct EventMouseScrolled : public EventTL<EventMouseScrolled>
        {
            float m_x, m_y;

            EventMouseScrolled(float x, float y) : m_x(x), m_y(y) {}
        };

        struct EventMousePressed : public EventTL<EventMousePressed>
        {
            types::KeyCodes m_button;

            explicit EventMousePressed(types::KeyCodes button) : m_button(button) {}
        };

        struct EventMouseReleased : public EventTL<EventMouseReleased>
        {
            types::KeyCodes m_button;

            explicit EventMouseReleased(types::KeyCodes button) : m_button(button) {}
        };

        struct EventKeyPressed : public EventTL<EventKeyPressed>
        {
            types::KeyCodes m_key;

            explicit EventKeyPressed(types::KeyCodes key) : m_key(key) {}
        };

        struct EventKeyReleased : public EventTL<EventKeyReleased>
        {
            types::KeyCodes m_key;

            explicit EventKeyReleased(types::KeyCodes key) : m_key(key) {}
        };

        struct EventWindowResized : public EventTL<EventWindowResized>
        {
            unsigned int m_x,m_y;

            EventWindowResized(unsigned int x, unsigned int y) : m_x(x), m_y(y) {}
        };

        struct EventWindowClosed : public EventTL<EventWindowClosed>
        {
        };

        struct EventWindowFocus : public EventTL<EventWindowFocus>
        {
        };

        struct EventWindowLostFocus : public EventTL<EventWindowLostFocus>
        {
        };

        struct EventWindowMoved : public EventTL<EventWindowMoved>
        {
        };

    private:
        EventType EventTypeFromStr(const char *str);

        EventHandler EventClassFromStr(const char *str);

    public:
        EventTL()
        {
            m_header.eventHandler = EventClassFromStr(typeid(T).name());
            m_header.eventType = EventTypeFromStr(typeid(T).name());
        }

        static std::string getString();
    };

    template<typename T>
    std::string EventTL<T>::getString()
    {
        std::string str = typeid(T).name();
        str = str.erase(0, strlen("struct "));
        return str;
    }

    template<typename T>
    EventHandler EventTL<T>::EventClassFromStr(const char *str)
    {
        if (!strcmp(str, typeid(EventMouseMoved).name())) return EventHandler::USER;
        if (!strcmp(str, typeid(EventMouseScrolled).name())) return EventHandler::USER;
        if (!strcmp(str, typeid(EventMousePressed).name())) return EventHandler::USER;
        if (!strcmp(str, typeid(EventMouseReleased).name())) return EventHandler::USER;
        if (!strcmp(str, typeid(EventKeyPressed).name())) return EventHandler::USER;
        if (!strcmp(str, typeid(EventKeyReleased).name())) return EventHandler::USER;
        if (!strcmp(str, typeid(EventWindowResized).name())) return EventHandler::ENGINE;
        if (!strcmp(str, typeid(EventWindowClosed).name())) return EventHandler::ENGINE;
        if (!strcmp(str, typeid(EventWindowFocus).name())) return EventHandler::ENGINE;
        if (!strcmp(str, typeid(EventWindowLostFocus).name())) return EventHandler::ENGINE;
        if (!strcmp(str, typeid(EventWindowMoved).name())) return EventHandler::ENGINE;
    }

    template<typename T>
    EventType EventTL<T>::EventTypeFromStr(const char *str)
    {
        if (!strcmp(str, typeid(EventMouseMoved).name())) return EventType::MOUSE_MOVED;
        if (!strcmp(str, typeid(EventMouseScrolled).name())) return EventType::MOUSE_SCROLLED;
        if (!strcmp(str, typeid(EventMousePressed).name())) return EventType::MOUSE_PRESSED;
        if (!strcmp(str, typeid(EventMouseReleased).name())) return EventType::MOUSE_RELEASED;
        if (!strcmp(str, typeid(EventKeyPressed).name())) return EventType::KEY_PRESSED;
        if (!strcmp(str, typeid(EventKeyReleased).name())) return EventType::KEY_RELEASED;
        if (!strcmp(str, typeid(EventWindowResized).name())) return EventType::WINDOW_RESIZED;
        if (!strcmp(str, typeid(EventWindowClosed).name())) return EventType::WINDOW_CLOSED;
        if (!strcmp(str, typeid(EventWindowFocus).name())) return EventType::WINDOW_FOCUS;
        if (!strcmp(str, typeid(EventWindowLostFocus).name())) return EventType::WINDOW_LOST_FOCUS;
        if (!strcmp(str, typeid(EventWindowMoved).name())) return EventType::WINDOW_MOVED;
    }

} // RAL

#endif //!RAL_PROJECT_EVENT_H
