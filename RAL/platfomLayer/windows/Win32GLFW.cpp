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

    Types::IOCode Win32GLFW::getCode(uint16_t glfwKeyCode) {
        switch (glfwKeyCode) {
            case GLFW_MOUSE_BUTTON_1: return Types::IOCode::MBUTTON_1;
            case GLFW_MOUSE_BUTTON_2: return Types::IOCode::MBUTTON_2;
            case GLFW_MOUSE_BUTTON_3: return Types::IOCode::MBUTTON_3;
            case GLFW_MOUSE_BUTTON_4: return Types::IOCode::MBUTTON_4;
            case GLFW_MOUSE_BUTTON_5: return Types::IOCode::MBUTTON_5;
            case GLFW_MOUSE_BUTTON_6: return Types::IOCode::MBUTTON_6;
            case GLFW_MOUSE_BUTTON_7: return Types::IOCode::MBUTTON_7;
            case GLFW_MOUSE_BUTTON_8: return Types::IOCode::MBUTTON_8;
            case GLFW_KEY_SPACE: return Types::IOCode::SPACE;
            case GLFW_KEY_APOSTROPHE: return Types::IOCode::APOSTROPHE;
            case GLFW_KEY_COMMA: return Types::IOCode::COMMA;
            case GLFW_KEY_MINUS: return Types::IOCode::MINUS;
            case GLFW_KEY_PERIOD: return Types::IOCode::PERIOD;
            case GLFW_KEY_SLASH: return Types::IOCode::SLASH;
            case GLFW_KEY_0: return Types::IOCode::N0;
            case GLFW_KEY_1: return Types::IOCode::N1;
            case GLFW_KEY_2: return Types::IOCode::N2;
            case GLFW_KEY_3: return Types::IOCode::N3;
            case GLFW_KEY_4: return Types::IOCode::N4;
            case GLFW_KEY_5: return Types::IOCode::N5;
            case GLFW_KEY_6: return Types::IOCode::N6;
            case GLFW_KEY_7: return Types::IOCode::N7;
            case GLFW_KEY_8: return Types::IOCode::N8;
            case GLFW_KEY_9: return Types::IOCode::N9;
            case GLFW_KEY_SEMICOLON: return Types::IOCode::SEMICOLON;
            case GLFW_KEY_EQUAL: return Types::IOCode::EQUAL;
            case GLFW_KEY_A: return Types::IOCode::A;
            case GLFW_KEY_B: return Types::IOCode::B;
            case GLFW_KEY_C: return Types::IOCode::C;
            case GLFW_KEY_D: return Types::IOCode::D;
            case GLFW_KEY_E: return Types::IOCode::E;
            case GLFW_KEY_F: return Types::IOCode::F;
            case GLFW_KEY_G: return Types::IOCode::G;
            case GLFW_KEY_H: return Types::IOCode::H;
            case GLFW_KEY_I: return Types::IOCode::I;
            case GLFW_KEY_J: return Types::IOCode::J;
            case GLFW_KEY_K: return Types::IOCode::K;
            case GLFW_KEY_L: return Types::IOCode::L;
            case GLFW_KEY_M: return Types::IOCode::M;
            case GLFW_KEY_N: return Types::IOCode::N;
            case GLFW_KEY_O: return Types::IOCode::O;
            case GLFW_KEY_P: return Types::IOCode::P;
            case GLFW_KEY_Q: return Types::IOCode::Q;
            case GLFW_KEY_R: return Types::IOCode::R;
            case GLFW_KEY_S: return Types::IOCode::S;
            case GLFW_KEY_T: return Types::IOCode::T;
            case GLFW_KEY_U: return Types::IOCode::U;
            case GLFW_KEY_V: return Types::IOCode::V;
            case GLFW_KEY_W: return Types::IOCode::W;
            case GLFW_KEY_X: return Types::IOCode::X;
            case GLFW_KEY_Y: return Types::IOCode::Y;
            case GLFW_KEY_Z: return Types::IOCode::Z;
            case GLFW_KEY_LEFT_BRACKET: return Types::IOCode::LEFT_BRACKET;
            case GLFW_KEY_BACKSLASH: return Types::IOCode::BACKSLASH;
            case GLFW_KEY_RIGHT_BRACKET: return Types::IOCode::RIGHT_BRACKET;
            case GLFW_KEY_GRAVE_ACCENT: return Types::IOCode::GRAVE_ACCENT;
            case GLFW_KEY_ESCAPE: return Types::IOCode::ESCAPE;
            case GLFW_KEY_ENTER: return Types::IOCode::ENTER;
            case GLFW_KEY_TAB: return Types::IOCode::TAB;
            case GLFW_KEY_BACKSPACE: return Types::IOCode::BACKSLASH;
            case GLFW_KEY_INSERT: return Types::IOCode::INSERT;
            case GLFW_KEY_DELETE: return Types::IOCode::DELETE;
            case GLFW_KEY_RIGHT: return Types::IOCode::RIGHT;
            case GLFW_KEY_LEFT: return Types::IOCode::LEFT;
            case GLFW_KEY_DOWN: return Types::IOCode::DOWN;
            case GLFW_KEY_UP: return Types::IOCode::UP;
            case GLFW_KEY_PAGE_UP: return Types::IOCode::PAGE_UP;
            case GLFW_KEY_PAGE_DOWN: return Types::IOCode::PAGE_DOWN;
            case GLFW_KEY_HOME: return Types::IOCode::HOME;
            case GLFW_KEY_END: return Types::IOCode::END;
            case GLFW_KEY_CAPS_LOCK: return Types::IOCode::CAPS_LOCK;
            case GLFW_KEY_SCROLL_LOCK: return Types::IOCode::SCROLL_LOCK;
            case GLFW_KEY_NUM_LOCK: return Types::IOCode::NUM_LOCK;
            case GLFW_KEY_PRINT_SCREEN: return Types::IOCode::PRINT_SCREEN;
            case GLFW_KEY_PAUSE: return Types::IOCode::PAUSE;
            case GLFW_KEY_F1: return Types::IOCode::F1;
            case GLFW_KEY_F2: return Types::IOCode::F2;
            case GLFW_KEY_F3: return Types::IOCode::F3;
            case GLFW_KEY_F4: return Types::IOCode::F4;
            case GLFW_KEY_F5: return Types::IOCode::F5;
            case GLFW_KEY_F6: return Types::IOCode::F6;
            case GLFW_KEY_F7: return Types::IOCode::F7;
            case GLFW_KEY_F8: return Types::IOCode::F8;
            case GLFW_KEY_F9: return Types::IOCode::F9;
            case GLFW_KEY_F10: return Types::IOCode::F10;
            case GLFW_KEY_F11: return Types::IOCode::F11;
            case GLFW_KEY_F12: return Types::IOCode::F12;
            case GLFW_KEY_F13: return Types::IOCode::F13;
            case GLFW_KEY_F14: return Types::IOCode::F14;
            case GLFW_KEY_F15: return Types::IOCode::F15;
            case GLFW_KEY_F16: return Types::IOCode::F16;
            case GLFW_KEY_F17: return Types::IOCode::F17;
            case GLFW_KEY_F18: return Types::IOCode::F18;
            case GLFW_KEY_F19: return Types::IOCode::F19;
            case GLFW_KEY_F20: return Types::IOCode::F20;
            case GLFW_KEY_F21: return Types::IOCode::F21;
            case GLFW_KEY_F22: return Types::IOCode::F22;
            case GLFW_KEY_F23: return Types::IOCode::F23;
            case GLFW_KEY_F24: return Types::IOCode::F24;
            case GLFW_KEY_F25: return Types::IOCode::F25;
            case GLFW_KEY_KP_0: return Types::IOCode::KP_0;
            case GLFW_KEY_KP_1: return Types::IOCode::KP_1;
            case GLFW_KEY_KP_2: return Types::IOCode::KP_2;
            case GLFW_KEY_KP_3: return Types::IOCode::KP_3;
            case GLFW_KEY_KP_4: return Types::IOCode::KP_4;
            case GLFW_KEY_KP_5: return Types::IOCode::KP_5;
            case GLFW_KEY_KP_6: return Types::IOCode::KP_6;
            case GLFW_KEY_KP_7: return Types::IOCode::KP_7;
            case GLFW_KEY_KP_8: return Types::IOCode::KP_8;
            case GLFW_KEY_KP_9: return Types::IOCode::KP_9;
            case GLFW_KEY_KP_DECIMAL: return Types::IOCode::KP_DECIMAL;
            case GLFW_KEY_KP_DIVIDE: return Types::IOCode::KP_DIVIDE;
            case GLFW_KEY_KP_MULTIPLY: return Types::IOCode::KP_MULTIPLY;
            case GLFW_KEY_KP_SUBTRACT: return Types::IOCode::KP_SUBTRACT;
            case GLFW_KEY_KP_ADD: return Types::IOCode::KP_ADD;
            case GLFW_KEY_KP_ENTER: return Types::IOCode::KP_ENTER;
            case GLFW_KEY_KP_EQUAL: return Types::IOCode::KP_EQUAL;
            case GLFW_KEY_LEFT_SHIFT: return Types::IOCode::LEFT_SHIFT;
            case GLFW_KEY_LEFT_CONTROL: return Types::IOCode::LEFT_CONTROL;
            case GLFW_KEY_LEFT_ALT: return Types::IOCode::LEFT_ALT;
            case GLFW_KEY_LEFT_SUPER: return Types::IOCode::LEFT_SUPER;
            case GLFW_KEY_RIGHT_SHIFT: return Types::IOCode::RIGHT_SHIFT;
            case GLFW_KEY_RIGHT_CONTROL: return Types::IOCode::RIGHT_CONTROL;
            case GLFW_KEY_RIGHT_ALT: return Types::IOCode::RIGHT_ALT;
            case GLFW_KEY_RIGHT_SUPER: return Types::IOCode::RIGHT_SUPER;
            case GLFW_KEY_MENU: return Types::IOCode::MENU;
        }

        RAL_LOG_ERROR("Unknown glfw key code: %d", glfwKeyCode);
        return Types::IOCode::ESCAPE;
    }
}
#endif //!RAL_WINDOWS