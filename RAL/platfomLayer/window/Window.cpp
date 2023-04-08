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


#include "Window.h"

namespace RAL {
    Window::~Window() = default;
    Window::Window(const WindowSpec& spec) : m_spec(spec), m_eventCallback(nullptr), m_id(0) {}

    const WindowSpec &Window::getSpec() const {
        return m_spec;
    }

    void Window::setEventCallback(const EventManager::EventCallback &callback) {
        RAL_ASSERTRV(m_eventCallback == nullptr, "Event callback is already set!");
        m_eventCallback = callback;
        setCallbacks();
    }

    uint8_t Window::getId() const {
        return m_id;
    }
} // RAL