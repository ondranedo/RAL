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
};



