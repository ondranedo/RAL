#include "wMemory.h"
#include "../../core/logger.h"

#ifdef RAL_WINDOWS

namespace RAL {

	WinMemory::WinMemory() {

		RAL_LOG_TRACE("Memory tracker/allocator created");
		nOfBytes = 0;
#ifdef RAL_DEBUG
		nOfGuards = 0;
#endif
		nOfBlocks = 0;
	}

	WinMemory::~WinMemory() {

		if (nOfBytes != 0)
			RAL_LOG_ERROR("Memory leak detected!");
#ifdef RAL_DEBUG
		if(nOfGuards != 0)
			RAL_LOG_ERROR("Guard bytes not freed!");
#endif
		if(nOfBlocks != 0)
			RAL_LOG_CRIT("Memory corrupted!");

		RAL_LOG_TRACE("Memory tracker/allocator destroyed");
	}

	void* WinMemory::allocate(size_t bytes) {

		nOfBytes += bytes;
		nOfBlocks += 1;
#ifdef RAL_DEBUG
		nOfGuards += 2;

		void* temp = malloc(bytes + 2);

		if (temp == NULL) {
			RAL_LOG_ERROR("Not enough memory!");
			return temp;
		}
		else {
			/*assigning guard bytes*/
			reinterpret_cast<u8_t*>(temp)[0] = (u8_t)GUARD_ONE;
			reinterpret_cast<u8_t*>(temp)[1 + bytes] = (u8_t)GUARD_ONE;

			/*shifting bytes so that the first index is writable*/
			temp = reinterpret_cast<u8_t*>(temp) + 1;
			return reinterpret_cast<void*>(temp);
		}
#else
		void* temp = malloc(bytes);
		if (temp == NULL)
			RAL_LOG_ERROR("Not enough memory!");

		return temp;
#endif
	}

	void WinMemory::release(void* block) {

#ifdef RAL_DEBUG
		/*shifting back to access the guard bytes*/
		block = reinterpret_cast<u8_t*>(block) - 1;
#endif
		nOfBytes -= _msize(block);
		nOfBlocks -= 1;
#ifdef RAL_DEBUG
		/*adding back the accessible bytes*/
		nOfBytes += 2;
		nOfGuards -= 2;

		if (reinterpret_cast<u8_t*>(block)[0] != (u8_t)GUARD_ONE) {
			RAL_LOG_CRIT("Out of bounds access detected!");
		}
		else if(reinterpret_cast<u8_t*>(block)[_msize(block) - 1] != (u8_t)GUARD_ONE)
			RAL_LOG_CRIT("Out of bounds access detected!");
#endif
		free(block);
	}

	void* WinMemory::reallocate(void* block, size_t newSize) {

#ifdef RAL_DEBUG
		/*shifting back to access the guard bytes*/
		block = reinterpret_cast<u8_t*>(block) - 1;
#endif
		nOfBytes -= _msize(block);
#ifdef RAL_DEBUG
		if (reinterpret_cast<u8_t*>(block)[0] != (u8_t)GUARD_ONE) {
			RAL_LOG_CRIT("Out of bounds access detected!");
		}
		else if (reinterpret_cast<u8_t*>(block)[_msize(block) - 1] != (u8_t)GUARD_ONE)
			RAL_LOG_CRIT("Out of bounds access detected!");
		
		/*adding back the accessible bytes and the new size*/
		nOfBytes += 2 + newSize;

		void* temp = realloc(block, newSize + 2);
		if (temp == NULL) {
			RAL_LOG_ERROR("Not enough memory!");
			return temp;
		}

		/*assigning guard bytes*/
		reinterpret_cast<u8_t*>(temp)[1 + newSize] = (u8_t)GUARD_ONE;

		/*shifting bytes so that the first index is writable*/
		temp = reinterpret_cast<u8_t*>(temp) + 1;
		return reinterpret_cast<void*>(temp);
#else
		void* temp = realloc(block, newSize);
		if (temp == NULL) {
			RAL_LOG_ERROR("Not enough memory!");
			return temp;
		}
#endif
        return nullptr;
	}

    fallocate WinMemory::getfAllocate() const {
        fallocate fun = &WinMemory::allocate;
        return fun;
    }
    ffree WinMemory::getfDellocate() const {
        ffree fun = &WinMemory::free;
        return fun;
    }
}
#endif