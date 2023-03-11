#include "wConsoleInterpreter.h"

#ifdef RAL_WINDOWS

#include "../../core/logger.h"
#include <iostream>

namespace RAL
{
    WConsoleInterpreter::WConsoleInterpreter()
    {

    }

    WConsoleInterpreter::~WConsoleInterpreter()
    {

    }

    void WConsoleInterpreter::setTitle(const RAL::String &title)
    {
        SetConsoleTitle(title.c_str());
    }

    void WConsoleInterpreter::log(const RAL::String &msg, RAL::ConsoleInterpreter::ColourBackground background,
                                  RAL::ConsoleInterpreter::ColourForeground text)
    {
        if (m_pause == FALSE)
        {
            SetConsoleTextAttribute(m_console, background | text);
            printf("%s\n", msg.c_str());
        }
    }

    void WConsoleInterpreter::log(const RAL::String &msg, RAL::ConsoleInterpreter::ColourForeground text,
                                  RAL::ConsoleInterpreter::ColourBackground background)
    {
        if (m_pause == FALSE)
        {
            SetConsoleTextAttribute(m_console, text | background);
            printf("%s\n", msg.c_str());
        }
    }

    void WConsoleInterpreter::log(const RAL::String &msg)
    {
        if (m_pause == FALSE)
        {
            SetConsoleTextAttribute(m_console, RAL::ConsoleInterpreter::ColourBackground::BLACK |
                                             RAL::ConsoleInterpreter::ColourForeground::WHITE);
            printf("%s\n", msg.c_str());
        }
    }

    void WConsoleInterpreter::clear()
    {
        GetConsoleScreenBufferInfo(m_console, &m_screen);
        FillConsoleOutputCharacterA(
                m_console, ' ', m_screen.dwSize.X * m_screen.dwSize.Y, m_topLeft, &m_written
        );
        FillConsoleOutputAttribute(
                m_console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
                m_screen.dwSize.X * m_screen.dwSize.Y, m_topLeft, &m_written
        );
        SetConsoleCursorPosition(m_console, m_topLeft);
    }

    void WConsoleInterpreter::pause()
    {
        m_pause = TRUE;
        SetConsoleTextAttribute(m_console, RAL::ConsoleInterpreter::ColourBackground::BLACK |
                                         RAL::ConsoleInterpreter::ColourForeground::LIGHTRED);
        printf("Console paused!\n");
    }

    void WConsoleInterpreter::unpause()
    {
        m_pause = FALSE;
        SetConsoleTextAttribute(m_console, RAL::ConsoleInterpreter::ColourBackground::BLACK |
                                         RAL::ConsoleInterpreter::ColourForeground::LIGHTRED);
        printf("Console unpaused!\n");
    }

    void WConsoleInterpreter::init()
    {
        FreeConsole();
        AllocConsole();
        m_console = GetStdHandle(STD_OUTPUT_HANDLE);
        freopen_s((FILE **) stdout, "CONOUT$", "w", stdout);
        freopen_s((FILE **) stderr, "CONOUT$", "w", stderr);
        freopen_s((FILE **) stdin, "CONIN$", "r", stdin);
        RAL_LOG_DEBUG("Console constructed on Windows platform");
    }

    void WConsoleInterpreter::release()
    {
        FreeConsole();
    }
}
#endif