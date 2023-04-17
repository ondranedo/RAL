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
#include "Win32Timer.h"
#include <core/memoryManager/Overload.h>

namespace RAL::Win32
{
    Win32Timer::Win32Timer() : m_local_time{nullptr}
    {
        reset();
    }

    double Win32Timer::timeElapsed(TimeUnit unit)
    {
        m_end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::duration<double>>(m_end - m_start).count() /
               getUnit(unit).count();
    }

    void Win32Timer::reset()
    {
        m_start = std::chrono::high_resolution_clock::now();
    }

    double Win32Timer::timeElapsedFromStart(Win32Timer::TimeUnit unit)
    {
        m_end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::duration<double>>(m_end - m_programStart).count() /
               getUnit(unit).count();
    }

    std::chrono::duration<double, std::ratio<1>> Win32Timer::getUnit(Win32Timer::TimeUnit unit)
    {
        switch (unit)
        {
            case TimeUnit::SECOND:
                return std::chrono::duration<double>(1);
            case TimeUnit::MILLISECOND:
                return std::chrono::duration<double, std::milli>(1);
            case TimeUnit::MICROSECOND:
                return std::chrono::duration<double, std::micro>(1);
            case TimeUnit::NANOSECOND:
                return std::chrono::duration<double, std::nano>(1);
        }
    }

    std::string Win32Timer::getSystemTime(Win32Timer::DateUnit unit)
    {
        std::string temp;
        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);
        m_local_time = std::localtime(&time);
        switch (unit)
        {
            case DateUnit::YEAR:
                temp += std::to_string(m_local_time->tm_year+1900);
                return temp;
            case DateUnit::MONTH:
                temp += std::to_string(m_local_time->tm_mon+1);
                return temp;
            case DateUnit::DAY:
                temp += std::to_string(m_local_time->tm_mday);
                return temp;
            case DateUnit::HOUR:
                temp += std::to_string(m_local_time->tm_hour);
                return temp;
            case DateUnit::MINUTE:
                temp += std::to_string(m_local_time->tm_min);
                return temp;
            case DateUnit::SECOND:
                temp += std::to_string(m_local_time->tm_sec);
                return temp;
        }
    }

} // RAL