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
	virtual void SetConsoleMode() override;
	virtual void SetConsoleHistoryInfo() override;
	virtual void SetConsoleDisplayMode() override;
	virtual void SetConsoleCursorPosition() override;
	virtual void SetConsoleCursorInfo() override;
	virtual void SetConsoleActiveScreenBuffer() override;
};