#include "fileIOFactory.h"
#include "../../core/allocator.h"

namespace RAL{

    FileIO* FileIOFactory::createFileIO() {

#ifdef RAL_WINDOWS
        return mainMemory.alloc<WFileIO>();
#endif
        return nullptr;
    }
}