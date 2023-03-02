#pragma once
#include "logger.h"

namespace RAL {
	namespace ASSERTS {
		RAL_API void msg(const char* message) {
			RAL_LOG_CRIT("%s : %d", __FILE__, __LINE__);
			RAL_LOG_CRIT(message);
		}
	}
}
