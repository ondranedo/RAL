#include "WindowsWindow.h"
#include "windowFactory.h"
#include "../../core/logger.h"
#include "../../core/types.h"
#include "../../core/asserts.h"
#include "../../core/allocator.h"


namespace RAL
{

    static void* _alloc(size_t size,void* user)
    {
        return malloc(size);
    }
    static void* _realloc(void* block, size_t size, void* user)
    {
        return realloc(block, size);
    }
    static void _release(void* block, void* user)
    {
        free(block);
    }

    WindowsWindow::WindowsWindow()
    {
    }

    WindowsWindow::~WindowsWindow()
	{
		glfwTerminate();
	}

	void WindowsWindow::init()
	{

        GLFWallocator allocator;
        allocator.allocate = _alloc;
        allocator.reallocate = _realloc;
        allocator.deallocate = _release;
        allocator.user = NULL;

        glfwInitAllocator(&allocator);
        //TODO:: Windowcoount
;		if (1)
		{
            RAL_LOG_INFO("Initializing GLFW");
			RAL_ASSERT_NULL(glfwInit(),"GLFW cant be initialized");
		}

		RAL_LOG_INFO("Creating windows window. Width: %d, Height: %d Title: %s", m_width, m_height, m_title.c_str());
		m_window = glfwCreateWindow(static_cast<int>(m_width), static_cast<int>(m_height), m_title.c_str(), nullptr, nullptr);
        RAL_ASSERT_NULL(m_window, "Windows window cant be opened");

		//if(m_window) RAL::WindowFactory::windowcount++;

		//GLFW callbacks
	}

	void WindowsWindow::destroy()
	{
		glfwDestroyWindow(m_window);
		//RAL::WindowFactory::windowcount--;
		//if (RAL::WindowFactory::windowcount == 0)
		{
			glfwTerminate();
		}
	}

	void WindowsWindow::makeContextCurrent()
	{
		glfwMakeContextCurrent(m_window);
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::setDims(const RAL::Pair<u8_t, u8_t>& dimsWH)
	{
		m_width = dimsWH.first;
		m_height = dimsWH.second;
	}

	void WindowsWindow::vSyncEnable()
	{
		glfwSwapInterval(1);
	}

	void WindowsWindow::vSyncDisable()
	{
		glfwSwapInterval(0);
	}

    void WindowsWindow::setEvenCallBack()
    {

    }
}
