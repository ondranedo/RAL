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

#ifndef RAL_PROJECT_WIN32CONSOLEINTERPRETER_H
#define RAL_PROJECT_WIN32CONSOLEINTERPRETER_H
#ifdef RAL_WINDOWS

#include <string>
#include <platfomLayer/consoleInterpreter/ConsoleInterpreter.h>
#include <windows.h>

namespace RAL::Win32 {
    class Win32ConsoleInterpreter final : public ConsoleInterpreter {
    public:
        Win32ConsoleInterpreter();
        ~Win32ConsoleInterpreter() override;

        void log(const char* msg, ColourForeground text, ColourBackground background) override;
        void log(const char* msg, ColourBackground background) override;
        void log(const char* msg, ColourForeground text) override;
        void log(const char* msg) override;

        void setTitle(const char* title) override;

        void clear() override;

        void init() override;
        void release() override;
        void update() override;

    private:
        HANDLE m_consoleHandle;
        DWORD m_bytesWrittten;
    };
};

#endif // RAL_WINDOWS
#endif //!RAL_PROJECT_WIN32CONSOLEINTERPRETER_H
