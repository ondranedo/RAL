#include "application.h"
#include "allocator.h"

#include "../platformLayer/memory/WMemory.h"

int main(int argc, char** argv)
{
    RAL_LOG_PRIORITY_TRACE();

#ifdef RAL_WINDOWS
    RAL::Memory* mem = new RAL::WinMemory;
#endif
    RAL::mainMemory.bindToMemory(*mem);

// Engine
    auto obj = RAL::mainMemory.alloc<RAL::Application>(mem);

	obj->run();

    RAL::mainMemory.release(obj);
//~Engine

    delete mem;
}