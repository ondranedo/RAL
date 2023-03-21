//
// Created by Vojta on 19.03.2023.
//

#pragma once

#include <GLFW/glfw3.h>
#include "../containers/string.h"
#include "../core/types.h"
#include <stdio.h>

namespace RAL
{

#define EVENT_TYPE(eventType) EventType getEventType() override { return eventType; }
#define EVENT_STRING(bufferString) RAL::String toString() override { \
message.recreate(bufferString);                                      \
return message; }
#define RAL_EVENT_BUFFER_SIZE 128

    enum class EventType
    {
        None = 0,
        WindowResized, WindowClosed, WindowFocus, WindowLostFocus, WindowMoved,
        KeyPressed, KeyReleased, KeyTyped,
        MousePressed, MouseReleased, MouseMoved, MouseScrolled
    };

    class Event
    {
    public:
        char buffer[RAL_EVENT_BUFFER_SIZE];
        String message;

        virtual ~Event() = default;

        virtual EventType getEventType() = 0;

#ifdef RAL_DEBUG

        virtual RAL::String toString() = 0;

#endif

    protected:
        bool m_handled = false;
    };
}
