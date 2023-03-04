#pragma once
#include "types.h"

namespace RAL
{
	struct WindowData
	{
		const i8_t* Title;
		u32_t Width;
		u32_t Height;
		WindowData(const i8_t* title = "RAL",
			u32_t width = 1280,
			u32_t height = 720,
			)
			: Title(title), Width(width), Height(height) {}
	};
	class RAL_API Window
	{
	public:
		virtual ~Window() {};

		virtual u32_t getWidth() = 0;
		virtual u32_t getHeight() = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() = 0;

		static Window* Create(WindowData& data = WindowData());
	};
}