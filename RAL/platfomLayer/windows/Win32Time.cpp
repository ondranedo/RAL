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
#include "Win32Time.h"

#include <Windows.h>

namespace RAL::Win32
{
    Win32Time::Win32Time() : m_time(getTime())
    {
        reset();
    }

    float Win32Time::timeElapsed()
    {
        m_end = std::chrono::high_resolution_clock::now();
        return static_cast<float>(std::chrono::duration_cast<std::chrono::seconds>(m_end - m_start).count());
    }

    double Win32Time::timeElapsedMilliSeconds()
    {
        m_end = std::chrono::high_resolution_clock::now();
        return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count());
    }

    float Win32Time::getSeconds() const
    {
        return static_cast<float>(m_time);
    }

    double Win32Time::getMilliSeconds() const
    {
        return m_time * 1000.0f;
    }

    void Win32Time::reset()
    {
        m_start = std::chrono::high_resolution_clock::now();
    }

    double Win32Time::getTime()
    {
        static LARGE_INTEGER startTime = {0};
        static LARGE_INTEGER frequency = {0};

        // Initialize the frequency of the performance counter
        if (frequency.QuadPart == 0)
        {
            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&startTime);
        }

        // Get the current time
        LARGE_INTEGER currentTime;
        QueryPerformanceCounter(&currentTime);

        // Calculate the elapsed time in seconds
        double elapsedTime = static_cast<double>(currentTime.QuadPart - startTime.QuadPart) /
                             static_cast<double>(frequency.QuadPart);

        return elapsedTime;
    }

} // RAL