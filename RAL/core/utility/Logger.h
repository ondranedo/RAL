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

#ifndef RAL_LOGGER_H
#define RAL_LOGGER_H
#include <core/memoryManager/Overload.h>


/*
 *  & -> level [DEBU, INFO, WARN, ERRO, FATA]
 *  % -> message [c like format]
 */

// TODO: Add mutex lock / atomic locks
// TODO: Add direct log for debugging purposes
#include <core/utility/LogMsg.h>
// TODO: Add custom utility library
#include <cstring>
#include <cstdio>
#include <platfomLayer/consoleInterpreter/ConsoleInterpreter.h>

#ifdef RAL_DEBUG
#define RAL_LOG_MSG_QUEUE_SIZE 32    // DBG opt
#define RAL_LOG_MSG_QUEUE_GUARD 0x1C // DBG
#else
#define RAL_LOG_MSG_QUEUE_SIZE 24
#endif

namespace RAL {
    class Logger {
    public:
        Logger();
        ~Logger();
        void print();
        template<typename ...Args>
        void log(LogMsg::Level level, Args... args);
        void setLevel(LogMsg::Level level);
        void setConsoleInterpreter(ConsoleInterpreter* consoleInterpreter);

    private:
        template<typename ...Args>
        void printMsg(char* msgBuff, LogMsg::Level level, Args... args) const;

    private:
        ConsoleInterpreter* m_consoleInterpreter;
        LogMsg m_msgQueue[RAL_LOG_MSG_QUEUE_SIZE];
        const char* m_format = "[&] %";
        size_t m_msgQueueSize;
        LogMsg::Level m_level;
#ifdef RAL_DEBUG
        char& guardByte = m_msgQueue[m_msgQueueSize].m_buff[RAL_LOG_MSG_SIZE-1];
#endif
    };
    namespace global{
        extern Logger mainLogger;
    }

    template<typename... Args>
    void Logger::log(LogMsg::Level level, Args... args) {
        if(m_level > level) return;
        if(m_msgQueueSize >= RAL_LOG_MSG_QUEUE_SIZE - 1) print();
        m_msgQueue[m_msgQueueSize].m_level = level;
#ifdef RAL_DEBUG
        guardByte = RAL_LOG_MSG_QUEUE_GUARD; // DBG
#endif
        printMsg(m_msgQueue[m_msgQueueSize].m_buff, level, args...);
        m_msgQueueSize++;
#ifdef RAL_DEBUG
        if(guardByte != RAL_LOG_MSG_QUEUE_GUARD) // DBG
            log(LogMsg::Level::ERROR, "LogMsg buffer overflow, MSG too long, MSG may be corrupted!");
#endif
        if(level == RAL::LogMsg::Level::FATAL)
            print();
    }

    template<typename... Args>
    void Logger::printMsg(char* msgBuff, LogMsg::Level level, Args... args) const {
        size_t bytesWritten = 0;
        size_t formatLen = strlen(m_format);
        for(size_t i = 0; i < formatLen; ++i)
        {
            if(m_format[i] == '&')
                bytesWritten+= snprintf(msgBuff + bytesWritten, RAL_LOG_MSG_SIZE - bytesWritten, "%s", LogMsg::levelToString(level));
            else if(m_format[i] == '%')
                bytesWritten+= snprintf(msgBuff + bytesWritten, RAL_LOG_MSG_SIZE - bytesWritten, args...);
            else
                bytesWritten+= snprintf(msgBuff + bytesWritten, RAL_LOG_MSG_SIZE - bytesWritten, "%c", m_format[i]);
        }
        msgBuff[bytesWritten] = '\n';
        bytesWritten++;
        msgBuff[bytesWritten] = '\0';

    }
} // RAL

#ifdef RAL_DEBUG
#define RAL_LOG_DEBUG(...)  RAL::global::mainLogger.log(RAL::LogMsg::Level::DEBUG, __VA_ARGS__)
#define RAL_LOG_INFO(...)   RAL::global::mainLogger.log(RAL::LogMsg::Level::INFO, __VA_ARGS__)
#define RAL_LOG_WARNING(...)RAL::global::mainLogger.log(RAL::LogMsg::Level::WARNING, __VA_ARGS__)
#else
#define RAL_LOG_DEBUG(...)
#define RAL_LOG_INFO(...)
#define RAL_LOG_WARNING(...)
#endif //!RAL_DEBUG

#define RAL_LOG_ERROR(...)  RAL::global::mainLogger.log(RAL::LogMsg::Level::ERROR, __VA_ARGS__)
#define RAL_LOG_FATAL(...)  RAL::global::mainLogger.log(RAL::LogMsg::Level::FATAL, __VA_ARGS__)

#endif //!RAL_LOGGER_H
