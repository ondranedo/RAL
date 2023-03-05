#pragma once
#include "../../core/logger.h"
#include "../../core/asserts.h"
#include "../../core/defines.h"

namespace RAL
{
	class Console
	{
	public:
		enum class ColourBackground : u8_t
		{
			BLACK = 0,
			NAVYBLUE = 16,
			GREEN = 32,
			TEAL = 48,
			MAROON = 64,
			PURPLE = 80,
			OLIVE = 96,
			SILVER = 112,
			GRAY = 128,
			BLUE = 144,
			LIME = 160,
			CYAN = 176,
			RED = 192,
			MAGENTA = 208,
			YELLOW = 224,
			WHITE = 240
		};
		enum class ColourForeground : u8_t
		{
			BLACK = 0,
			BLUE = 1,
			GREEN = 2,
			CYAN = 3,
			RED = 4,
			MAGENTA = 5,
			BROWN = 6,
			LIGHTGRAY = 7,
			GRAY = 8,
			LIGHTBLUE = 9,
			LIGHTGREEN = 10,
			LIGHTCYAN = 11,
			LIGHTRED = 12,
			LIGHTMAGENTA = 13,
			YELLOW = 14,
			WHITE = 15
		};

		virtual void setTitle(const char* title) = 0;
		virtual void log(const char* msg, ColourBackground background, ColourForeground text = ColourForeground::WHITE) = 0;
		virtual void log(const char* msg, ColourForeground text, ColourBackground background = ColourBackground::BLACK) = 0;
		virtual void log(const char* msg) = 0;
		virtual void clear() = 0;
		virtual void pause() = 0;
		virtual ~Console();
	};

	u8_t operator|(Console::ColourForeground foreground, Console::ColourBackground background);
	u8_t operator|(Console::ColourBackground background, Console::ColourForeground foreground);
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
