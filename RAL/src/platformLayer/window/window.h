#pragma once
#include "types.h"

namespace RAL
{
	class Window
	{
	public:
		void getWidth(u32_t new_Width);
		void getHeight(u32_t new_Height);

	protected:
		struct Config
		{
			u32_t m_Width;
			u32_t m_Height;
			const i8_t* m_Title;

			Config(u32_t width = 1280,
				u32_t height = 720,
				const i8_t title = "RAL")
				: m_Width(width), m_Height(height), m_Title(title) {}
		};
		Config m_config;
	};
}