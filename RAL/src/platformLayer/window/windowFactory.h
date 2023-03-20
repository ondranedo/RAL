#pragma once
#include "window.h"
#include "WindowsWindow.h"
#include "../../core/baseFactory.h"
#include "../../core/allocator.h"

namespace RAL
{
    class WindowFactory : public BaseFactory<Window>
    {
    public:
        Window* create() override
        {
#ifdef RAL_WINDOWS
            return mainMemory.alloc<WindowsWindow>();
#endif
            return nullptr;
        }
    private:
    };
};

//#ifdef RAL_PLATFORM_WINDOWS
//#define INIT() RAL::WindowsWindow::init();
//#endif