#include "application.h"

namespace RAL {
	Application::Application(int argc, char** argv)
	{
		RAL_LOG_TRACE("Application created");
	}

	Application::~Application()
	{
		RAL_LOG_TRACE("Application destroyed");
	}

	void Application::run()
	{

	}
};