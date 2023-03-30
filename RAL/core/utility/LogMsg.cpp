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

#include "LogMsg.h"

namespace RAL {
    const char* LogMsg::levelToString(Level level) {
        switch(level){
            case Level::DEBUG:  return "DEBUG";
            case Level::INFO:   return "INFO";
            case Level::WARNING:return "WARN";
            case Level::ERROR:  return "ERROR";
            case Level::FATAL:  return "FATAL";
            default:            return "UNKNOWN";
        }
    }
};
