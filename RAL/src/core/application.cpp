#include "application.h"
#include "../platformLayer/window/window.h"
#include "../platformLayer/window/windowFactory.h"
#include "../platformLayer/console/consoleInterpreter.h"

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
        ConsoleInterpreter* console = ConsoleInterpreterFactory::createConsole();
        RAL::LoggerClass debug;
        RAL_LOG_INFO("a");
        console->clear();
        console->setTitle("debug console");
        console->log("More", ConsoleInterpreter::ColourBackground::GREEN, ConsoleInterpreter::ColourForeground::WHITE);
        console->pause();
        delete console;
	}
};