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
	SetConsoleTitle(title);
}

void WConsole::setTextAttribute()
{

}

void WConsole::setScreenBufferSize()
{

}

void WConsole::setCurrentFontEx()
{

}

void WConsole::setWindowInfo()
{

}

void WConsole::setConsoleMode()
{

}

void WConsole::setConsoleHistoryInfo()
{

}

void WConsole::setConsoleDisplayMode()
{

}

void WConsole::setConsoleCursorPosition()
{

}

void WConsole::setConsoleCursorInfo()
{

}

void WConsole::setConsoleActiveScreenBuffer()
{

}
