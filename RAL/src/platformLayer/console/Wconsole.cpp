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

void WConsole::setTitle(const char* title)
{
	SetConsoleTitle(title);
}

void WConsole::log(const char* msg, ColourBackground background, ColourForeground text)
{
	SetConsoleTextAttribute(console, background | text);
	printf("%s\n", msg);
}

void WConsole::log(const char* msg, ColourForeground text, ColourBackground background)
{
	SetConsoleTextAttribute(console, text | background);
	printf("%s\n",msg);
}

void WConsole::log(const char* msg)
{
	SetConsoleTextAttribute(console, ColourBackground::BLACK | ColourForeground::WHITE);
	printf("%s\n", msg);
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