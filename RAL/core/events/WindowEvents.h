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

#include <core/events/Event.h>

namespace RAL::Events {
    struct WindowResized : public EventTL<WindowResized>
    {
        unsigned int x, y;

        WindowResized(unsigned int _x, unsigned int _y);
    };

    struct WindowClosed : public EventTL<WindowClosed>
    {
        WindowClosed();
    };

    struct WindowFocus : public EventTL<WindowFocus>
    {
        WindowFocus();
    };

    struct WindowLostFocus : public EventTL<WindowLostFocus>
    {
        WindowLostFocus();
    };

    struct WindowMoved : public EventTL<WindowMoved>
    {
        WindowMoved();
    };

} // RAL

#endif //!RAL_PROJECT_WINDOWEVENTS_H
