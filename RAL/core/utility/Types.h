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

#ifndef RAL_PROJECT_TYPES_H
#define RAL_PROJECT_TYPES_H
#include <core/memoryManager/Overload.h>
#include <string>
#include <cstdint>
#include <core/utility/Logger.h>

namespace RAL {
    namespace Types {
        enum class IOCode : uint16_t
        {
            //Mouse
            MBUTTON_1 = 0,
            MBUTTON_2 = 1,
            MBUTTON_3 = 2,
            MBUTTON_4 = 3,
            MBUTTON_5 = 4,
            MBUTTON_6 = 5,
            MBUTTON_7 = 6,
            MBUTTON_8 = 7,
            MBUTTON_LEFT = 8,
            MBUTTON_RIGHT = 9,
            MBUTTON_MIDDLE = 10,
            //Key
            SPACE = 32,
            APOSTROPHE = 39,  /* ' */
            COMMA = 44,  /* , */
            MINUS = 45,  /* - */
            PERIOD = 46,  /* . */
            SLASH = 47,  /* / */
            N0 = 48,
            N1 = 49,
            N2 = 50,
            N3 = 51,
            N4 = 52,
            N5 = 53,
            N6 = 54,
            N7 = 55,
            N8 = 56,
            N9 = 57,
            SEMICOLON = 59,  /* ; */
            EQUAL = 61,  /* = */
            A = 65,
            B = 66,
            C = 67,
            D = 68,
            E = 69,
            F = 70,
            G = 71,
            H = 72,
            I = 73,
            J = 74,
            K = 75,
            L = 76,
            M = 77,
            N = 78,
            O = 79,
            P = 80,
            Q = 81,
            R = 82,
            S = 83,
            T = 84,
            U = 85,
            V = 86,
            W = 87,
            X = 88,
            Y = 89,
            Z = 90,
            LEFT_BRACKET = 91,  /* [ */
            BACKSLASH = 92,  /* \ */
            RIGHT_BRACKET = 93,  /* ] */
            GRAVE_ACCENT = 96,  /* ` */
            ESCAPE = 256,
            ENTER = 257,
            TAB = 258,
            BACKSPACE = 259,
            INSERT = 260,
            DELETE = 261,
            RIGHT = 262,
            LEFT = 263,
            DOWN = 264,
            UP = 265,
            PAGE_UP = 266,
            PAGE_DOWN = 267,
            HOME = 268,
            END = 269,
            CAPS_LOCK = 280,
            SCROLL_LOCK = 281,
            NUM_LOCK = 282,
            PRINT_SCREEN = 283,
            PAUSE = 284,
            F1 = 290,
            F2 = 291,
            F3 = 292,
            F4 = 293,
            F5 = 294,
            F6 = 295,
            F7 = 296,
            F8 = 297,
            F9 = 298,
            F10 = 299,
            F11 = 300,
            F12 = 301,
            F13 = 302,
            F14 = 303,
            F15 = 304,
            F16 = 305,
            F17 = 306,
            F18 = 307,
            F19 = 308,
            F20 = 309,
            F21 = 310,
            F22 = 311,
            F23 = 312,
            F24 = 313,
            F25 = 314,
            KP_0 = 320,
            KP_1 = 321,
            KP_2 = 322,
            KP_3 = 323,
            KP_4 = 324,
            KP_5 = 325,
            KP_6 = 326,
            KP_7 = 327,
            KP_8 = 328,
            KP_9 = 329,
            KP_DECIMAL = 330,
            KP_DIVIDE = 331,
            KP_MULTIPLY = 332,
            KP_SUBTRACT = 333,
            KP_ADD = 334,
            KP_ENTER = 335,
            KP_EQUAL = 336,
            LEFT_SHIFT = 340,
            LEFT_CONTROL = 341,
            LEFT_ALT = 342,
            LEFT_SUPER = 343,
            RIGHT_SHIFT = 344,
            RIGHT_CONTROL = 345,
            RIGHT_ALT = 346,
            RIGHT_SUPER = 347,
            MENU = 348

        };

        enum class DataType : uint8_t {
            VOID,
            FLOAT,
            DOUBLE,
            INT8,
            INT16,
            INT32,
            INT64,
            UINT8,
            UINT16,
            UINT32,
            UINT64,
        };

