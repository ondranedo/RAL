#include "consoleInterpreter.h"

namespace RAL {
	ConsoleInterpreter::~ConsoleInterpreter()
	{

	}

	ConsoleInterpreter* ConsoleInterpreterFactory::createConsole()
	{
		//TODO: Memory management
	#ifdef RAL_WINDOWS
		return new WConsoleInterpreter();
    #endif

        return nullptr;
	}

	u8_t operator|(ConsoleInterpreter::ColourForeground foreground, ConsoleInterpreter::ColourBackground background)
	{
		return static_cast<u8_t>(foreground) | static_cast<u8_t>(background);
	}
	u8_t operator|(ConsoleInterpreter::ColourBackground  background, ConsoleInterpreter::ColourForeground foreground)
	{
		return foreground | background;
	}
}
