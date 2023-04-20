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
#include "RenderingAPI.h"

namespace RAL {
    RenderingAPI::RenderingAPI() :
    m_window(nullptr),
    m_clearColour({255,0,255,255}) // Vivid magenta
    {}

    RenderingAPI::~RenderingAPI() = default;

    void RenderingAPI::setWindow(Window *window) {
        if(!m_window)
        {
            m_window = window;
            setWindowToDraw();
        }
        else
        {
            RAL_LOG_WARNING("Window already set, ignoring new window, call clearWindow() to clear window");
        }
    }

    void RenderingAPI::clearWindow() {
        m_window = nullptr;
    }

    void RenderingAPI::clearColour(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_clearColour = {r, g, b, a}; }
    void RenderingAPI::clearColour(uint8_t r, uint8_t g, uint8_t b) { clearColour(r, g, b, 255); }
    void RenderingAPI::clearColour(uint32_t hex) {
        auto unm = [](uint32_t hex_value, uint8_t shift) -> uint8_t {
            return (hex_value >> (shift * 8)) & 0xFF;
        };
        if(hex > 0xFFFFFF) clearColour(unm(hex, 3),
                                        unm(hex, 2),
                                        unm(hex, 1),
                                        unm(hex, 0));
        else               clearColour(unm(hex, 2),
                                       unm(hex, 1),
                                       unm(hex, 0),
                                       0xFF);
    }
} // RAL
