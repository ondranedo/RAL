#pragma once
#include <GLFW/glfw3.h>
#include "types.h"
#include "window.h"

namespace RAL 
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(WindowData& data);
		virtual ~WindowsWindow();

		u32_t GetWidth() override { return m_Data.Width; }
		u32_t GetHeight() override { return m_Data.Height; }

		void setVsync() override;
		bool isVsync() override;
	private:
		GLFWwindow* m_Window;
		//m_Context;

		void Init(WindowData& data);
		void Destroy();

		struct WindowsWindowData
		{
			const i8_t* Title;
			u32_t Width, Height;
			bool VSync;
		};

		WindowsWindowData m_Data;
	};
}