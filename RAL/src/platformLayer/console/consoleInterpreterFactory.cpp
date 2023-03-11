//
// Created by Vojta on 09.03.2023.
//

#include "consoleInterpreterFactory.h"

namespace RAL{

	ConsoleInterpreter* ConsoleInterpreterFactory::createConsole()
	{
		//TODO: Memory management
	#ifdef RAL_WINDOWS
		return new WConsoleInterpreter();
    #endif

        return nullptr;
	}
}
