#pragma once

#ifdef RAL_WINDOWS
#include "wFileIO.h"
#endif

namespace RAL{

    class FileIOFactory{

    public:
        FileIO* createFileIO();
    };
}