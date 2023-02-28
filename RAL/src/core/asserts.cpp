#pragma once
#include "logger.h"

namespace RAL {
	namespace asserts {
		void msg(const char* message) {

			RAL_LOG_CRIT("%s : %d", __FILE__, __LINE__);
			RAL_LOG_CRIT(message);
		}
	}
}
