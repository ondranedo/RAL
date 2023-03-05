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
private:
	HANDLE console;
};