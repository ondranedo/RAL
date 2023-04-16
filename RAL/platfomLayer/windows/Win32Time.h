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
#ifndef RAL_PROJECT_WIN32TIME_H
#define RAL_PROJECT_WIN32TIME_H

#include <chrono>

namespace RAL::Win32
    {
        class Win32Time
        {
        public:
            Win32Time();
            void reset();
            float timeElapsed();
            double timeElapsedMilliSeconds();
            [[nodiscard]] float getSeconds() const;
            [[nodiscard]] double getMilliSeconds() const;
        private:
            double m_time;
            static double getTime();
            std::chrono::time_point<std::chrono::high_resolution_clock> m_start,m_end;
        };
    } // RAL

#endif //!RAL_PROJECT_WIN32TIME_H