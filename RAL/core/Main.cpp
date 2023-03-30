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

#include "Main.h"
#include <core/Core.h>
#include <core/memoryManager/MemoryManager.h>
#include <core/Application.h>

namespace RAL {
    int main(const StartupInfo& info) {

        RAL_PLATFORM_MEMORY(memory);
        RAL::MemoryManager mgr(&memory);
        RAL::global::setMemoryManager(&mgr);

        auto app = new RAL::Application();

        app->run();

        delete app;

        return 0;
    }
}

int main()
{
    return RAL::main({});
}