#pragma once
#include <GLFW/glfw3.h>
#include "../../core/types.h"
#include "window.h"

namespace RAL 
{
	class WindowsWindow : public Window
	{
	public:
		void init();
		void Destroy();
		void MakeContextCurrent();
		void SwapBuffers();

		void getWidth(u32_t new_Width);
		void getHeight(u32_t new_Height);

		void VSyncenable();
		void VSyncdisable();
	private:
		GLFWwindow* m_window;
	};
}