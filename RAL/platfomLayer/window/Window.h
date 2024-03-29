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

#ifndef RAL_PROJECT_WINDOW_H
#define RAL_PROJECT_WINDOW_H

#include <core/baseClass/BaseComponent.h>
#include <core/memoryManager/MemoryManager.h>
#include <platfomLayer/window/WindowSpec.h>
#include <string>
#include <core/events/EventManager.h>

namespace RAL {
    class Window : public BaseComponent{
    public:
        typedef void* (*LoadProc)(const char *name);


        Window(const WindowSpec& spec);
        virtual ~Window();
        [[nodiscard]] const WindowSpec& getSpec() const;

        virtual void create() = 0;
        virtual void destroy() = 0;
        virtual void setDims(uint16_t width, uint16_t height) = 0;
        virtual void setTitle(const std::string& title) = 0;
        virtual void setVSync(bool state) = 0;
        [[nodiscard]] virtual bool getVSync() const = 0;
        virtual void makeContextCurrent() = 0;
        [[nodiscard]] uint8_t getId() const;
        void setEventCallback(const EventManager::EventCallback& callback);
        virtual void swapBuffers() = 0;
        virtual LoadProc getProcAddress() = 0;

    private:
        virtual void setCallbacks() = 0;

    protected:
        WindowSpec m_spec;
        EventManager::EventCallback m_eventCallback;

        // TODO: Window manager or some similar thing for supporting multiple windows
        uint8_t m_id;
        bool m_created;
    };
} // RAL

#endif //!RAL_PROJECT_WINDOW_H
