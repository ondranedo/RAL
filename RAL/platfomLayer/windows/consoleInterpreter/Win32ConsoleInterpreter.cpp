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

#ifdef RAL_WINDOWS

#include <core/utility/Asserts.h>
#include "Win32ConsoleInterpreter.h"

namespace RAL::Win32 {
    Win32ConsoleInterpreter::Win32ConsoleInterpreter() :
            m_consoleHandle(0),
            m_bytesWrittten(0) {
    }

    Win32ConsoleInterpreter::~Win32ConsoleInterpreter() = default;

    void Win32ConsoleInterpreter::log(const char* msg, RAL::ConsoleInterpreter::ColourForeground text,
                                           RAL::ConsoleInterpreter::ColourBackground background) {
        RAL_ASSERTRV(m_consoleHandle != 0, "Console handle is not initialized")
        SetConsoleTextAttribute(m_consoleHandle, background | text);
        WriteConsole(m_consoleHandle, msg, strlen(msg)+1, &m_bytesWrittten, NULL);
        SetConsoleTextAttribute(m_consoleHandle, ColourBackground::BLACK | ColourForeground::WHITE);
    }

    void
    Win32ConsoleInterpreter::log(const char* msg, RAL::ConsoleInterpreter::ColourBackground background) {
        log(msg, ColourForeground::WHITE, background);
    }

    void Win32ConsoleInterpreter::log(const char* msg, RAL::ConsoleInterpreter::ColourForeground text) {
        log(msg, text, ColourBackground::BLACK);
    }

    void Win32ConsoleInterpreter::log(const char* msg) {
        log(msg, ColourForeground::WHITE, ColourBackground::BLACK);
    }

    void Win32ConsoleInterpreter::setTitle(const char* title) {
        SetConsoleTitle(title);
    }

    void Win32ConsoleInterpreter::clear() {
        RAL_ASSERTRV(m_consoleHandle != 0, "Console handle is not initialized")
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(m_consoleHandle, &csbi);
        DWORD count = csbi.dwSize.X * csbi.dwSize.Y;
        FillConsoleOutputAttribute(m_consoleHandle, ' ', count, {0, 0}, &m_bytesWrittten);
        FillConsoleOutputAttribute(m_consoleHandle, csbi.wAttributes, count, {0, 0}, &m_bytesWrittten);
        SetConsoleCursorPosition(m_consoleHandle, {0, 0});
    }

    void Win32ConsoleInterpreter::init() {
        FreeConsole();
        if (!AllocConsole()) {
            MessageBox(NULL, "Failed to allocate console", "RAL - Error", MB_OK | MB_ICONERROR);
            return;
        }
        m_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        freopen("CONIN$", "r", stdin);
    }

    void Win32ConsoleInterpreter::release() {
        FreeConsole();
    }

    void Win32ConsoleInterpreter::update() {

    }
};

#endif //!RAL_WINDOWS