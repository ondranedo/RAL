#pragma once

#include "../../pch.h"
namespace RAL {
    class Memory {

    protected:
        int64_t nOfBytes;
#ifdef RAL_DEBUG
        int64_t nOfGuards;
#endif
        int64_t nOfBlocks;

    public:
        Memory();

        virtual ~Memory();

        virtual void *allocate(size_t bytes) = 0;

        virtual void release(void *block) = 0;

        virtual void *reallocate(void *block, size_t newSize) = 0;

        int64_t allocated();
        int64_t blocks();
    };

    typedef void* (Memory::*fallocate)(size_t);
    typedef void  (Memory::*frelease)(void*);
    typedef void* (Memory::*freallocate)(void*,size_t);
};