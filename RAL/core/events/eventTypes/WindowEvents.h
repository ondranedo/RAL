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
#ifndef RAL_PROJECT_WINDOWEVENTS_H
#define RAL_PROJECT_WINDOWEVENTS_H

#include "core/events/Event.h"

namespace RAL::Events {
    struct WindowResized : public Event
    {
        unsigned int x, y;

        WindowResized(unsigned int _x, unsigned int _y);
    };

    struct WindowClosed : public Event
    {
        WindowClosed();
    };

    struct WindowFocus : public Event
    {
        WindowFocus();
    };

    struct WindowLostFocus : public Event
    {
        WindowLostFocus();
    };

    struct WindowMoved : public Event
    {
        WindowMoved();
    };

} // RAL

#endif //!RAL_PROJECT_WINDOWEVENTS_H
