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

#include "Logger.h"
// TODO: Add custom output library
#include <iostream>

namespace RAL {
    namespace global{
        Logger mainLogger;
    }

    Logger::Logger() : m_msgQueue(), m_msgQueueSize(0),
#ifdef RAL_DEBUG
        m_level(LogMsg::Level::DEBUG)
#else
    m_level(LogMsg::Level::WARNING)
#endif
    {
    }

    Logger::~Logger() {
        print();
    }

    void Logger::print() {
        for(size_t i = 0; i < m_msgQueueSize; ++i)
        {
            LogMsg &msg = m_msgQueue[i];

            // TODO: Console output
            printf("%s\n", msg.m_buff);
        }
        m_msgQueueSize = 0;
    }

    void Logger::setLevel(LogMsg::Level level) {
        m_level = level;
    }
} // RAL
