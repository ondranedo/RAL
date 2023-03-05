#pragma once

#include "core/defines.h"

namespace RAL {
	class RAL_API Application {
	public:
		Application(int argc, char** argv);
		~Application();
		void run();
	};
}