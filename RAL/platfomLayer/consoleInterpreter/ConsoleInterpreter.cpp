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
#include "ConsoleInterpreter.h"

namespace RAL {
    ConsoleInterpreter::~ConsoleInterpreter() = default;

    uint8_t
    operator|(ConsoleInterpreter::ColourForeground foreground, ConsoleInterpreter::ColourBackground background) {
        return static_cast<uint8_t>(foreground) | static_cast<uint8_t>(background);
    }

    uint8_t
    operator|(ConsoleInterpreter::ColourBackground background, ConsoleInterpreter::ColourForeground foreground) {
        return foreground | background;
    }
} // RAL
