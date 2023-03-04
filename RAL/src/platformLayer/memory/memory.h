#pragma once

/*TODO: check methods, headers and cmake
*		guard bytes
*		pointer validation
*		these only for compilation and debug
*		documentation (wiki)
*/

#include <stdlib.h>
#include "core/types.h"

namespace RAL {

	class Memory {

	private:
		i64_t allocated;

	public:
		Memory();
		~Memory();

		void* allocate(size_t bytes);
		void release(void* block);
	};
}