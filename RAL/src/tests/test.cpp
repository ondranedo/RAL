#include "test.h"
#include "core/defines.h"
#include "core/logger.h"

namespace RAL {
	RAL_API void test_all()
	{
		RAL_LOG_PRIORITY_DEBUG();
		test_linkage();
	}

	// Testing linkage
	RAL_API void test_linkage()
	{
		RAL_LOG_DEBUG("Testing rala linkage");
	}
}

