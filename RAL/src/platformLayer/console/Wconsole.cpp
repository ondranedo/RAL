#include "Wconsole.h"

WConsole::WConsole()
{	
	//TODO: REMOVE THESE 2 LINES ONLY FOR TESTING 
	FreeConsole();
	printf("If you see this message Console was not created");
	AllocConsole();
	system("pause");
	RAL_LOG_DEBUG("Console constructed on Windows platform");
}

WConsole::~WConsole()
{

}

void WConsole::setTitle(const char* title)
{

}
