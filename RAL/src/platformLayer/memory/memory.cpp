#include "memory.h"
#include "../../core/logger.h"

namespace RAL {

	Memory::Memory() {

		RAL_LOG_TRACE("Memory tracker/allocator created");
		nOfBytes = 0;
		nOfBlocks = 0;
	}

	Memory::~Memory() {

		if (nOfBytes != 0)
			RAL_LOG_ERROR("Memory leak detected!");
		if(nOfBlocks != 0)
			RAL_LOG_CRIT("Memory corrupted!");

		RAL_LOG_TRACE("Memory tracker/allocator destroyed");
	}

	void* Memory::allocate(size_t bytes) {

#ifdef RAL_DEBUG

#else
		nOfBytes += bytes;
		nOfBlocks += 1;
		return malloc(bytes);
#endif
	}

	void Memory::release(void* block) {

		nOfBytes -= _msize(block);
		nOfBlocks -= 1;
		free(block);
	}

	i64_t Memory::allocated() {
		
		return nOfBytes;
	}

	i64_t Memory::blocks() {

		return nOfBlocks;
	}
}