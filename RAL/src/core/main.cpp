#include "application.h"
#include "allocator.h"

#include "../platformLayer/memory/WMemory.h"

int main(int argc, char** argv)
{
    RAL_LOG_PRIORITY_TRACE();

#ifdef RAL_WINDOWS
    RAL::WinMemory mem;
#endif

    RAL::mainMemory.bindToMemory(mem);

    RAL::Application* app = (RAL::Application*)malloc(sizeof(RAL::Application));

	auto engine = RAL::mainMemory.alloc<RAL::Application>();

	engine->run();

    RAL::mainMemory.release(engine);
}