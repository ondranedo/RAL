#pragma once

#include "../../pch.h"
namespace RAL {
    class Memory {

    protected:
        i64_t nOfBytes;
#ifdef RAL_DEBUG
        i64_t nOfGuards;
#endif
        i64_t nOfBlocks;

    public:
        Memory();

        virtual ~Memory();

        typedef void* (Memory::*fallocate)(size_t);
        typedef void  (Memory::*ffree)(void*);

        virtual void *allocate(size_t bytes) = 0;

        virtual void release(void *block) = 0;

        virtual void *reallocate(void *block, size_t newSize) = 0;

        virtual fallocate getfAllocate() const;

        virtual ffree getfDellocate() const;

        i64_t allocated();

        i64_t blocks();
    };

    struct Allocator{
    private:
        Memory* m_memory = nullptr;
    public:
        template<typename T>
        T* alloc()
        {
            if(m_memory)
                return (T*)(m_memory->*(m_memory->getfAllocate()))(sizeof(T));
            std::cerr<<"Allocator unset\n";
        }
        void free(void* mem)
        {
            if(m_memory)
                (m_memory->*(m_memory->getfDellocate()))(mem);
            else
                std::cerr<<"Allocator unset\n";
        }
        void bindToMemory(Memory& mem)
        {
            m_memory = &mem;
        }
    }allocator;
}