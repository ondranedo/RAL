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

#include <core/utility/Logger.h>

#ifndef RAL_ASSERTS_H
#define RAL_ASSERTS_H
#ifdef RAL_DEBUG

#ifdef _MSC_VER
#define RAL_ASSERT_BREAKPOINT __debugbreak()
#else
#define RAL_ASSERT_BREAKPOINT
#endif // !_MSC_VER

#define RAL_ASSERT_MSG_LENGTH 1024
    namespace RAL::asserts {
        template<typename... Agrs>
        void msg(const char* file, const int line, Agrs... args)
        {
            char buffer[RAL_ASSERT_MSG_LENGTH];
            snprintf(buffer, RAL_ASSERT_MSG_LENGTH, args...);
            RAL_LOG_FATAL("[ASSERT] FILE: [%s] LINE [%d] MSG [%s]", file, line, buffer);
        }
    }
    #define RAL_ASSERT(condition, ...) if (!(condition)) { RAL::asserts::msg(__FILE__, __LINE__, __VA_ARGS__); RAL_ASSERT_BREAKPOINT; }
    #define RAL_ASSERTR(condition, ret, ...) if (!(condition)) { RAL::asserts::msg(__FILE__, __LINE__, __VA_ARGS__); RAL_ASSERT_BREAKPOINT; return ret;}
    #define RAL_ASSERTRV(condition, ...) if (!(condition)) { RAL::asserts::msg(__FILE__, __LINE__, __VA_ARGS__); RAL_ASSERT_BREAKPOINT; return;}

#else
#define RAL_ASSERT(condition, ...)
#define RAL_ASSERTR(condition, ret, ...) if (!(condition)) {return ret;}
#define RAL_ASSERTRV(condition, ...) if (!(condition)) {return;}

#endif // !RAL_DEBUG
#endif //!RAL_ASSERTS_H