#include "WindowsWindow.h"
#include "windowFactory.h"
#include "../../core/logger.h"

namespace RAL
{
    WindowsWindow::WindowsWindow()
    {

    }

    WindowsWindow::~WindowsWindow()
	{
		glfwTerminate();
	}

	void WindowsWindow::Init()
	{

		if (RAL::WindowFactory::windowcount == 0)
		{
            RAL_LOG_INFO("Initializing GLFW");
			RAL_ASSERT_NULL(glfwInit(),"GLFW cant be initialized");
		}

		RAL_LOG_INFO("Creating windows window. Width: %d, Height: %d Title: %s", m_width, m_height, m_title);
		m_window = glfwCreateWindow(static_cast<int>(m_width), static_cast<int>(m_height), m_title.c_str(), nullptr, nullptr);
        RAL_ASSERT_NULL(m_window, "Windows window cant be opened");

		if(m_window) RAL::WindowFactory::windowcount++;

		//GLFW callbacks

	}

	void WindowsWindow::Destroy()
	{
		glfwDestroyWindow(m_window);
		RAL::WindowFactory::windowcount--;
		if (RAL::WindowFactory::windowcount == 0)
		{
			glfwTerminate();
		}
	}

	void WindowsWindow::MakeContextCurrent()
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

	void WindowsWindow::VSyncenable()
	{
		glfwSwapInterval(1);
	}

	void WindowsWindow::VSyncdisable()
	{
		glfwSwapInterval(0);
	}
}
