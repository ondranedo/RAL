//
// Created by Vojta on 20.03.2023.
//

#pragma once

#include "event.h"

//TODO Implement Logger

namespace RAL
{
    class KeyPressed : public Event
    {
    public:
        KeyCodes m_key;
        i32_t m_repeatCount;

        EVENT_TYPE(EventType::KeyPressed)

        KeyPressed(KeyCodes keyCode, i32_t repeatCount)
                : m_key(keyCode), m_repeatCount(repeatCount)
        {

            snprintf(buffer, RAL_EVENT_BUFFER_SIZE, "[Event][KeyPressed] Key: %hu Repeat count: %d\n", m_key,
                     m_repeatCount);
        }

        EVENT_STRING(buffer);
    };

    class KeyReleased : public Event
    {
    public:
        KeyCodes m_key;

        EVENT_TYPE(EventType::KeyReleased)

        explicit KeyReleased(KeyCodes keyCode)
                : m_key(keyCode)
        {

            snprintf(buffer, RAL_EVENT_BUFFER_SIZE, "[Event][KeyReleased] Key: %hu \n", m_key);
        }

        EVENT_STRING(buffer);
    };

    class KeyTyped : public Event
    {
    public:
        KeyCodes m_key;

        EVENT_TYPE(EventType::KeyTyped)

        explicit KeyTyped(KeyCodes keyCode)
                : m_key(keyCode)
        {

            snprintf(buffer, RAL_EVENT_BUFFER_SIZE, "[Event][KeyTyped] Key: %hu \n", m_key);
        }

        EVENT_STRING(buffer);
    };
};
