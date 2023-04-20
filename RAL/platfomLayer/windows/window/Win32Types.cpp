//
// Created by matya on 20.04.2023.
//

#include "Win32Types.h"
#include <core/utility/Types.h>


namespace RAL
{
    namespace Win32
    {
        Types::Codes TranslateToRalTypes(WPARAM wParam)
        {
            switch(wParam)
            {
                case VK_LBUTTON: return Types::Codes::MBUTTON_1;
                case VK_RBUTTON: return Types::Codes::MBUTTON_2;
                case VK_MBUTTON: return Types::Codes::MBUTTON_3;
                case VK_XBUTTON1: return Types::Codes::MBUTTON_4;
                case VK_XBUTTON2: return Types::Codes::MBUTTON_5;
                case VK_SPACE: return Types::Codes::SPACE;
                case VK_OEM_3: return Types::Codes::APOSTROPHE;
                case VK_OEM_COMMA: return Types::Codes::COMMA;
                case VK_OEM_MINUS: return Types::Codes::MINUS;
                case VK_OEM_PERIOD: return Types::Codes::PERIOD;
                case VK_OEM_2: return Types::Codes::SLASH;
                case 0x30: return Types::Codes::N0;
                case 0x31: return Types::Codes::N1;
                case 0x32: return Types::Codes::N2;
                case 0x33: return Types::Codes::N3;
                case 0x34: return Types::Codes::N4;
                case 0x35: return Types::Codes::N5;
                case 0x36: return Types::Codes::N6;
                case 0x37: return Types::Codes::N7;
                case 0x38: return Types::Codes::N8;
                case 0x39: return Types::Codes::N9;
                case VK_OEM_1: return Types::Codes::SEMICOLON;
                case VK_OEM_PLUS: return Types::Codes::EQUAL;
                case 0x41: return Types::Codes::A;
                case 0x42: return Types::Codes::B;
                case 0x43: return Types::Codes::C;
                case 0x44: return Types::Codes::D;
                case 0x45: return Types::Codes::E;
                case 0x46: return Types::Codes::F;
                case 0x47: return Types::Codes::G;
                case 0x48: return Types::Codes::H;
                case 0x49: return Types::Codes::I;
                case 0x4A: return Types::Codes::J;
                case 0x4B: return Types::Codes::K;
                case 0x4C: return Types::Codes::L;
                case 0x4D: return Types::Codes::M;
                case 0x4E: return Types::Codes::N;
                case 0x4F: return Types::Codes::O;
                case 0x50: return Types::Codes::P;
                case 0x51: return Types::Codes::Q;
                case 0x52: return Types::Codes::R;
                case 0x53: return Types::Codes::S;
                case 0x54: return Types::Codes::T;
                case 0x55: return Types::Codes::U;
                case 0x56: return Types::Codes::V;
                case 0x57: return Types::Codes::W;
                case 0x58: return Types::Codes::X;
                case 0x59: return Types::Codes::Y;
                case 0x5A: return Types::Codes::Z;
                case VK_OEM_4: return Types::Codes::LEFT_BRACKET;
                case VK_OEM_5: return Types::Codes::BACKSLASH;
                case VK_OEM_6: return Types::Codes::RIGHT_BRACKET;
                    //case GLFW_KEY_GRAVE_ACCENT: return Types::Codes::GRAVE_ACCENT;
                case VK_ESCAPE: return Types::Codes::ESCAPE;
                case VK_RETURN: return Types::Codes::ENTER;
                case VK_TAB: return Types::Codes::TAB;
                case VK_BACK: return Types::Codes::BACKSLASH;
                case VK_INSERT: return Types::Codes::INSERT;
                    //case VK_DELETE: return Types::Codes::DELETE;
                case VK_RIGHT: return Types::Codes::RIGHT;
                case VK_LEFT: return Types::Codes::LEFT;
                case VK_DOWN: return Types::Codes::DOWN;
                case VK_UP: return Types::Codes::UP;
                case VK_PRIOR: return Types::Codes::PAGE_UP;
                case VK_NEXT: return Types::Codes::PAGE_DOWN;
                case VK_HOME: return Types::Codes::HOME;
                case VK_END: return Types::Codes::END;
                case VK_CAPITAL: return Types::Codes::CAPS_LOCK;
                    //case GLFW_KEY_SCROLL_LOCK: return Types::Codes::SCROLL_LOCK;
                case VK_NUMLOCK: return Types::Codes::NUM_LOCK;
                case VK_SNAPSHOT: return Types::Codes::PRINT_SCREEN;
                case VK_MEDIA_PLAY_PAUSE: return Types::Codes::PAUSE;
                case VK_F1: return Types::Codes::F1;
                case VK_F2: return Types::Codes::F2;
                case VK_F3: return Types::Codes::F3;
                case VK_F4: return Types::Codes::F4;
                case VK_F5: return Types::Codes::F5;
                case VK_F6: return Types::Codes::F6;
                case VK_F7: return Types::Codes::F7;
                case VK_F8: return Types::Codes::F8;
                case VK_F9: return Types::Codes::F9;
                case VK_F10: return Types::Codes::F10;
                case VK_F11: return Types::Codes::F11;
                case VK_F12: return Types::Codes::F12;
                case VK_F13: return Types::Codes::F13;
                case VK_F14: return Types::Codes::F14;
                case VK_F15: return Types::Codes::F15;
                case VK_F16: return Types::Codes::F16;
                case VK_F17: return Types::Codes::F17;
                case VK_F18: return Types::Codes::F18;
                case VK_F19: return Types::Codes::F19;
                case VK_F20: return Types::Codes::F20;
                case VK_F21: return Types::Codes::F21;
                case VK_F22: return Types::Codes::F22;
                case VK_F23: return Types::Codes::F23;
                case VK_F24: return Types::Codes::F24;
                    //case VK_F225: return Types::Codes::F25;
                    //case GLFW_KEY_KP_0: return Types::Codes::KP_0;
                    //case GLFW_KEY_KP_1: return Types::Codes::KP_1;
                    //case GLFW_KEY_KP_2: return Types::Codes::KP_2;
                    //case GLFW_KEY_KP_3: return Types::Codes::KP_3;
                    // case GLFW_KEY_KP_4: return Types::Codes::KP_4;
                    //case GLFW_KEY_KP_5: return Types::Codes::KP_5;
                    //case GLFW_KEY_KP_6: return Types::Codes::KP_6;
                    //case GLFW_KEY_KP_7: return Types::Codes::KP_7;
                    //case GLFW_KEY_KP_8: return Types::Codes::KP_8;
                    //case GLFW_KEY_KP_9: return Types::Codes::KP_9;
                case VK_DECIMAL: return Types::Codes::KP_DECIMAL;
                case VK_DIVIDE: return Types::Codes::KP_DIVIDE;
                case VK_MULTIPLY: return Types::Codes::KP_MULTIPLY;
                case VK_SUBTRACT: return Types::Codes::KP_SUBTRACT;
                case VK_ADD: return Types::Codes::KP_ADD;
                    //case GLFW_KEY_KP_ENTER: return Types::Codes::KP_ENTER;
                    //case GLFW_KEY_KP_EQUAL: return Types::Codes::KP_EQUAL;
                case VK_LSHIFT: return Types::Codes::LEFT_SHIFT;
                case VK_LCONTROL: return Types::Codes::LEFT_CONTROL;
                case VK_LMENU: return Types::Codes::LEFT_ALT;
                case VK_LWIN: return Types::Codes::LEFT_SUPER;
                case VK_RSHIFT: return Types::Codes::RIGHT_SHIFT;
                case VK_RCONTROL: return Types::Codes::RIGHT_CONTROL;
                case VK_RMENU: return Types::Codes::RIGHT_ALT;
                case VK_RWIN: return Types::Codes::RIGHT_SUPER;
                case VK_APPS: return Types::Codes::MENU;

            }
            //RAL_LOG_ERROR("Unknown Win32 key code: ");
            return Types::Codes::ESCAPE;
        }
    }
}