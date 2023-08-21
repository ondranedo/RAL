/////////////////////////////////////////////////////////
// Copyright (C) 2023                                  //
// Ondřej Nedojedlý (https://www.github.com/ondranedo),//
// Matyáš Noska (https://www.github.com/sutiama),      //
// Vojtěch Šokala (https://github.com/Karnatour),      //
// Adam Wiszczor (https://github.com/1nome).           //
//                                                     //
// This file is part of `RAL_PROJECT` project          //
// which is released under `GNU General Public         //
// License v3.0` license.                              //
// See file `LICENSE` for full license details.        //
/////////////////////////////////////////////////////////

#ifndef RAL_PROJECT_WIN32WINDOW_H
#define RAL_PROJECT_WIN32WINDOW_H

#ifdef RAL_WINDOWS

#include <platfomLayer/window/Window.h>
#include <platfomLayer/windows/Win32GLFW.h>
#include <vendor/glfw/include/GLFW/glfw3.h>

namespace RAL::Win32 {
    class Win32Window : public Window {
    public:
        Win32Window(const WindowSpec &spec);

        void swapBuffers() override;

        Win32Window();

        void init() override;
        void release() override;
        void update() override;
        void makeContextCurrent() override;
        void setDims(uint16_t width, uint16_t height) override;
        void setTitle(const std::string &title) override;
        void setVSync(bool state) override;

        void create() override;
        void destroy() override;

        bool getVSync() const override;

        LoadProc getProcAddress() override;

    private:
        void setCallbacks() override;

    private:
        GLFWwindow *m_window;
    };
} // RAL
#endif //!RAL_WINDOWS
#endif //!RAL_PROJECT_WIN32WINDOW_H
