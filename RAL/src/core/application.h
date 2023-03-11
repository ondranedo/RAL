#pragma once

#include "../platformLayer/memory/memory.h"

namespace RAL {
	class Application {
        Memory* m_memory;
	public:
		Application(Memory* mem);
		~Application();
		void run();
	};

}