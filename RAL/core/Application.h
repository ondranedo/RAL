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

#ifndef RAL_PROJECT_APPLICATION_H
#define RAL_PROJECT_APPLICATION_H

#include <core/events/Event.h>
#include <core/baseClass/BaseGame.h>
#include <platfomLayer/consoleInterpreter/ConsoleInterpreter.h>
#include <core/FCM/FCM.h>

namespace RAL {
    class Application {
    public:
        struct ConstructInfo {
            MemoryManager* memory;
            ConsoleInterpreter* consoleInterpreter;
        };

        Application(const ConstructInfo& info);
        ~Application();
        void run();
        void onEvent(Event* event);

        void inti();
        void release();

    private:
        FCM m_fcm;
    };
}; // RAL

#endif //!RAL_PROJECT_APPLICATION_H
