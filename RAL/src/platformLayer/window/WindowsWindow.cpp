#include "WindowsWindow.h"
#include "windowFactory.h"
#include "../../core/logger.h"

namespace RAL
{
	WindowsWindow::~WindowsWindow()
	{
		glfwTerminate();
	}

	WindowsWindow::WindowsWindow()
	{
		
	}
	void WindowsWindow::init()
	{
		RAL_LOG_INFO("Initializing GLFW");
		if (RAL::windowFactory::windowcount == 0)
		{
			if(!glfwInit()) RAL_LOG_ERROR("GLFW cant be initialized");
		}

		RAL_LOG_INFO("Creating windows window. Width: %d, Height: %d Title: %s", m_config.m_Width, m_config.m_Height, m_config.m_Title);
		m_window = glfwCreateWindow(m_config.m_Width, m_config.m_Height, m_config.m_Title, NULL, NULL);
		if (!m_window)
		{
			RAL_LOG_ERROR("Windows window cant be opened");
		}
		else RAL::windowFactory::windowcount++;

		//GLFW callbacks

	}

	void WindowsWindow::Destroy()
	{
		glfwDestroyWindow(m_window);
		RAL::windowFactory::windowcount--;
		if (RAL::windowFactory::windowcount == 0)
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

	void WindowsWindow::setWidth(i32_t new_width)
	{
		m_config.m_Width = new_width;
	}

	void WindowsWindow::setHeight(i32_t new_height)
	{
		m_config.m_Height = new_height;
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
