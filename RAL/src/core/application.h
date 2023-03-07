#pragma once
#include "../pch.h"

namespace RAL {
	class Application {
	public:
		Application(int argc, char** argv);
		~Application();
		void run();
	};
}