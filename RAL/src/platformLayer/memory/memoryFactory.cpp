#include "memoryFactory.h"

namespace RAL{

    Memory* MemoryFactory::createMemory() {

#ifdef RAL_WINDOWS
        return new WinMemory();
#endif
        return nullptr;
    }
}