#include "windowFactory.h"
#include "../../core/allocator.h"

namespace RAL
{
		i32_t WindowFactory::windowcount = 0;

		Window* WindowFactory::createWindow()
		{
            return mainMemory.alloc<WindowsWindow>();
		}

		i32_t WindowFactory::getWindowCount()
		{
			return windowcount;
		}
}