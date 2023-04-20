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

#include "Win32.h"

#include <core/utility/Logger.h>
#include <core/utility/Asserts.h>
#include <vendor/glfw/include/GLFW/glfw3.h>

namespace RAL::Win32 {
    namespace global {
        Win32 glfw;
    }

    Win32::~Win32()
    {
        if(m_windowCount) {
            RAL_LOG_WARNING("GLFW is still initialized, terminating");
            glfwTerminate();
        }
    }
    // TODO: global setting
    Win32::Win32(): m_windowCount(0), m_isVSync(false) {};

    void Win32::init() {
        if(m_windowCount++) return;
        glfwInit();
        m_isVSync = true;
        glfwSwapInterval(m_isVSync ? 1 : 0);
        RAL_LOG_DEBUG("GLFW initialized %s VSync", m_isVSync ? "with" : "without");
    }


    void Win32::release() {
        if(--m_windowCount) return;
        glfwTerminate();
        RAL_LOG_DEBUG("GLFW terminated");
    }

    void Win32::setVSync(bool state){
        RAL_ASSERT(m_windowCount, "GLFW is not initialized, cannot set VSync");
        if(!m_windowCount)
        glfwSwapInterval(state ? 1 : 0);
        m_isVSync = state;
    }

    bool Win32::getVSync() const {
        RAL_ASSERT(m_windowCount, "GLFW is not initialized, cannot get VSync");
        if(!m_windowCount) return false;
        return m_isVSync;
    }

