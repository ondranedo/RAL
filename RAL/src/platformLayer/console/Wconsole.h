#pragma once

#include "console.h"
#include <windows.h>

class WConsole : public RAL::Console
{
public:
	WConsole();
	~WConsole();
	void setTitle(const char* title) override;
	void log(const char* msg, ConsoleColourBackground background, ConsoleColourText text) override;
	void log(const char* msg, ConsoleColourText text, ConsoleColourBackground background) override;
	void log(const char* msg) override;
	void clear() override;
	void pause() override;
private:
	HANDLE console;
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written, mode, count;
	COORD topLeft = { 0, 0 };
	INPUT_RECORD input;
};