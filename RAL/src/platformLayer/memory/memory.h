#pragma once

/*TODO: pointer validation
*		documentation (wiki)
*		runtime checks
*		add more guard bytes
*		add constants to make adding more guard bytes easier
*		add asserts for out of bounds access
*/

#include <stdlib.h>
#include "core/types.h"

#ifdef RAL_DEBUG

#define GUARD_ONE 0xB0
#endif

namespace RAL {

	class Memory {

	protected:
		i64_t nOfBytes;
#ifdef RAL_DEBUG
		i64_t nOfGuards;
#endif
		i64_t nOfBlocks;

	public:
		Memory();
		~Memory();

		virtual void* allocate(size_t bytes) = 0;
		virtual void release(void* block) = 0;
		i64_t allocated();
		i64_t blocks();
	};

	class WinMemory: public Memory {

	public:
		void* allocate(size_t bytes);
		void release(void* block);
	};
}