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


#ifndef RAL_PROJECT_MAIN_H
#define RAL_PROJECT_MAIN_H

#include <platfomLayer/consoleInterpreter/ConsoleInterpreter.h>
#include <platfomLayer/memory/Memory.h>

namespace RAL{
    struct StartupInfo {
        ConsoleInterpreter* consoleInterpreter;
        Memory* memory;
    };

    extern int main(const StartupInfo& info);
}

#endif //!RAL_PROJECT_MAIN_H