#pragma once
#include <GLFW/glfw3.h>
#include "../../core/types.h"
#include "window.h"

namespace RAL {

    class WindowsWindow : public Window {
    public:
        WindowsWindow();
        virtual ~WindowsWindow();

        void init() override;
        void destroy() override;
        void makeContextCurrent() override;
        void onUpdate() override;
        void setEvenCallBack() override;
        void setDims(const RAL::Pair<u8_t, u8_t>& dimsWH) override;
        void vSyncEnable() override;
        void vSyncDisable() override;

    private:
        GLFWwindow *m_window;
    };
};
