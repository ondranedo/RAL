#include "application.h"
#include "../platformLayer/window/window.h"
#include "../platformLayer/window/windowFactory.h"
#include "../platformLayer/console/consoleInterpreter.h"
#include "../platformLayer/console/consoleInterpreterFactory.h"

namespace RAL
{
    Application::Application(int argc, char **argv)
    {
        RAL_LOG_TRACE("Application created");
// setMem(mem)
        //m_factoryMGR.addBeforeCreate(mem, "memory");

// init()+
        //m_factoryMGR.addFactory<MemoryFactory>(FactoryMGR::options::NOT_DEFAULT_CREATE);
        //m_factoryMGR.addFactory<WindowFactory>(FactoryMGR::options::NOT_DEFAULT_CREATE);
        //m_factoryMGR.addFactory<ConsoleInterpreterFactory>();

        //m_factoryMGR.createComponent<Window>("mainWindow",  150,300,"RAL   engine");
        //m_factoryMGR.createComponent<Window>("debugWindow", 100,100,"debug engine");

        //m_factoryMGR.removeComponet("debugWindow");

        //m_factoryMGR.create();

        //m_factoryMGR.init();
    }

	Application::~Application()
	{
		RAL_LOG_TRACE("Application destroyed");
	}
};