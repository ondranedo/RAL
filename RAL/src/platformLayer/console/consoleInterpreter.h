#pragma once
#include "../../pch.h"

namespace RAL
{
	class ConsoleInterpreter
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
		virtual void setTitle(const RAL::String& title) = 0;
		virtual void log(const RAL::String& msg, ColourBackground background, ColourForeground text = ColourForeground::WHITE) = 0;
		virtual void log(const RAL::String& msg, ColourForeground text, ColourBackground background = ColourBackground::BLACK) = 0;
		virtual void log(const RAL::String& msg) = 0;
		virtual void clear() = 0;
		virtual void pause() = 0;
        virtual void unpause() = 0;
		virtual ~ConsoleInterpreter();
	};

	u8_t operator|(ConsoleInterpreter::ColourForeground foreground, ConsoleInterpreter::ColourBackground background);
	u8_t operator|(ConsoleInterpreter::ColourBackground background, ConsoleInterpreter::ColourForeground foreground);
}


