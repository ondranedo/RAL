#pragma once

#ifdef RAL_WINDOWS
#include "wMemory.h"
#endif
#include "../../core/baseFactory.h"
#include "../../core/allocator.h"

namespace RAL{

    class MemoryFactory : public BaseFactory<Memory>
    {

    public:
        Memory* create() override
        {
#ifdef RAL_WINDOWS
            return mainMemory.alloc<WinMemory>();
#endif
            return nullptr;
        };
};