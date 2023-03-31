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
        RAL::MemoryManager mgr(info.memory);
        RAL::global::setMemoryManager(&mgr);
        RAL::global::mainLogger.setConsoleInterpreter(info.consoleInterpreter);

        auto app = new RAL::Application();

        app->run();

        delete app;

        return 0;
    }
}


// TODO: move it into platform layer
#ifdef RAL_WINDOWS
#include <platfomLayer/windows/memory/Win32Memory.h>
#include <platfomLayer/windows/consoleInterpreter/Win32ConsoleInterpreter.h>

int main(int argc, char** argv) {
    RAL::Win32::Win32Memory memory;
    RAL::Win32::Win32ConsoleInterpreter interpreter;
    interpreter.init();
    interpreter.setTitle("RAL engine - debug console");
    interpreter.log("Starting logging...\n", RAL::ConsoleInterpreter::ColourForeground::GREEN,  RAL::ConsoleInterpreter::ColourBackground::BLACK);

    RAL::StartupInfo info = { &interpreter, &memory };
    RAL::main(info);

#ifdef RAL_DEBUG
    RAL::global::mainLogger.print();
    system("pause");
#endif //!RAL_DEBUG

    //interpreter.release();
    //memory.release();

    return 0;
}
#endif //!RAL_WINDOWS