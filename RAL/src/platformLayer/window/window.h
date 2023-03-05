#pragma once
#include "../../core/types.h"

namespace RAL
{
	class Window
	{
	public:

	protected:
		struct Config
		{
			u32_t m_Width;
			u32_t m_Height;
			const char* m_Title;

			Config(u32_t width = 1280,
				u32_t height = 720,
				const char* title = "RAL")
				: m_Width(width), m_Height(height), m_Title(title) {}
		};
		Config m_config;
	};
}