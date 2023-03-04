#include "memory.h"
#include "../../core/logger.h"

namespace RAL {

	Memory::Memory() {

		RAL_LOG_TRACE("Memory tracker/allocator created");
		allocated = 0;
	}

	Memory::~Memory() {

		if (allocated != 0)
			RAL_LOG_ERROR("Memory leak detected!");

		RAL_LOG_TRACE("Memory tracker/allocator destroyed");
	}

	void* Memory::allocate(size_t bytes) {

		allocated += bytes;
		return malloc(bytes);
	}

	void Memory::release(void* block) {

		allocated -= sizeof(block);
		free(block);
	}
}