#include "Engine.h"
#include <iostream> 
#include <optional>

namespace RAL
{
	void Engine::init()
	{
		std::cout << " Engine initialized " << std::endl;
	}

	void Engine::run()
	{
		std::cout << " Engine is running " << std::endl;
	}

	void Engine::release()
	{
		std::cout << " Engine released " << std::endl;
	}
};


