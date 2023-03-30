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


#ifndef RAL_PROJECT_LOGMSG_H
#define RAL_PROJECT_LOGMSG_H
#include <core/memoryManager/Overload.h>

#define RAL_LOG_MSG_SIZE 256

namespace RAL{
    struct LogMsg{
        enum class Level{
            DEBUG,
            INFO,
            WARNING,
            ERROR,
            FATAL
        } m_level;
        char m_buff[RAL_LOG_MSG_SIZE];
        // TODO: MSG Time
        LogMsg():m_buff{0}, m_level(Level::DEBUG){}
        static const char* levelToString(Level level);
    };
}

#endif //!RAL_PROJECT_LOGMSG_H