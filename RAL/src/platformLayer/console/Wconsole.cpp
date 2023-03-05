#include "Wconsole.h"

#ifdef RAL_WINDOWS
#include <iostream>

WConsole::WConsole()
{	
	AllocConsole();
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);
	freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
	RAL_LOG_DEBUG("Console constructed on Windows platform");
}

WConsole::~WConsole()
{
	FreeConsole();
}

void WConsole::setTitle(const RAL::String& title)
{
	SetConsoleTitle(title.c_str());
}

void WConsole::log(const RAL::String& msg, ColourBackground background, ColourForeground text)
{
	SetConsoleTextAttribute(console, background | text);
	printf("%s\n", msg.c_str());
}

void WConsole::log(const RAL::String& msg, ColourForeground text, ColourBackground background)
{
	SetConsoleTextAttribute(console, text | background);
	printf("%s\n",msg.c_str());
}

void WConsole::log(const RAL::String& msg)
{
	SetConsoleTextAttribute(console, ColourBackground::BLACK | ColourForeground::WHITE);
	printf("%s\n", msg.c_str());
}

void WConsole::clear()
{
	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void WConsole::pause()
{	
	SetConsoleTextAttribute(console, ColourBackground::BLACK | ColourForeground::LIGHTRED);
	printf("Console paused! Press any key to continue");
	std::cin.get();
}
#endif