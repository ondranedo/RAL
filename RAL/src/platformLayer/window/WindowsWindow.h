#pragma once
#include <GLFW/glfw3.h>
#include "../../core/types.h"
#include "window.h"

namespace RAL {

    class WindowsWindow : public Window {
    public:
        WindowsWindow();

        virtual ~WindowsWindow();

        void Init() override;

        void Destroy() override;

        void MakeContextCurrent() override;

        void onUpdate() override;

        void setDims(const RAL::Pair<u8_t, u8_t>& dimsWH) override;

        void VSyncenable() override;

        void VSyncdisable() override;

    private:
        GLFWwindow *m_window;
    };
};
