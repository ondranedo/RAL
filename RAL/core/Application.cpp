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


#include "Application.h"
#include <core/utility/Logger.h>


namespace RAL {
    Application::Application() {
        RAL_LOG_DEBUG("Application created");
    }

    Application::~Application() {
        RAL_LOG_DEBUG("Application destroyed");
    }

    void Application::run() {
        RAL_LOG_DEBUG("Application running");
        RAL_LOG_DEBUG("Debug");
        RAL_LOG_INFO("Info");
        RAL_LOG_WARNING("Warning");
        RAL_LOG_ERROR("Error");
        RAL_LOG_FATAL("Fatal");
    }
} // RAL