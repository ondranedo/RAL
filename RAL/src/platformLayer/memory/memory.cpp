#include "memory.h"

namespace RAL{
    Memory::Memory(){

    }

    Memory::~Memory(){

    }

    i64_t Memory::allocated() {

#ifdef RAL_DEBUG
        return nOfBytes /*+ nOfGuards*/;
#else
        return nOfBytes;
#endif
    }

    i64_t Memory::blocks() {

        return nOfBlocks;
    }
}