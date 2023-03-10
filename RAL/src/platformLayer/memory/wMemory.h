#pragma once
#include "memory.h"

/*      pointer validation
*		runtime checks
*		add more guard bytes
*		add constants to make adding more guard bytes easier
*		add asserts for out of bounds access
*/

#ifdef RAL_WINDOWS

#include <cstdlib>

#ifdef RAL_DEBUG

#define GUARD_ONE 0xB0
#endif

namespace RAL {

	class WinMemory: public Memory {

	public:
        WinMemory();
        ~WinMemory() override;

		void* allocate(size_t bytes) override;
		void release(void* block) override;
		void* reallocate(void* block, size_t newSize) override;
        fallocate getfAllocate() const;
        ffree getfDellocate() const;
	};
}
#endif