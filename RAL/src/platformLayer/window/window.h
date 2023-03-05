#pragma once
#include "../../core/types.h"

//TO DO:
//	-MUTEX lock
//	-

namespace RAL
{
	class Window
	{
	public:
		virtual ~Window();
		virtual void init() = 0;
		virtual void Destroy() = 0;
		virtual void MakeContextCurrent() = 0;
		virtual void onUpdate() = 0;

		virtual void setWidth(i32_t new_width) = 0;
		virtual void setHeight(i32_t new_width) = 0;

		virtual void VSyncenable() = 0;
		virtual void VSyncdisable() = 0;
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

