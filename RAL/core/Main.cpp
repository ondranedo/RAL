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
#include <thread>
namespace RAL {
    int main(const StartupInfo& info) {
        MemoryManager mgr(info.memory);
        global::setMemoryManager(&mgr);
        std::thread loggerThread(&global::mainLogger.startLogLoop, &global::mainLogger);

        auto app = new RAL::Application({&mgr, info.consoleInterpreter});
        app->inti();
        app->run();
        app->release();
        delete app;

        global::mainLogger.endLogLoop();
        loggerThread.join();

        return 0;
    }
}

#ifdef RAL_WINDOWS_USE_WINMAIN

#include "Win32Main.h"
#include <windows.h>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	return RAL::Win32::main();
}

#else

#ifdef RAL_WINDOWS
#include <platfomLayer/windows/Win32Main.h>
#endif

int main(int, char**)
{
#ifdef RAL_WINDOWS
    return RAL::Win32::main();
#endif
}

#endif //!RAL_WINDOWS_USE_WINMAIN