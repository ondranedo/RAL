#include "console.h"

namespace RAL {
	Console::~Console()
	{

	}

	Console* ConsoleFacotry::createConsole()
	{
		return new WConsole();
	}
};



