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

#ifdef RAL_WINDOWS

#include "Win32Window.h"

#include <core/utility/Asserts.h>

namespace RAL::Win32 {
    Win32Window::Win32Window(const WindowSpec &spec) : Window(spec), m_window(nullptr) {}
    Win32Window::Win32Window() : Window(WindowSpec()), m_window(nullptr) {}

    void Win32Window::init() {
        global::glfw.init();
    }

    void Win32Window::release() {
        global::glfw.release();
    }

    void Win32Window::update() {
        RAL_ASSERT(m_window, "Cannot update window, window `%s` is not created", m_spec.m_title);
        if(!m_window) return;
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }

    void Win32Window::makeContextCurrent() {
        RAL_ASSERT(m_window, "Cannot make context current, window `%s` is not created", m_spec.m_title);
        if(!m_window) return;
        glfwMakeContextCurrent(m_window);
    }

    void Win32Window::setDims(uint16_t width, uint16_t height) {
        RAL_ASSERT(m_window, "Cannot set window dimensions, window `%s` is not created", m_spec.m_title);
        if(!m_window) return;
        glfwSetWindowSize(m_window, width, height);
    }

    void Win32Window::setTitle(const std::string &title) {
        RAL_ASSERT(title.size() > 0, "Window `%s` title cannot be empty", m_spec.m_title);
        RAL_ASSERT(title.size() < RAL_WINDOW_SPEC_TITLE_SIZE, "Window `%s` title cannot be longer than %d characters", m_spec.m_title, RAL_WINDOW_SPEC_TITLE_SIZE);
        glfwSetWindowTitle(m_window, title.c_str());
        strcpy(m_spec.m_title,title.c_str());
    }

    void Win32Window::setVSync(bool state) {
        global::glfw.setVSync(state);
    }

    void Win32Window::create() {
        m_window = glfwCreateWindow(m_spec.m_width, m_spec.m_height, m_spec.m_title, nullptr, nullptr);
        if(m_window)
        {
            RAL_LOG_DEBUG("Windows window `%s` created", m_spec.m_title);
            m_spec.m_created = true;
            return;
        }

        RAL_LOG_ERROR("Windows window `%s` creation failed", m_spec.m_title);
    }

    void Win32Window::destroy() {
        RAL_LOG_DEBUG("Windows window `%s` destroyed", m_spec.m_title);
        glfwDestroyWindow(m_window);
        m_spec.m_created = false;
    }

    bool Win32Window::getVSync() const {
        return global::glfw.getVSync();
    }
} // RAL

#endif //!RAL_WINDOWS