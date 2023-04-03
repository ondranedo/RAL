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
#ifndef RAL_PROJECT_KEYEVENTS_H
#define RAL_PROJECT_KEYEVENTS_H

#include <core/utility/Types.h>
#include <core/events/Event.h>

namespace RAL::Events {
    struct KeyPressed : public EventTL<KeyPressed> {
        types::KeyCodes key;

        explicit KeyPressed(types::KeyCodes _key);
    };

    struct KeyReleased : public EventTL<KeyReleased> {
        types::KeyCodes key;

        explicit KeyReleased(types::KeyCodes _key);
    };
}
#endif //!RAL_PROJECT_KEYEVENTS_H
