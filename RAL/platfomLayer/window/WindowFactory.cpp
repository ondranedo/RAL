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

#include <core/memoryManager/Overload.h>
#include "WindowFactory.h"

namespace RAL {
    Window *WindowFactory::create() {
#ifdef RAL_WINDOWS
        return RAL_BASEFACTORY_CREATE(Win32::Win32Window);
#endif
        RAL_ASSERTR(false, nullptr, "Unknown platform when creating window");
    }

    std::string WindowFactory::productName() const {
        return "Window";
    }
}; //!RAL