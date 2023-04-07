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
#ifndef RAL_PROJECT_EVENTDISPATCHER_H
#define RAL_PROJECT_EVENTDISPATCHER_H

#include <functional>
#include <core/events/Event.h>
#include <core/utility/Asserts.h>

namespace RAL {
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
        RAL_ASSERT(m_event != nullptr, "Event is null, cannot dispatch null pointer");
        if(m_event->getType() == T::getEventType() && !m_event->isHandled())
        {
            m_event->setHandled(fn(dynamic_cast<T*>(m_event)));
        }
    }
} // RAL

#endif //!RAL_PROJECT_EVENTDISPATCHER_H
