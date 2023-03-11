#include "allocator.h"

namespace RAL{
    Allocator mainMemory;

    void  Allocator::bindToMemory(Memory& mem)
    {
        m_memory = &mem;
    }

    void* Allocator::reallocate(void* mem, size_t size)
    {
        if(m_memory)
            return (m_memory->*(&Memory::reallocate))(mem, size);

        RAL_LOG_CRIT("Can't reallocate, memory unset");
        return nullptr;
    }
}