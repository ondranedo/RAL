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

		int getWidth();
		int getHeight();

		void VSyncenable();
		void VSyncdisable();
	private:
		GLFWwindow* m_window;
	};
}