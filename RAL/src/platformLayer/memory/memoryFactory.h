#pragma once

#ifdef RAL_WINDOWS
#include "wMemory.h"
#endif

namespace RAL{

    class MemoryFactory{

    public:
        Memory* createMemory();
    };
}