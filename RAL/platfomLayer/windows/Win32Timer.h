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
#ifndef RAL_PROJECT_WIN32TIMER_H
#define RAL_PROJECT_WIN32TIMER_H

#include <chrono>

namespace RAL::Win32
{
    class Win32Timer
    {
    public:
        enum class TimeUnit : unsigned char
        {
            SECOND ,
            MILLISECOND,
            MICROSECOND,
            NANOSECOND
        };

        enum class DateUnit : unsigned char
        {
            YEAR,
            MONTH,
            DAY,
            HOUR,
            MINUTE,
            SECOND
        };

        Win32Timer();

        void reset();
        std::string getSystemTime(DateUnit unit);
        double timeElapsedFromStart(TimeUnit unit);
        double timeElapsed(TimeUnit unit);

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_start,m_programStart, m_end;
        static std::chrono::duration<double, std::ratio<1>> getUnit(TimeUnit unit);
        std::tm *m_local_time;
    };
} // RAL

#endif //!RAL_PROJECT_WIN32TIMER_H