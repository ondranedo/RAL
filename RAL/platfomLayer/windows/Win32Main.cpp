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

#include <thread>
#include <core/Main.h>
#include <core/utility/Logger.h>
#include <platfomLayer/windows/memory/Win32Memory.h>
#include <platfomLayer/windows/consoleInterpreter/Win32ConsoleInterpreter.h>

namespace RAL {
	namespace Win32 {
		int main()
		{
			RAL_LOG_DEBUG("Starting on Windows");

            Win32Memory memory;
			Win32ConsoleInterpreter interpreter;
			interpreter.init();
			interpreter.setTitle("RAL engine - debug console");
			interpreter.log(" \xDA");
			interpreter.log("Starting logging...\n", ConsoleInterpreter::ColourForeground::GRAY, ConsoleInterpreter::ColourBackground::BLACK);
			interpreter.log("\xB3\n");

            global::mainLogger.setConsoleInterpreter(&interpreter);


			StartupInfo info = { &interpreter, &memory };
			RAL::main(info);

            RAL_LOG_DEBUG("Ending on Windows");

            memory.checkMemoryLeak();
            global::mainLogger.print();

            interpreter.log("\xB3\n");
            interpreter.log("\xAF");
#ifdef RAL_DEBUG
            system("pause");
#endif //!RAL_DEBUG

            interpreter.release();
			global::mainLogger.detachConsoleInterpreter();

			return 0;
		}
	}
}

#endif //!RAL_WINDOWS