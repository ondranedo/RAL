//
// Created by Vojta on 09.03.2023.
//

#pragma once

#ifdef RAL_WINDOWS
#include "wConsoleInterpreter.h"
#endif //!RAL_WINDOWS
#include "../../core/allocator.h"
#include "../../core/baseFactory.h"
#include "consoleInterpreter.h"

namespace RAL
{
	class ConsoleInterpreterFactory : BaseFactory<ConsoleInterpreter>
	{
	public:
		ConsoleInterpreter* create() override
        {
#ifdef RAL_WINDOWS
            return mainMemory.alloc<WConsoleInterpreter>();
#endif
        }
        const char *productName() override {
            return "ConsoleInterpreter";
        }
	};
};
