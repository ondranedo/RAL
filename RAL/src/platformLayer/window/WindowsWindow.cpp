#include "WindowsWindow.h"

namespace RAL
{
	void WindowsWindow::init()
	{
		glfwInit();
		m_window = glfwCreateWindow(m_config.m_Width, m_config.m_Height, m_config.m_Title, NULL, NULL);
	}

	void WindowsWindow::Destroy()
	{

	}

	void WindowsWindow::MakeContextCurrent()
	{
		glfwMakeContextCurrent(m_window);
	}
}
