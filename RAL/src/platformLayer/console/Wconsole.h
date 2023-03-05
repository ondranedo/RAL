#pragma once

#include "console.h"
#include <windows.h>

class WConsole : public RAL::Console
{
public:
	WConsole();
	~WConsole();
	void setTitle(const char* title) override;
	virtual void setTextAttribute() override;
	virtual void setScreenBufferSize() override;
	virtual void setCurrentFontEx() override;
	virtual void setWindowInfo() override;
	virtual void setConsoleMode() override;
	virtual void setConsoleHistoryInfo() override;
	virtual void setConsoleDisplayMode() override;
	virtual void setConsoleCursorPosition() override;
	virtual void setConsoleCursorInfo() override;
	virtual void setConsoleActiveScreenBuffer() override;
};