    Types::Codes Win32::getCode(uint16_t glfwKeyCode) {
        switch (glfwKeyCode) {
            case GLFW_MOUSE_BUTTON_1: return Types::Codes::MBUTTON_1;
            case GLFW_MOUSE_BUTTON_2: return Types::Codes::MBUTTON_2;
            case GLFW_MOUSE_BUTTON_3: return Types::Codes::MBUTTON_3;
            case GLFW_MOUSE_BUTTON_4: return Types::Codes::MBUTTON_4;
            case GLFW_MOUSE_BUTTON_5: return Types::Codes::MBUTTON_5;
            case GLFW_MOUSE_BUTTON_6: return Types::Codes::MBUTTON_6;
            case GLFW_MOUSE_BUTTON_7: return Types::Codes::MBUTTON_7;
            case GLFW_MOUSE_BUTTON_8: return Types::Codes::MBUTTON_8;
            case GLFW_KEY_SPACE: return Types::Codes::SPACE;
            case GLFW_KEY_APOSTROPHE: return Types::Codes::APOSTROPHE;
            case GLFW_KEY_COMMA: return Types::Codes::COMMA;
            case GLFW_KEY_MINUS: return Types::Codes::MINUS;
            case GLFW_KEY_PERIOD: return Types::Codes::PERIOD;
            case GLFW_KEY_SLASH: return Types::Codes::SLASH;
            case GLFW_KEY_0: return Types::Codes::N0;
            case GLFW_KEY_1: return Types::Codes::N1;
            case GLFW_KEY_2: return Types::Codes::N2;
            case GLFW_KEY_3: return Types::Codes::N3;
            case GLFW_KEY_4: return Types::Codes::N4;
            case GLFW_KEY_5: return Types::Codes::N5;
            case GLFW_KEY_6: return Types::Codes::N6;
            case GLFW_KEY_7: return Types::Codes::N7;
            case GLFW_KEY_8: return Types::Codes::N8;
            case GLFW_KEY_9: return Types::Codes::N9;
            case GLFW_KEY_SEMICOLON: return Types::Codes::SEMICOLON;
            case GLFW_KEY_EQUAL: return Types::Codes::EQUAL;
            case GLFW_KEY_A: return Types::Codes::A;
            case GLFW_KEY_B: return Types::Codes::B;
            case GLFW_KEY_C: return Types::Codes::C;
            case GLFW_KEY_D: return Types::Codes::D;
            case GLFW_KEY_E: return Types::Codes::E;
            case GLFW_KEY_F: return Types::Codes::F;
            case GLFW_KEY_G: return Types::Codes::G;
            case GLFW_KEY_H: return Types::Codes::H;
            case GLFW_KEY_I: return Types::Codes::I;
            case GLFW_KEY_J: return Types::Codes::J;
            case GLFW_KEY_K: return Types::Codes::K;
            case GLFW_KEY_L: return Types::Codes::L;
            case GLFW_KEY_M: return Types::Codes::M;
            case GLFW_KEY_N: return Types::Codes::N;
            case GLFW_KEY_O: return Types::Codes::O;
            case GLFW_KEY_P: return Types::Codes::P;
            case GLFW_KEY_Q: return Types::Codes::Q;
            case GLFW_KEY_R: return Types::Codes::R;
            case GLFW_KEY_S: return Types::Codes::S;
            case GLFW_KEY_T: return Types::Codes::T;
            case GLFW_KEY_U: return Types::Codes::U;
            case GLFW_KEY_V: return Types::Codes::V;
            case GLFW_KEY_W: return Types::Codes::W;
            case GLFW_KEY_X: return Types::Codes::X;
            case GLFW_KEY_Y: return Types::Codes::Y;
            case GLFW_KEY_Z: return Types::Codes::Z;
            case GLFW_KEY_LEFT_BRACKET: return Types::Codes::LEFT_BRACKET;
            case GLFW_KEY_BACKSLASH: return Types::Codes::BACKSLASH;
            case GLFW_KEY_RIGHT_BRACKET: return Types::Codes::RIGHT_BRACKET;
            case GLFW_KEY_GRAVE_ACCENT: return Types::Codes::GRAVE_ACCENT;
            case GLFW_KEY_ESCAPE: return Types::Codes::ESCAPE;
            case GLFW_KEY_ENTER: return Types::Codes::ENTER;
            case GLFW_KEY_TAB: return Types::Codes::TAB;
            case GLFW_KEY_BACKSPACE: return Types::Codes::BACKSLASH;
            case GLFW_KEY_INSERT: return Types::Codes::INSERT;
            case GLFW_KEY_DELETE: return Types::Codes::DELETE;
            case GLFW_KEY_RIGHT: return Types::Codes::RIGHT;
            case GLFW_KEY_LEFT: return Types::Codes::LEFT;
            case GLFW_KEY_DOWN: return Types::Codes::DOWN;
            case GLFW_KEY_UP: return Types::Codes::UP;
            case GLFW_KEY_PAGE_UP: return Types::Codes::PAGE_UP;
            case GLFW_KEY_PAGE_DOWN: return Types::Codes::PAGE_DOWN;
            case GLFW_KEY_HOME: return Types::Codes::HOME;
            case GLFW_KEY_END: return Types::Codes::END;
            case GLFW_KEY_CAPS_LOCK: return Types::Codes::CAPS_LOCK;
            case GLFW_KEY_SCROLL_LOCK: return Types::Codes::SCROLL_LOCK;
            case GLFW_KEY_NUM_LOCK: return Types::Codes::NUM_LOCK;
            case GLFW_KEY_PRINT_SCREEN: return Types::Codes::PRINT_SCREEN;
            case GLFW_KEY_PAUSE: return Types::Codes::PAUSE;
            case GLFW_KEY_F1: return Types::Codes::F1;
            case GLFW_KEY_F2: return Types::Codes::F2;
            case GLFW_KEY_F3: return Types::Codes::F3;
            case GLFW_KEY_F4: return Types::Codes::F4;
            case GLFW_KEY_F5: return Types::Codes::F5;
            case GLFW_KEY_F6: return Types::Codes::F6;
            case GLFW_KEY_F7: return Types::Codes::F7;
            case GLFW_KEY_F8: return Types::Codes::F8;
            case GLFW_KEY_F9: return Types::Codes::F9;
            case GLFW_KEY_F10: return Types::Codes::F10;
            case GLFW_KEY_F11: return Types::Codes::F11;
            case GLFW_KEY_F12: return Types::Codes::F12;
            case GLFW_KEY_F13: return Types::Codes::F13;
            case GLFW_KEY_F14: return Types::Codes::F14;
            case GLFW_KEY_F15: return Types::Codes::F15;
            case GLFW_KEY_F16: return Types::Codes::F16;
            case GLFW_KEY_F17: return Types::Codes::F17;
            case GLFW_KEY_F18: return Types::Codes::F18;
            case GLFW_KEY_F19: return Types::Codes::F19;
            case GLFW_KEY_F20: return Types::Codes::F20;
            case GLFW_KEY_F21: return Types::Codes::F21;
            case GLFW_KEY_F22: return Types::Codes::F22;
            case GLFW_KEY_F23: return Types::Codes::F23;
            case GLFW_KEY_F24: return Types::Codes::F24;
            case GLFW_KEY_F25: return Types::Codes::F25;
            case GLFW_KEY_KP_0: return Types::Codes::KP_0;
            case GLFW_KEY_KP_1: return Types::Codes::KP_1;
            case GLFW_KEY_KP_2: return Types::Codes::KP_2;
            case GLFW_KEY_KP_3: return Types::Codes::KP_3;
            case GLFW_KEY_KP_4: return Types::Codes::KP_4;
            case GLFW_KEY_KP_5: return Types::Codes::KP_5;
            case GLFW_KEY_KP_6: return Types::Codes::KP_6;
            case GLFW_KEY_KP_7: return Types::Codes::KP_7;
            case GLFW_KEY_KP_8: return Types::Codes::KP_8;
            case GLFW_KEY_KP_9: return Types::Codes::KP_9;
            case GLFW_KEY_KP_DECIMAL: return Types::Codes::KP_DECIMAL;
            case GLFW_KEY_KP_DIVIDE: return Types::Codes::KP_DIVIDE;
            case GLFW_KEY_KP_MULTIPLY: return Types::Codes::KP_MULTIPLY;
            case GLFW_KEY_KP_SUBTRACT: return Types::Codes::KP_SUBTRACT;
            case GLFW_KEY_KP_ADD: return Types::Codes::KP_ADD;
            case GLFW_KEY_KP_ENTER: return Types::Codes::KP_ENTER;
            case GLFW_KEY_KP_EQUAL: return Types::Codes::KP_EQUAL;
            case GLFW_KEY_LEFT_SHIFT: return Types::Codes::LEFT_SHIFT;
            case GLFW_KEY_LEFT_CONTROL: return Types::Codes::LEFT_CONTROL;
            case GLFW_KEY_LEFT_ALT: return Types::Codes::LEFT_ALT;
            case GLFW_KEY_LEFT_SUPER: return Types::Codes::LEFT_SUPER;
            case GLFW_KEY_RIGHT_SHIFT: return Types::Codes::RIGHT_SHIFT;
            case GLFW_KEY_RIGHT_CONTROL: return Types::Codes::RIGHT_CONTROL;
            case GLFW_KEY_RIGHT_ALT: return Types::Codes::RIGHT_ALT;
            case GLFW_KEY_RIGHT_SUPER: return Types::Codes::RIGHT_SUPER;
            case GLFW_KEY_MENU: return Types::Codes::MENU;
        }

        RAL_LOG_ERROR("Unknown glfw key code: %d", glfwKeyCode);
        return Types::Codes::ESCAPE;
    }
}
#endif //!RAL_WINDOWS