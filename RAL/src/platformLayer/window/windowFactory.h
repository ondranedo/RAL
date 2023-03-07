#pragma once
#include "windows.h"
#include "WindowsWindow.h"

namespace RAL
{
	class windowFactory
	{
	public:
		static i32_t getWindowCount();
		static i32_t windowcount;
		static Window* createWindow();
	private:
	};
}

//#ifdef RAL_PLATFORM_WINDOWS
//#define INIT() RAL::WindowsWindow::init();
//#endif