        static std::string toString(IOCode code) {
            switch (code) {
                case IOCode::MBUTTON_1:
                    return "MOUSE_BUTTON_1";
                case IOCode::MBUTTON_2:
                    return "MOUSE_BUTTON_2";
                case IOCode::MBUTTON_3:
                    return "MOUSE_BUTTON_3";
                case IOCode::MBUTTON_4:
                    return "MOUSE_BUTTON_4";
                case IOCode::MBUTTON_5:
                    return "MOUSE_BUTTON_5";
                case IOCode::MBUTTON_6:
                    return "MOUSE_BUTTON_6";
                case IOCode::MBUTTON_7:
                    return "MOUSE_BUTTON_7";
                case IOCode::MBUTTON_8:
                    return "MOUSE_BUTTON_8";
                case IOCode::MBUTTON_LEFT:
                    return "MOUSE_BUTTON_LEFT";
                case IOCode::MBUTTON_RIGHT:
                    return "MOUSE_BUTTON_RIGHT";
                case IOCode::MBUTTON_MIDDLE :
                    return "MOUSE_BUTTON_MIDDLE";
                case IOCode::SPACE :
                    return "KEY_SPACE";
                case IOCode::APOSTROPHE :
                    return "KEY_APOSTROPHE";
                case IOCode::COMMA :
                    return "KEY_COMMA";
                case IOCode::MINUS :
                    return "KEY_MINUS";
                case IOCode::PERIOD:
                    return "KEY_PERIOD";
                case IOCode::SLASH :
                    return "KEY_SLASH";
                case IOCode::N0 :
                    return "KEY_0";
                case IOCode::N1 :
                    return "KEY_1";
                case IOCode::N2 :
                    return "KEY_2";
                case IOCode::N3 :
                    return "KEY_3";
                case IOCode::N4 :
                    return "KEY_4";
                case IOCode::N5 :
                    return "KEY_5";
                case IOCode::N6 :
                    return "KEY_6";
                case IOCode::N7 :
                    return "KEY_7";
                case IOCode::N8 :
                    return "KEY_8";
                case IOCode::N9 :
                    return "KEY_9";
                case IOCode::SEMICOLON :
                    return "KEY_SEMICOLON";
                case IOCode::EQUAL :
                    return "KEY_EQUAL";
                case IOCode::A :
                    return "KEY_A";
                case IOCode::B :
                    return "KEY_B";
                case IOCode::C :
                    return "KEY_C";
                case IOCode::D :
                    return "KEY_D";
                case IOCode::E :
                    return "KEY_E";
                case IOCode::F :
                    return "KEY_F";
                case IOCode::G :
                    return "KEY_G";
                case IOCode::H :
                    return "KEY_H";
                case IOCode::I :
                    return "KEY_I";
                case IOCode::J :
                    return "KEY_J";
                case IOCode::K :
                    return "KEY_K";
                case IOCode::L :
                    return "KEY_L";
                case IOCode::M :
                    return "KEY_M";
                case IOCode::N :
                    return "KEY_N";
                case IOCode::O :
                    return "KEY_O";
                case IOCode::P :
                    return "KEY_P";
                case IOCode::Q :
                    return "KEY_Q";
                case IOCode::R :
                    return "KEY_R";
                case IOCode::S :
                    return "KEY_S";
                case IOCode::T :
                    return "KEY_T";
                case IOCode::U :
                    return "KEY_U";
                case IOCode::V :
                    return "KEY_V";
                case IOCode::W :
                    return "KEY_W";
                case IOCode::X :
                    return "KEY_X";
                case IOCode::Y :
                    return "KEY_Y";
                case IOCode::Z :
                    return "KEY_Z";
                case IOCode::LEFT_BRACKET:
                    return "KEY_LEFT_BRACKET";
                case IOCode::BACKSLASH :
                    return "KEY_BACKSLASH";
                case IOCode::RIGHT_BRACKET :
                    return "KEY_RIGHT_BRACKET";
                case IOCode::GRAVE_ACCENT :
                    return "KEY_GRAVE_ACCENT";
                case IOCode::ESCAPE:
                    return "KEY_ESCAPE";
                case IOCode::ENTER:
                    return "KEY_ENTER";
                case IOCode::TAB:
                    return "KEY_TAB";
                case IOCode::BACKSPACE:
                    return "KEY_BACKSPACE";
                case IOCode::INSERT:
                    return "KEY_INSERT";
                case IOCode::DELETE:
                    return "KEY_DELETE";
                case IOCode::RIGHT:
                    return "KEY_RIGHT";
                case IOCode::LEFT:
                    return "KEY_LEFT";
                case IOCode::DOWN:
                    return "KEY_DOWN";
                case IOCode::UP:
                    return "KEY_UP";
                case IOCode::PAGE_UP:
                    return "KEY_PAGE_UP";
                case IOCode::PAGE_DOWN:
                    return "KEY_PAGE_DOWN";
                case IOCode::HOME:
                    return "KEY_HOME";
                case IOCode::END:
                    return "KEY_END";
                case IOCode::CAPS_LOCK:
                    return "KEY_CAPS_LOCK";
                case IOCode::SCROLL_LOCK:
                    return "KEY_SCROLL_LOCK";
                case IOCode::NUM_LOCK:
                    return "KEY_NUM_LOCK";
                case IOCode::PRINT_SCREEN:
                    return "KEY_PRINT_SCREEN";
                case IOCode::PAUSE:
                    return "KEY_PAUSE";
                case IOCode::F1:
                    return "KEY_F1";
                case IOCode::F2:
                    return "KEY_F2";
                case IOCode::F3:
                    return "KEY_F3";
                case IOCode::F4:
                    return "KEY_F4";
                case IOCode::F5:
                    return "KEY_F5";
                case IOCode::F6:
                    return "KEY_F6";
                case IOCode::F7:
                    return "KEY_F7";
                case IOCode::F8:
                    return "KEY_F8";
                case IOCode::F9:
                    return "KEY_F9";
                case IOCode::F10:
                    return "KEY_F10";
                case IOCode::F11:
                    return "KEY_F11";
                case IOCode::F12:
                    return "KEY_F12";
                case IOCode::F13:
                    return "KEY_F13";
                case IOCode::F14:
                    return "KEY_F14";
                case IOCode::F15:
                    return "KEY_F15";
                case IOCode::F16:
                    return "KEY_F16";
                case IOCode::F17:
                    return "KEY_F17";
                case IOCode::F18:
                    return "KEY_F18";
                case IOCode::F19:
                    return "KEY_F19";
                case IOCode::F20:
                    return "KEY_F20";
                case IOCode::F21:
                    return "KEY_F21";
                case IOCode::F22:
                    return "KEY_F22";
                case IOCode::F23:
                    return "KEY_F23";
                case IOCode::F24:
                    return "KEY_F24";
                case IOCode::F25:
                    return "KEY_F25";
                case IOCode::KP_0:
                    return "KEY_KP_0";
                case IOCode::KP_1:
                    return "KEY_KP_1";
                case IOCode::KP_2:
                    return "KEY_KP_2";
                case IOCode::KP_3:
                    return "KEY_KP_3";
                case IOCode::KP_4:
                    return "KEY_KP_4";
                case IOCode::KP_5:
                    return "KEY_KP_5";
                case IOCode::KP_6:
                    return "KEY_KP_6";
                case IOCode::KP_7:
                    return "KEY_KP_7";
                case IOCode::KP_8:
                    return "KEY_KP_8";
                case IOCode::KP_9:
                    return "KEY_KP_9";
                case IOCode::KP_DECIMAL:
                    return "KEY_KP_DECIMAL";
                case IOCode::KP_DIVIDE:
                    return "KEY_KP_DIVIDE";
                case IOCode::KP_MULTIPLY:
                    return "KEY_KP_MULTIPLY";
                case IOCode::KP_SUBTRACT:
                    return "KEY_KP_SUBTRACT";
                case IOCode::KP_ADD:
                    return "KEY_KP_ADD";
                case IOCode::KP_ENTER:
                    return "KEY_KP_ENTER";
                case IOCode::KP_EQUAL:
                    return "KEY_KP_EQUAL";
                case IOCode::LEFT_SHIFT:
                    return "KEY_LEFT_SHIFT";
                case IOCode::LEFT_CONTROL:
                    return "KEY_LEFT_CONTROL";
                case IOCode::LEFT_ALT:
                    return "KEY_LEFT_ALT";
                case IOCode::LEFT_SUPER:
                    return "KEY_LEFT_SUPER";
                case IOCode::RIGHT_SHIFT:
                    return "KEY_RIGHT_SHIFT";
                case IOCode::RIGHT_CONTROL:
                    return "KEY_RIGHT_CONTROL";
                case IOCode::RIGHT_ALT:
                    return "KEY_RIGHT_ALT";
                case IOCode::RIGHT_SUPER:
                    return "KEY_RIGHT_SUPER";
                case IOCode::MENU :
                    return "KEY_MENU";
            }

            RAL_LOG_ERROR("Unknown RAL key code");
            return "Unknown RAL key code";
        }

