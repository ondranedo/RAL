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

#ifndef RAL_PROJECT_WIN32GLFW_H
#define RAL_PROJECT_WIN32GLFW_H
#ifdef RAL_WINDOWS

#include <cstdint>

namespace RAL::Win32 {
    class Win32GLFW {
    public:
        Win32GLFW();
        ~Win32GLFW();
        void init();
        void release();
        void setVSync(bool state);
        [[nodiscard]] bool getVSync() const;

    private:
        uint8_t m_windowCount;
        bool m_isVSync;
    };

    namespace global {
        extern Win32GLFW glfw;
    }
} // RAL
#endif //!RAL_WINDOWS
#endif //!RAL_PROJECT_WIN32GLFW_H
