#pragma once

/*TODO: check methods, headers and cmake
*		guard bytes
*		pointer validation
*		these only for compilation and debug
*		documentation (wiki)
*/

#include <stdlib.h>
#include "core/types.h"

#ifdef RAL_DEBUG

#define GUARD_ONE 0xB0
#define GUARD_TWO 0xFACC
#endif

namespace RAL {

	class Memory {

	private:
		i64_t alloced;

	public:
		Memory();
		~Memory();

		void* allocate(size_t bytes);
		void release(void* block);
		i64_t allocated();
	};
}