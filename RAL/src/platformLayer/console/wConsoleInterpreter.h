#pragma once


#include "consoleInterpreter.h"

#ifdef RAL_WINDOWS

#include <windows.h>

namespace RAL
{
    class WConsoleInterpreter final : public ConsoleInterpreter
    {
    public:
        WConsoleInterpreter();

        ~WConsoleInterpreter() override;

        void setTitle(const RAL::String &title) override;
        void log(const RAL::String &msg, ColourBackground background, ColourForeground text) override;
        void log(const RAL::String &msg, ColourForeground text, ColourBackground background) override;
        void log(const RAL::String &msg) override;
        void clear() override;
        void pause() override;
        void unpause() override;

        void init() override;
        void release() override;

    private:
        bool m_pause = false;
        HANDLE console;
        CONSOLE_SCREEN_BUFFER_INFO screen{};
        DWORD written{}, mode{}, count{};
        COORD topLeft = {0, 0};
        INPUT_RECORD input{};
    };
};

#endif