#include "application.h"
#include "core/logger.h"

namespace RAL {
	Application::Application()
	{
		RAL_LOG_TRACE("Application created");
	}

	Application::~Application()
	{
		RAL_LOG_TRACE("Application destroyed");
	}
};