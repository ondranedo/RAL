#include "window.h"

namespace RAL
{
	void Window::GetWidth(u32_t new_Width)
	{
		m_config.m_Width = new_Width;
	}

	void Window::GetHeight(u32_t new_Height)
	{
		m_config.m_Height = new_Height;
	}
}
