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

#ifndef RAL_PROJECT_CONSOLEINTERPRETER_H
#define RAL_PROJECT_CONSOLEINTERPRETER_H

#include <core/baseClass/BaseComponent.h>
#include <string>

namespace RAL {
    class ConsoleInterpreter : public virtual BaseComponent {
    public:
        enum class ColourBackground : uint8_t
        {
            BLACK = 0, NAVYBLUE = 16, GREEN = 32, TEAL = 48, MAROON = 64, PURPLE = 80, OLIVE = 96, SILVER = 112,
            GRAY = 128, BLUE = 144, LIME = 160, CYAN = 176, RED = 192, MAGENTA = 208, YELLOW = 224, WHITE = 240
        };
        enum class ColourForeground : uint8_t
        {
            BLACK = 0, BLUE = 1, GREEN = 2, CYAN = 3, RED = 4, MAGENTA = 5, BROWN = 6, LIGHTGRAY = 7, GRAY = 8,
            LIGHTBLUE = 9, LIGHTGREEN = 10, LIGHTCYAN = 11, LIGHTRED = 12, LIGHTMAGENTA = 13, YELLOW = 14, WHITE = 15
        };

        virtual ~ConsoleInterpreter();

        virtual void log(const char* msg, ColourForeground text, ColourBackground background) = 0;
        virtual void log(const char* msg, ColourBackground background) = 0;
        virtual void log(const char* msg, ColourForeground text) = 0;
        virtual void log(const char* msg) = 0;

        virtual void setTitle(const char* title) = 0;

        virtual void clear() = 0;
    private:
    };

    uint8_t operator|(ConsoleInterpreter::ColourForeground foreground, ConsoleInterpreter::ColourBackground background);
    uint8_t operator|(ConsoleInterpreter::ColourBackground background, ConsoleInterpreter::ColourForeground foreground);
} // RAL

#endif //!RAL_PROJECT_CONSOLEINTERPRETER_H
