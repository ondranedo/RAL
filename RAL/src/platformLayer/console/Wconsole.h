#pragma once

#include "console.h"
#include <windows.h>

class WConsole : public RAL::Console
{
public:
	WConsole();
	~WConsole();
	void setTitle(const char* title) override;
};