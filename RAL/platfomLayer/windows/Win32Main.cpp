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

#ifdef RAL_WINDOWS

#include <core/Core.h>
#include <core/Main.h>
#include <core/utility/Logger.h>
#include <platfomLayer/windows/memory/Win32Memory.h>
#include <platfomLayer/windows/consoleInterpreter/Win32ConsoleInterpreter.h>

namespace RAL {
	namespace Win32 {
		int main()
		{
			RAL_LOG_DEBUG("Starting on Windows");

			RAL::Win32::Win32Memory memory;
			RAL::Win32::Win32ConsoleInterpreter interpreter;
			interpreter.init();
			interpreter.setTitle("RAL engine - debug console");
			interpreter.log(" \xDA");
			interpreter.log("Starting logging...\n", RAL::ConsoleInterpreter::ColourForeground::GRAY, RAL::ConsoleInterpreter::ColourBackground::BLACK);
			interpreter.log("\xB3\n");

			RAL::StartupInfo info = { &interpreter, &memory };
			RAL::main(info);

			RAL::global::mainLogger.print();
			interpreter.log("\xB3\n");
			interpreter.log("\xAF");
#ifdef RAL_DEBUG
			system("pause");
#endif //!RAL_DEBUG

			RAL::global::mainLogger.detachConsoleInterpreter();

			return 0;
		}
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

int main(int, char**)
{
	return RAL::Win32::main();
}

#endif //!RAL_WINDOWS_USE_WINMAIN

#endif //!RAL_WINDOWS