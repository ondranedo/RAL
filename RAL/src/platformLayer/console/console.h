#pragma once
#include "core/logger.h"
#include "core/asserts.h"
#define RAL_WINDOWS

namespace RAL
{
	class Console
	{
	public:
		enum ConsoleColourBackground
		{
			BG_BLACK = 0,
			BG_NAVYBLUE = 16,
			BG_GREEN = 32,
			BG_TEAL = 48,
			BG_MAROON = 64,
			BG_PURPLE = 80,
			BG_OLIVE = 96,
			BG_SILVER = 112,
			BG_GRAY = 128,
			BG_BLUE = 144,
			BG_LIME = 160,
			BG_CYAN = 176,
			BG_RED = 192,
			BG_MAGENTA = 208,
			BG_YELLOW = 224,
			BG_WHITE = 240
		};
		enum ConsoleColourText
		{
			FG_BLACK = 0,
			FG_BLUE = 1,
			FG_GREEN = 2,
			FG_CYAN = 3,
			FG_RED = 4,
			FG_MAGENTA = 5,
			FG_BROWN = 6,
			FG_LIGHTGRAY = 7,
			FG_GRAY = 8,
			FG_LIGHTBLUE = 9,
			FG_LIGHTGREEN = 10,
			FG_LIGHTCYAN = 11,
			FG_LIGHTRED = 12,
			FG_LIGHTMAGENTA = 13,
			FG_YELLOW = 14,
			FG_WHITE = 15
		};
		/* API
			Windows->https://learn.microsoft.com/en-us/windows/console/console-functions
		*/
		virtual void setTitle(const char* title) = 0;
		virtual void log(const char* msg, ConsoleColourBackground background=BG_BLACK, ConsoleColourText text=FG_WHITE) = 0;
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
