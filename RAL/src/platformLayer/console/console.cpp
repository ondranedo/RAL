#include "console.h"

namespace RAL {
	Console::~Console()
	{

	}

	Console* ConsoleFacotry::createConsole()
	{
		//TODO: Memory management
	#ifdef RAL_WINDOWS
		return new WConsole();
	#endif
	#ifdef RAL_LINUX
		return new LConsole();
	#endif
	#ifdef RAL_MAC
		return new MConsole();
	#endif
	}

	u8_t operator|(Console::ColourForeground foreground, Console::ColourBackground background)
	{
		return static_cast<u8_t>(foreground) | static_cast<u8_t>(background);
	}
	u8_t operator|(Console::ColourBackground  background, Console::ColourForeground foreground)
	{
		return foreground | background;
	}
};
