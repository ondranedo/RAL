#include "Wconsole.h"
#include <iostream>

WConsole::WConsole()
{	
	FreeConsole();
	AllocConsole();
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);
	freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
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
	printf("%s\n", msg);
}

void WConsole::log(const char* msg, ConsoleColourText text, ConsoleColourBackground background)
{
	SetConsoleTextAttribute(console, text | background);
	printf("%s\n",msg);
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
	SetConsoleTextAttribute(console, Console::BG_BLACK | Console::FG_LIGHTRED);
	printf("Console paused! Press any key to continue");
	std::cin.get();
}
