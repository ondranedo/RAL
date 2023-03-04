#include "memory.h"
#include "../../core/logger.h"

namespace RAL {

	Memory::Memory() {

		RAL_LOG_TRACE("Memory tracker/allocator created");
		alloced = 0;
	}

	Memory::~Memory() {

		if (alloced != 0)
			RAL_LOG_ERROR("Memory leak detected!");

		RAL_LOG_TRACE("Memory tracker/allocator destroyed");
	}

	void* Memory::allocate(size_t bytes) {

		alloced += bytes;
		return malloc(bytes);
	}

	void Memory::release(void* block) {

		alloced -= sizeof(block);
		free(block);
	}

	i64_t Memory::allocated() {
		
		return alloced;
	}
}