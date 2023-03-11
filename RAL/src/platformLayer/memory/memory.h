#pragma once

#include "../../core/types.h"

typedef u64_t size_t;

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

        virtual void *allocate(size_t bytes) = 0;

        virtual void release(void *block) = 0;

        virtual void *reallocate(void *block, size_t newSize) = 0;

        i64_t allocated();
        i64_t blocks();
    };

    typedef void* (Memory::*fallocate)(size_t);
    typedef void  (Memory::*frelease)(void*);
    typedef void* (Memory::*freallocate)(void*,size_t);
};