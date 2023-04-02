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

#include "Win32GLFW.h"

#include <core/utility/Logger.h>
#include <core/utility/Asserts.h>
#include <vendor/glfw/include/GLFW/glfw3.h>

namespace RAL::Win32 {
    namespace global {
        Win32GLFW glfw;
    }

    Win32GLFW::~Win32GLFW()
    {
        if(m_windowCount) {
            RAL_LOG_WARNING("GLFW is still initialized, terminating");
            glfwTerminate();
        }
    }
    // TODO: global setting
    Win32GLFW::Win32GLFW(): m_windowCount(0), m_isVSync(false) {};

    void Win32GLFW::init() {
        if(m_windowCount++) return;
        glfwInit();
        m_isVSync = true;
        glfwSwapInterval(m_isVSync ? 1 : 0);
        RAL_LOG_DEBUG("GLFW initialized %s VSync", m_isVSync ? "with" : "without");
    }


    void Win32GLFW::release() {
        if(--m_windowCount) return;
        glfwTerminate();
        RAL_LOG_DEBUG("GLFW terminated");
    }

    void Win32GLFW::setVSync(bool state){
        RAL_ASSERT(m_windowCount, "GLFW is not initialized, cannot set VSync");
        if(!m_windowCount)
        glfwSwapInterval(state ? 1 : 0);
        m_isVSync = state;
    }

    bool Win32GLFW::getVSync() const {
        RAL_ASSERT(m_windowCount, "GLFW is not initialized, cannot get VSync");
        if(!m_windowCount) return false;
        return m_isVSync;
    }
}

#endif //!RAL_WINDOWS