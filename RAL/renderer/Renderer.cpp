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
#include "Renderer.h"

namespace RAL {
    Renderer::RenderSpec::RenderSpec() : width(0), height(0) {}

    Renderer::Renderer(const Renderer::RendererAPI &rendererAPI) : m_rendererAPI(rendererAPI), m_window(nullptr),
                                                                   m_renderSpec(RenderSpec()) {}

    Renderer::~Renderer() {
        if(m_window != nullptr) detachWindow();
    }

    void Renderer::setToWindow(Window *window) {
        RAL_ASSERTRV(window != nullptr, "Window is nullptr, when setting renderer to window");
        RAL_ASSERTRV(m_window == nullptr, "Window is already set to renderer");
        m_window = window;
    }

    void Renderer::detachWindow() {
        RAL_ASSERTRV(m_window != nullptr, "Window is already detached from renderer");
        m_window = nullptr;
    }

    void Renderer::setRenderSpec(const Renderer::RenderSpec &spec) {
        m_renderSpec = spec;
    }
} // RAL
