//
// Created by Vojta on 19.03.2023.
//

#pragma once

#include "../containers/string.h"

namespace RAL
{
    enum class EventType
    {
        None = 0,
        WindowResized, WindowClosed, WindowFocus, WindowLostFocus, WindowMoved,
        KeyPressed, KeyReleased, KeyTyped,
        MousePressed, MouseReleased, MouseMoved, MouseScrolled,
        AppUpdate, AppRender
    };

    enum class EventCategory
    {
        None = 0,
        EventCategoryApp = 1 << 0,
        EventCategoryInput = 1 << 1,
        EventCategoryKeybaord = 1 << 2,
        EventCategoryMouse = 1 << 3,
        EventCattegoryMouseButton = 1 << 4
    };

    class Event
    {
    public:
        virtual ~Event() {}
        virtual EventType getEventType() = 0;

        virtual int getCategoryFlags() = 0;

#ifdef RAL_DEBUG

        virtual RAL::String getName() = 0;

        virtual RAL::String toString() { return getName(); }

#endif

        bool inCategory(EventCategory category)
        {
            return static_cast<int>(getCategoryFlags()) & static_cast<int>(category);
        }

    protected:
        bool m_handled = false;
    };

}
