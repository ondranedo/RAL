#pragma once
#include "core/logger.h"
#include "core/asserts.h"
#define RAL_WINDOWS

namespace RAL
{
	class Console
	{
	public:
		//API:https://learn.microsoft.com/en-us/windows/console/console-functions
		virtual void setTitle(const char* title) = 0;
		virtual void setTextAttribute() = 0;
		virtual void setScreenBufferSize() = 0;
		virtual void setCurrentFontEx() = 0;
		virtual void setWindowInfo() = 0;
		virtual void SetConsoleMode() = 0;
		virtual void SetConsoleHistoryInfo() = 0;
		virtual void SetConsoleDisplayMode() = 0;
		virtual void SetConsoleCursorPosition() = 0;
		virtual void SetConsoleCursorInfo() = 0;
		virtual void SetConsoleActiveScreenBuffer() = 0;

		virtual ~Console();
	};
};

#ifdef RAL_WINDOWS
#include "Wconsole.h"
#endif // _DEBUG
#ifdef RAL_LINUX
#include "Lconsole.h"
#endif // _DEBUG
#ifdef RAL_MAC
#include "Mconsole.h"
#endif // _DEBUG

namespace RAL
{
	class ConsoleFacotry
	{
	public:
		static Console* createConsole();
	};
}