        static std::string toString(DataType code) {
            switch (code) {
                case DataType::VOID: return  "void";
                case DataType::FLOAT: return  "float";
                case DataType::DOUBLE: return "double";
                case DataType::INT8: return   "int8";
                case DataType::INT16: return  "int16";
                case DataType::INT32: return  "int32";
                case DataType::INT64: return  "int64";
                case DataType::UINT8: return  "uint8";
                case DataType::UINT16: return "uint16";
                case DataType::UINT32: return "uint32";
                case DataType::UINT64: return "uint64";
            }
            RAL_LOG_FATAL("Unknown RAL data type, when converting to string");
            return "Unknown";
        }

        static uint8_t size(DataType type) {
            switch (type) {
                case DataType::VOID: return 0;
                case DataType::FLOAT: return  sizeof(float);
                case DataType::DOUBLE: return sizeof(double);
                case DataType::INT8: return   sizeof(int8_t);
                case DataType::INT16: return  sizeof(int16_t);
                case DataType::INT32: return  sizeof(int32_t);
                case DataType::INT64: return  sizeof(int64_t);
                case DataType::UINT8: return  sizeof(uint8_t);
                case DataType::UINT16: return sizeof(uint16_t);
                case DataType::UINT32: return sizeof(uint32_t);
                case DataType::UINT64: return sizeof(uint64_t);
            }
            RAL_LOG_FATAL("Unknown RAL data type size");
            return 0;
        }
    }; // namespace Types
} // RAL

#endif //!RAL_PROJECT_TYPES_H
