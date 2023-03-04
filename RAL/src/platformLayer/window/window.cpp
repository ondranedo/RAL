#include "window.h"

namespace RAL
{
	void Window::getWidth(u32_t new_Width)
	{
		m_config.m_Width = new_Width;
	}

	void Window::getHeight(u32_t new_Height)
	{
		m_config.m_Height = new_Height;
	}
}
