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


#include "Types.h"

#include <core/utility/Logger.h>
namespace RAL {
    std::string Types::toString(Types::Codes code) {
        switch (code) {
            case Types::Codes::MBUTTON_1: return "MOUSE_BUTTON_1";
            case Types::Codes::MBUTTON_2: return "MOUSE_BUTTON_2";
            case Types::Codes::MBUTTON_3: return "MOUSE_BUTTON_3";
            case Types::Codes::MBUTTON_4: return "MOUSE_BUTTON_4";
            case Types::Codes::MBUTTON_5: return "MOUSE_BUTTON_5";
            case Types::Codes::MBUTTON_6: return "MOUSE_BUTTON_6";
            case Types::Codes::MBUTTON_7: return "MOUSE_BUTTON_7";
            case Types::Codes::MBUTTON_8: return "MOUSE_BUTTON_8";
            case Types::Codes::MBUTTON_LEFT: return "MOUSE_BUTTON_LEFT";
            case Types::Codes::MBUTTON_RIGHT: return "MOUSE_BUTTON_RIGHT";
            case Types::Codes::MBUTTON_MIDDLE : return "MOUSE_BUTTON_MIDDLE";
            case Types::Codes::SPACE : return "KEY_SPACE";
            case Types::Codes::APOSTROPHE : return "KEY_APOSTROPHE";
            case Types::Codes::COMMA : return "KEY_COMMA";
            case Types::Codes::MINUS : return "KEY_MINUS";
            case Types::Codes::PERIOD: return "KEY_PERIOD";
            case Types::Codes::SLASH : return "KEY_SLASH";
            case Types::Codes::N0 : return "KEY_0";
            case Types::Codes::N1 : return "KEY_1";
            case Types::Codes::N2 : return "KEY_2";
            case Types::Codes::N3 : return "KEY_3";
            case Types::Codes::N4 : return "KEY_4";
            case Types::Codes::N5 : return "KEY_5";
            case Types::Codes::N6 : return "KEY_6";
            case Types::Codes::N7 : return "KEY_7";
            case Types::Codes::N8 : return "KEY_8";
            case Types::Codes::N9 : return "KEY_9";
            case Types::Codes::SEMICOLON : return "KEY_SEMICOLON";
            case Types::Codes::EQUAL : return "KEY_EQUAL";
            case Types::Codes::A : return "KEY_A";
            case Types::Codes::B : return "KEY_B";
            case Types::Codes::C : return "KEY_C";
            case Types::Codes::D : return "KEY_D";
            case Types::Codes::E : return "KEY_E";
            case Types::Codes::F : return "KEY_F";
            case Types::Codes::G : return "KEY_G";
            case Types::Codes::H : return "KEY_H";
            case Types::Codes::I : return "KEY_I";
            case Types::Codes::J : return "KEY_J";
            case Types::Codes::K : return "KEY_K";
            case Types::Codes::L : return "KEY_L";
            case Types::Codes::M : return "KEY_M";
            case Types::Codes::N : return "KEY_N";
            case Types::Codes::O : return "KEY_O";
            case Types::Codes::P : return "KEY_P";
            case Types::Codes::Q : return "KEY_Q";
            case Types::Codes::R : return "KEY_R";
            case Types::Codes::S : return "KEY_S";
            case Types::Codes::T : return "KEY_T";
            case Types::Codes::U : return "KEY_U";
            case Types::Codes::V : return "KEY_V";
            case Types::Codes::W : return "KEY_W";
            case Types::Codes::X : return "KEY_X";
            case Types::Codes::Y : return "KEY_Y";
            case Types::Codes::Z : return "KEY_Z";
            case Types::Codes::LEFT_BRACKET: return "KEY_LEFT_BRACKET";
            case Types::Codes::BACKSLASH : return "KEY_BACKSLASH";
            case Types::Codes::RIGHT_BRACKET : return "KEY_RIGHT_BRACKET";
            case Types::Codes::GRAVE_ACCENT : return "KEY_GRAVE_ACCENT";
            case Types::Codes::ESCAPE: return "KEY_ESCAPE";
            case Types::Codes::ENTER: return "KEY_ENTER";
            case Types::Codes::TAB: return "KEY_TAB";
            case Types::Codes::BACKSPACE: return "KEY_BACKSPACE";
            case Types::Codes::INSERT: return "KEY_INSERT";
            case Types::Codes::DELETE: return "KEY_DELETE";
            case Types::Codes::RIGHT: return "KEY_RIGHT";
            case Types::Codes::LEFT: return "KEY_LEFT";
            case Types::Codes::DOWN: return "KEY_DOWN";
            case Types::Codes::UP: return "KEY_UP";
            case Types::Codes::PAGE_UP: return "KEY_PAGE_UP";
            case Types::Codes::PAGE_DOWN: return "KEY_PAGE_DOWN";
            case Types::Codes::HOME: return "KEY_HOME";
            case Types::Codes::END: return "KEY_END";
            case Types::Codes::CAPS_LOCK: return "KEY_CAPS_LOCK";
            case Types::Codes::SCROLL_LOCK: return "KEY_SCROLL_LOCK";
            case Types::Codes::NUM_LOCK: return "KEY_NUM_LOCK";
            case Types::Codes::PRINT_SCREEN: return "KEY_PRINT_SCREEN";
            case Types::Codes::PAUSE: return "KEY_PAUSE";
            case Types::Codes::F1: return "KEY_F1";
            case Types::Codes::F2: return "KEY_F2";
            case Types::Codes::F3: return "KEY_F3";
            case Types::Codes::F4: return "KEY_F4";
            case Types::Codes::F5: return "KEY_F5";
            case Types::Codes::F6: return "KEY_F6";
            case Types::Codes::F7: return "KEY_F7";
            case Types::Codes::F8: return "KEY_F8";
            case Types::Codes::F9: return "KEY_F9";
            case Types::Codes::F10: return "KEY_F10";
            case Types::Codes::F11: return "KEY_F11";
            case Types::Codes::F12: return "KEY_F12";
            case Types::Codes::F13: return "KEY_F13";
            case Types::Codes::F14: return "KEY_F14";
            case Types::Codes::F15: return "KEY_F15";
            case Types::Codes::F16: return "KEY_F16";
            case Types::Codes::F17: return "KEY_F17";
            case Types::Codes::F18: return "KEY_F18";
            case Types::Codes::F19: return "KEY_F19";
            case Types::Codes::F20: return "KEY_F20";
            case Types::Codes::F21: return "KEY_F21";
            case Types::Codes::F22: return "KEY_F22";
            case Types::Codes::F23: return "KEY_F23";
            case Types::Codes::F24: return "KEY_F24";
            case Types::Codes::F25: return "KEY_F25";
            case Types::Codes::KP_0: return "KEY_KP_0";
            case Types::Codes::KP_1: return "KEY_KP_1";
            case Types::Codes::KP_2: return "KEY_KP_2";
            case Types::Codes::KP_3: return "KEY_KP_3";
            case Types::Codes::KP_4: return "KEY_KP_4";
            case Types::Codes::KP_5: return "KEY_KP_5";
            case Types::Codes::KP_6: return "KEY_KP_6";
            case Types::Codes::KP_7: return "KEY_KP_7";
            case Types::Codes::KP_8: return "KEY_KP_8";
            case Types::Codes::KP_9: return "KEY_KP_9";
            case Types::Codes::KP_DECIMAL: return "KEY_KP_DECIMAL";
            case Types::Codes::KP_DIVIDE: return "KEY_KP_DIVIDE";
            case Types::Codes::KP_MULTIPLY: return "KEY_KP_MULTIPLY";
            case Types::Codes::KP_SUBTRACT: return "KEY_KP_SUBTRACT";
            case Types::Codes::KP_ADD: return "KEY_KP_ADD";
            case Types::Codes::KP_ENTER: return "KEY_KP_ENTER";
            case Types::Codes::KP_EQUAL: return "KEY_KP_EQUAL";
            case Types::Codes::LEFT_SHIFT: return "KEY_LEFT_SHIFT";
            case Types::Codes::LEFT_CONTROL: return "KEY_LEFT_CONTROL";
            case Types::Codes::LEFT_ALT: return "KEY_LEFT_ALT";
            case Types::Codes::LEFT_SUPER: return "KEY_LEFT_SUPER";
            case Types::Codes::RIGHT_SHIFT: return "KEY_RIGHT_SHIFT";
            case Types::Codes::RIGHT_CONTROL: return "KEY_RIGHT_CONTROL";
            case Types::Codes::RIGHT_ALT: return "KEY_RIGHT_ALT";
            case Types::Codes::RIGHT_SUPER: return "KEY_RIGHT_SUPER";
            case Types::Codes::MENU : return "KEY_MENU";
        }

        RAL_LOG_ERROR("Unknown key code");
        return "Unknown key code";
    }
} // RAL