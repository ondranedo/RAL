#pragma once

#include "../platformLayer/memory/memory.h"

namespace RAL{
    struct Allocator{
        template<typename T, size_t S = 1, typename... Args>
        T* alloc(Args... args)
        {
            if(m_memory){
                T* ptr = (T*)(m_memory->*(&Memory::allocate))(sizeof(T)*S);
                new (ptr) T(args...);
                return ptr;
            }
            std::cerr<<"Allocator unset\n";
            return nullptr;
        }
        template<typename T>
        void release(T* mem)
        {
            if(m_memory){
                (m_memory->*(&Memory::release))(mem);
                mem->~T();
            }
            else
                std::cerr<<"Allocator unset\n";
        }
        void bindToMemory(Memory& mem);
        void* reallocate(void* mem, size_t size);

    private:
        Memory* m_memory = nullptr;
    };

    extern Allocator mainMemory;
}
