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
    std::string Types::toString(Types::IOCode code) {
        switch (code) {
            case Types::IOCode::MBUTTON_1: return "MOUSE_BUTTON_1";
            case Types::IOCode::MBUTTON_2: return "MOUSE_BUTTON_2";
            case Types::IOCode::MBUTTON_3: return "MOUSE_BUTTON_3";
            case Types::IOCode::MBUTTON_4: return "MOUSE_BUTTON_4";
            case Types::IOCode::MBUTTON_5: return "MOUSE_BUTTON_5";
            case Types::IOCode::MBUTTON_6: return "MOUSE_BUTTON_6";
            case Types::IOCode::MBUTTON_7: return "MOUSE_BUTTON_7";
            case Types::IOCode::MBUTTON_8: return "MOUSE_BUTTON_8";
            case Types::IOCode::MBUTTON_LEFT: return "MOUSE_BUTTON_LEFT";
            case Types::IOCode::MBUTTON_RIGHT: return "MOUSE_BUTTON_RIGHT";
            case Types::IOCode::MBUTTON_MIDDLE : return "MOUSE_BUTTON_MIDDLE";
            case Types::IOCode::SPACE : return "KEY_SPACE";
            case Types::IOCode::APOSTROPHE : return "KEY_APOSTROPHE";
            case Types::IOCode::COMMA : return "KEY_COMMA";
            case Types::IOCode::MINUS : return "KEY_MINUS";
            case Types::IOCode::PERIOD: return "KEY_PERIOD";
            case Types::IOCode::SLASH : return "KEY_SLASH";
            case Types::IOCode::N0 : return "KEY_0";
            case Types::IOCode::N1 : return "KEY_1";
            case Types::IOCode::N2 : return "KEY_2";
            case Types::IOCode::N3 : return "KEY_3";
            case Types::IOCode::N4 : return "KEY_4";
            case Types::IOCode::N5 : return "KEY_5";
            case Types::IOCode::N6 : return "KEY_6";
            case Types::IOCode::N7 : return "KEY_7";
            case Types::IOCode::N8 : return "KEY_8";
            case Types::IOCode::N9 : return "KEY_9";
            case Types::IOCode::SEMICOLON : return "KEY_SEMICOLON";
            case Types::IOCode::EQUAL : return "KEY_EQUAL";
            case Types::IOCode::A : return "KEY_A";
            case Types::IOCode::B : return "KEY_B";
            case Types::IOCode::C : return "KEY_C";
            case Types::IOCode::D : return "KEY_D";
            case Types::IOCode::E : return "KEY_E";
            case Types::IOCode::F : return "KEY_F";
            case Types::IOCode::G : return "KEY_G";
            case Types::IOCode::H : return "KEY_H";
            case Types::IOCode::I : return "KEY_I";
            case Types::IOCode::J : return "KEY_J";
            case Types::IOCode::K : return "KEY_K";
            case Types::IOCode::L : return "KEY_L";
            case Types::IOCode::M : return "KEY_M";
            case Types::IOCode::N : return "KEY_N";
            case Types::IOCode::O : return "KEY_O";
            case Types::IOCode::P : return "KEY_P";
            case Types::IOCode::Q : return "KEY_Q";
            case Types::IOCode::R : return "KEY_R";
            case Types::IOCode::S : return "KEY_S";
            case Types::IOCode::T : return "KEY_T";
            case Types::IOCode::U : return "KEY_U";
            case Types::IOCode::V : return "KEY_V";
            case Types::IOCode::W : return "KEY_W";
            case Types::IOCode::X : return "KEY_X";
            case Types::IOCode::Y : return "KEY_Y";
            case Types::IOCode::Z : return "KEY_Z";
            case Types::IOCode::LEFT_BRACKET: return "KEY_LEFT_BRACKET";
            case Types::IOCode::BACKSLASH : return "KEY_BACKSLASH";
            case Types::IOCode::RIGHT_BRACKET : return "KEY_RIGHT_BRACKET";
            case Types::IOCode::GRAVE_ACCENT : return "KEY_GRAVE_ACCENT";
            case Types::IOCode::ESCAPE: return "KEY_ESCAPE";
            case Types::IOCode::ENTER: return "KEY_ENTER";
            case Types::IOCode::TAB: return "KEY_TAB";
            case Types::IOCode::BACKSPACE: return "KEY_BACKSPACE";
            case Types::IOCode::INSERT: return "KEY_INSERT";
            case Types::IOCode::DELETE: return "KEY_DELETE";
            case Types::IOCode::RIGHT: return "KEY_RIGHT";
            case Types::IOCode::LEFT: return "KEY_LEFT";
            case Types::IOCode::DOWN: return "KEY_DOWN";
            case Types::IOCode::UP: return "KEY_UP";
            case Types::IOCode::PAGE_UP: return "KEY_PAGE_UP";
            case Types::IOCode::PAGE_DOWN: return "KEY_PAGE_DOWN";
            case Types::IOCode::HOME: return "KEY_HOME";
            case Types::IOCode::END: return "KEY_END";
            case Types::IOCode::CAPS_LOCK: return "KEY_CAPS_LOCK";
            case Types::IOCode::SCROLL_LOCK: return "KEY_SCROLL_LOCK";
            case Types::IOCode::NUM_LOCK: return "KEY_NUM_LOCK";
            case Types::IOCode::PRINT_SCREEN: return "KEY_PRINT_SCREEN";
            case Types::IOCode::PAUSE: return "KEY_PAUSE";
            case Types::IOCode::F1: return "KEY_F1";
            case Types::IOCode::F2: return "KEY_F2";
            case Types::IOCode::F3: return "KEY_F3";
            case Types::IOCode::F4: return "KEY_F4";
            case Types::IOCode::F5: return "KEY_F5";
            case Types::IOCode::F6: return "KEY_F6";
            case Types::IOCode::F7: return "KEY_F7";
            case Types::IOCode::F8: return "KEY_F8";
            case Types::IOCode::F9: return "KEY_F9";
            case Types::IOCode::F10: return "KEY_F10";
            case Types::IOCode::F11: return "KEY_F11";
            case Types::IOCode::F12: return "KEY_F12";
            case Types::IOCode::F13: return "KEY_F13";
            case Types::IOCode::F14: return "KEY_F14";
            case Types::IOCode::F15: return "KEY_F15";
            case Types::IOCode::F16: return "KEY_F16";
            case Types::IOCode::F17: return "KEY_F17";
            case Types::IOCode::F18: return "KEY_F18";
            case Types::IOCode::F19: return "KEY_F19";
            case Types::IOCode::F20: return "KEY_F20";
            case Types::IOCode::F21: return "KEY_F21";
            case Types::IOCode::F22: return "KEY_F22";
            case Types::IOCode::F23: return "KEY_F23";
            case Types::IOCode::F24: return "KEY_F24";
            case Types::IOCode::F25: return "KEY_F25";
            case Types::IOCode::KP_0: return "KEY_KP_0";
            case Types::IOCode::KP_1: return "KEY_KP_1";
            case Types::IOCode::KP_2: return "KEY_KP_2";
            case Types::IOCode::KP_3: return "KEY_KP_3";
            case Types::IOCode::KP_4: return "KEY_KP_4";
            case Types::IOCode::KP_5: return "KEY_KP_5";
            case Types::IOCode::KP_6: return "KEY_KP_6";
            case Types::IOCode::KP_7: return "KEY_KP_7";
            case Types::IOCode::KP_8: return "KEY_KP_8";
            case Types::IOCode::KP_9: return "KEY_KP_9";
            case Types::IOCode::KP_DECIMAL: return "KEY_KP_DECIMAL";
            case Types::IOCode::KP_DIVIDE: return "KEY_KP_DIVIDE";
            case Types::IOCode::KP_MULTIPLY: return "KEY_KP_MULTIPLY";
            case Types::IOCode::KP_SUBTRACT: return "KEY_KP_SUBTRACT";
            case Types::IOCode::KP_ADD: return "KEY_KP_ADD";
            case Types::IOCode::KP_ENTER: return "KEY_KP_ENTER";
            case Types::IOCode::KP_EQUAL: return "KEY_KP_EQUAL";
            case Types::IOCode::LEFT_SHIFT: return "KEY_LEFT_SHIFT";
            case Types::IOCode::LEFT_CONTROL: return "KEY_LEFT_CONTROL";
            case Types::IOCode::LEFT_ALT: return "KEY_LEFT_ALT";
            case Types::IOCode::LEFT_SUPER: return "KEY_LEFT_SUPER";
            case Types::IOCode::RIGHT_SHIFT: return "KEY_RIGHT_SHIFT";
            case Types::IOCode::RIGHT_CONTROL: return "KEY_RIGHT_CONTROL";
            case Types::IOCode::RIGHT_ALT: return "KEY_RIGHT_ALT";
            case Types::IOCode::RIGHT_SUPER: return "KEY_RIGHT_SUPER";
            case Types::IOCode::MENU : return "KEY_MENU";
        }

        RAL_LOG_ERROR("Unknown RAL key code");
        return "Unknown RAL key code";
    }

    std::string Types::toString(Types::DataType code) {
        switch (code) {
            case Types::DataType::VOID: return  "void";
            case Types::DataType::FLOAT: return  "float";
            case Types::DataType::DOUBLE: return "double";
            case Types::DataType::INT8: return   "int8";
            case Types::DataType::INT16: return  "int16";
            case Types::DataType::INT32: return  "int32";
            case Types::DataType::INT64: return  "int64";
            case Types::DataType::UINT8: return  "uint8";
            case Types::DataType::UINT16: return "uint16";
            case Types::DataType::UINT32: return "uint32";
            case Types::DataType::UINT64: return "uint64";
        }
        RAL_LOG_FATAL("Unknown RAL data type, when converting to string");
        return "Unknown";
    }

    uint8_t Types::size(Types::DataType type) {
        switch (type) {
            case Types::DataType::VOID: return 0;
            case Types::DataType::FLOAT: return  sizeof(float);
            case Types::DataType::DOUBLE: return sizeof(double);
            case Types::DataType::INT8: return   sizeof(int8_t);
            case Types::DataType::INT16: return  sizeof(int16_t);
            case Types::DataType::INT32: return  sizeof(int32_t);
            case Types::DataType::INT64: return  sizeof(int64_t);
            case Types::DataType::UINT8: return  sizeof(uint8_t);
            case Types::DataType::UINT16: return sizeof(uint16_t);
            case Types::DataType::UINT32: return sizeof(uint32_t);
            case Types::DataType::UINT64: return sizeof(uint64_t);
        }
        RAL_LOG_FATAL("Unknown RAL data type size");
        return 0;
    }
} // RAL