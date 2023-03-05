#include "WindowsWindow.h"
#include "../../core/logger.h"

namespace RAL
{
	void WindowsWindow::init()
	{
		RAL_LOG_INFO("Initializing GLFW");
		if (!glfwInit())
		{
			RAL_LOG_ERROR("GLFW cant be initialized");
		}
		else
		{
			RAL_LOG_INFO("Creating windows window. Width: %d, Height: %d Title: %s", m_config.m_Width, m_config.m_Height, m_config.m_Title);
			m_window = glfwCreateWindow(m_config.m_Width, m_config.m_Height, m_config.m_Title, NULL, NULL);
			if (!m_window) RAL_LOG_ERROR("Windows window cant be opened");
		}

	}

	void WindowsWindow::Destroy()
	{
		glfwTerminate();
	}

	void WindowsWindow::MakeContextCurrent()
	{
		glfwMakeContextCurrent(m_window);
	}

	void WindowsWindow::SwapBuffers()
	{
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::getWidth(u32_t new_Width)
	{
		m_config.m_Width = new_Width;
	}

	void WindowsWindow::getHeight(u32_t new_Height)
	{
		m_config.m_Height = new_Height;
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
