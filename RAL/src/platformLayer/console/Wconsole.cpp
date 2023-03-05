#include "Wconsole.h"

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
	GetConsoleMode(console, &mode);
	SetConsoleMode(console, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));

	while (true)
	{
		ReadConsoleInput(console, &input, 1, &count);
		if (input.EventType == KEY_EVENT && input.Event.KeyEvent.bKeyDown)
		{
			if (input.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
			{
				break;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}

	SetConsoleMode(console, mode);
	return;
}
