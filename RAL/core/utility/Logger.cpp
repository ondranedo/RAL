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
#include <core/utility/Asserts.h>

namespace RAL {
    static ConsoleInterpreter::ColourForeground colourForegroundArray[5] = {
            ConsoleInterpreter::ColourForeground::WHITE,
            ConsoleInterpreter::ColourForeground::GREEN,
            ConsoleInterpreter::ColourForeground::YELLOW,
            ConsoleInterpreter::ColourForeground::RED,
            ConsoleInterpreter::ColourForeground::LIGHTMAGENTA
    };

    namespace global{
        Logger mainLogger;
    }

    Logger::Logger() : m_msgQueue(), m_msgQueueSize(0), m_consoleInterpreter(nullptr), m_logLoop(false),
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
        std::lock_guard<std::mutex> lock(m_mutex);
        for(size_t i = 0; i < m_msgQueueSize; ++i)
        {
            LogMsg &msg = m_msgQueue[i];

            if(m_consoleInterpreter) {
                m_consoleInterpreter->log("\xB3");
                m_consoleInterpreter->log(msg.m_buff,colourForegroundArray[static_cast<uint8_t>(msg.m_level)]);
            }
            else
                printf("%s", msg.m_buff);
        }
        m_msgQueueSize = 0;
    }

    void Logger::setLevel(LogMsg::Level level) {
        m_level = level;
    }

    void Logger::setConsoleInterpreter(ConsoleInterpreter *consoleInterpreter) {
        std::lock_guard<std::mutex> lock(m_mutex);
        RAL_ASSERT(m_consoleInterpreter == nullptr, "Console interpreter is not nullptr");
        RAL_ASSERTRV(consoleInterpreter != nullptr, "Console interpreter is nullptr");
        m_consoleInterpreter = consoleInterpreter;
    }

    void Logger::detachConsoleInterpreter() {
        std::lock_guard<std::mutex> lock(m_mutex);
        RAL_ASSERT(m_consoleInterpreter != nullptr, "Console interpreter is nullptr");
        m_consoleInterpreter = nullptr;
    }

    void Logger::endLogLoop() {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_logLoop = false;
    }

    void Logger::startLogLoop() {
        m_logLoop = true;
        while(m_logLoop)
            print();
    }
} // RAL
