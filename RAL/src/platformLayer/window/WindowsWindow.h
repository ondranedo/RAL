#pragma once
#include <GLFW/glfw3.h>
#include "types.h"
#include "window.h"

namespace RAL 
{
	class WindowsWindow : public Window
	{
	public:
		void Init(Window window);
		void Destroy(Window window);
		void MakeContextCurrent();
	private:
		GLFWwindow m_window;
	};
}