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
	private:
		GLFWwindow* m_window;
	};
}