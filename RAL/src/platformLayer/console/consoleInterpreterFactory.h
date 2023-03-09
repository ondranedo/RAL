//
// Created by Vojta on 09.03.2023.
//

#pragma once

#ifdef RAL_WINDOWS
#include "wConsoleInterpreter.h"
#endif //!RAL_WINDOWS

namespace RAL
{
	class ConsoleInterpreterFactory
	{
	public:
		static ConsoleInterpreter* createConsole();
	};
}
