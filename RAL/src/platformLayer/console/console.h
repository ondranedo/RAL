#pragma once
#include "core/logger.h"
#include "core/asserts.h"
#define RAL_WINDOWS

namespace RAL
{
	class Console
	{
	public:
		/* API
			Windows->https://learn.microsoft.com/en-us/windows/console/console-functions
		*/
		virtual void setTitle(const char* title) = 0;
		virtual void setTextAttribute() = 0;
		virtual void setScreenBufferSize() = 0;
		virtual void setCurrentFontEx() = 0;
		virtual void setWindowInfo() = 0;
		virtual void setConsoleMode() = 0;
		virtual void setConsoleHistoryInfo() = 0;
		virtual void setConsoleDisplayMode() = 0;
		virtual void setConsoleCursorPosition() = 0;
		virtual void setConsoleCursorInfo() = 0;
		virtual void setConsoleActiveScreenBuffer() = 0;

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
