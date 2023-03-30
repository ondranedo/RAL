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

#ifndef RAL_BASECOMPONENT_H
#define RAL_BASECOMPONENT_H

namespace RAL {
    class BaseComponent {
    public:
        virtual ~BaseComponent();
        virtual void init() = 0;
        virtual void release() = 0;
        // TODO: Delta time
        virtual void update() = 0;
    };
} // RAL

#endif //!RAL_BASECOMPONENT_H
