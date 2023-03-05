#include "windowFactory.h"

namespace RAL
{
		i32_t windowFactory::windowcount = 0;

		Window* windowFactory::createWindow()
		{
			return new WindowsWindow();
		}

		i32_t windowFactory::getWindowCount()
		{
			return windowcount;
		}
}