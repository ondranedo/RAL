#include "Wconsole.h"

WConsole::WConsole()
{	
	FreeConsole();
	AllocConsole();
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);
	RAL_LOG_DEBUG("Console constructed on Windows platform");
}

WConsole::~WConsole()
{
	
}

void WConsole::setTitle(const char* title)
{
	SetConsoleTitle(title);
}

void WConsole::log(const char* msg, ConsoleColourBackground background, ConsoleColourText text)
{
	SetConsoleTextAttribute(console, background | text);
}
