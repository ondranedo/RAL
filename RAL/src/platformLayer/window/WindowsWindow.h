#pragma once
#include <GLFW/glfw3.h>
#include "../../core/types.h"
#include "window.h"

namespace RAL 
{

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow();
		virtual ~WindowsWindow();
		void init() override;
		void Destroy() override;
		void MakeContextCurrent() override;
		void onUpdate() override;

		void setWidth(i32_t new_width) override;
		void setHeight(i32_t new_width) override;

		void VSyncenable() override;
		void VSyncdisable() override;
	private:
		GLFWwindow* m_window;
	};
	

}