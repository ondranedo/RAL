#pragma once
#include "../pch.h"
#include "../platformLayer/memory/memory.h"

namespace RAL {
	class Application {
	public:
		Application(const Memory& mem);
		~Application();
		void run();
	};

}