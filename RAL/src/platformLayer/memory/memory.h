#pragma once

/*TODO: check methods, headers and cmake
*		guard bytes
*		pointer validation
*		documentation (wiki)
*		change to a interface, create a class for windows
*		runtime checks
*/

#include <stdlib.h>
#include "core/types.h"

#ifdef RAL_DEBUG

#define GUARD_TWO 0xFACC
#define GUARD_FOUR 0xC0CCD1CC
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