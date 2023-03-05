#pragma once

/*TODO: pointer validation
*		documentation (wiki)
*		change to a interface, create a class for windows
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

	private:
		i64_t nOfBytes;
#ifdef RAL_DEBUG
		i64_t nOfGuards;
#endif
		i64_t nOfBlocks;

	public:
		Memory();
		~Memory();

		void* allocate(size_t bytes);
		void release(void* block);
		i64_t allocated();
		i64_t blocks();
	};
}