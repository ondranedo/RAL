#pragma once

#include "../platformLayer/memory/memory.h"

namespace RAL{
    struct Allocator{
        template<typename T>
        T* alloc()
        {
            if(m_memory)
                return (T*)(m_memory->*(&Memory::allocate))(sizeof(T));
            std::cerr<<"Allocator unset\n";
            return nullptr;
        }
        void release(void* mem);
        void bindToMemory(Memory& mem);
        void* reallocate(void* mem, size_t size);

    private:
        Memory* m_memory = nullptr;
    };

    extern Allocator mainMemory;
}
