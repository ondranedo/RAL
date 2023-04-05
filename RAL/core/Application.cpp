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

#include <core/layers/LayerManagerFactory.h>

namespace RAL {
    Application::Application() {
        RAL_LOG_DEBUG("Engine initialization started");

        RAL_LOG_DEBUG("Engine initialization ended");
    }

    Application::~Application() {
        RAL_LOG_DEBUG("Engine release started");

        RAL_LOG_DEBUG("Engine release ended");
    }

    void Application::onEvent(Event *event) {
        RAL_LOG_DEBUG("Engine received event");
    }

    void Application::run() {
        RAL_LOG_INFO("Engine starting!");

    }
} // RAL