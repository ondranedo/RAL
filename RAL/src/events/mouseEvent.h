//
// Created by Vojta on 21.03.2023.
//

#pragma once

#include "event.h"

namespace RAL
{
    class MousePressed : public Event
    {
    public:
        KeyCodes m_button;

        EVENT_TYPE(EventType::MousePressed)

        explicit MousePressed(KeyCodes buttonCode)
                : m_button(buttonCode)
        {

            snprintf(buffer, RAL_EVENT_BUFFER_SIZE, "[Event][MousePressed] Button: %hu \n", m_button);
        }

        EVENT_STRING(buffer);
    };

    class MouseReleased : public Event
    {
    public:
        KeyCodes m_button;

        EVENT_TYPE(EventType::MouseReleased)

        explicit MouseReleased(KeyCodes buttonCode)
                : m_button(buttonCode)
        {

            snprintf(buffer, RAL_EVENT_BUFFER_SIZE, "[Event][MouseReleased] Button: %hu \n", m_button);
        }

        EVENT_STRING(buffer);
    };

    class MouseMoved : public Event
    {
    public:
        f32_t m_mouseX, m_mouseY;

        EVENT_TYPE(EventType::MouseMoved)

        MouseMoved(f32_t x, f32_t y)
                : m_mouseX(x), m_mouseY(y)
        {

            snprintf(buffer, RAL_EVENT_BUFFER_SIZE, "[Event][MouseMoved] X: %f Y: %f \n", m_mouseX, m_mouseY);
        }

        EVENT_STRING(buffer);
    };

    class MouseScrolled : public Event
    {
    public:
        f32_t m_scrollX, m_scrollY;

        EVENT_TYPE(EventType::MouseScrolled)

        MouseScrolled(f32_t x, f32_t y)
                : m_scrollX(x), m_scrollY(y)
        {

            snprintf(buffer, RAL_EVENT_BUFFER_SIZE, "[Event][MouseScrolled] X: %f Y: %f \n", m_scrollX, m_scrollY);
        }

        EVENT_STRING(buffer);
    };
};
