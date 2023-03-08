#include "wConsoleInterpreter.h"

#ifdef RAL_WINDOWS
#include <iostream>

namespace RAL {
    WConsoleInterpreter::WConsoleInterpreter() {
        FreeConsole();
        AllocConsole();
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        freopen_s((FILE **) stdout, "CONOUT$", "w", stdout);
        freopen_s((FILE **) stderr, "CONOUT$", "w", stderr);
        freopen_s((FILE **) stdin, "CONIN$", "r", stdin);
        RAL_LOG_DEBUG("Console constructed on Windows platform");
    }

    WConsoleInterpreter::~WConsoleInterpreter() {
        FreeConsole();
    }

    void WConsoleInterpreter::setTitle(const RAL::String &title) {
        SetConsoleTitle(title.c_str());
    }

    void WConsoleInterpreter::log(const RAL::String &msg, RAL::ConsoleInterpreter::ColourBackground background,
                       RAL::ConsoleInterpreter::ColourForeground text) {
        SetConsoleTextAttribute(console, background | text);
        printf("%s\n", msg.c_str());
    }

    void WConsoleInterpreter::log(const RAL::String &msg, RAL::ConsoleInterpreter::ColourForeground text,
                       RAL::ConsoleInterpreter::ColourBackground background) {
        SetConsoleTextAttribute(console, text | background);
        printf("%s\n", msg.c_str());
    }

    void WConsoleInterpreter::log(const RAL::String &msg) {
        SetConsoleTextAttribute(console, RAL::ConsoleInterpreter::ColourBackground::BLACK |
                                         RAL::ConsoleInterpreter::ColourForeground::WHITE);
        printf("%s\n", msg.c_str());
    }

    void WConsoleInterpreter::clear() {
        GetConsoleScreenBufferInfo(console, &screen);
        FillConsoleOutputCharacterA(
                console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        FillConsoleOutputAttribute(
                console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
                screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        SetConsoleCursorPosition(console, topLeft);
    }

    void WConsoleInterpreter::pause() {
        SetConsoleTextAttribute(console, RAL::ConsoleInterpreter::ColourBackground::BLACK |
                                         RAL::ConsoleInterpreter::ColourForeground::LIGHTRED);
        printf("Console paused! Press any key to continue");
        std::cin.get();
    }
}
#endif