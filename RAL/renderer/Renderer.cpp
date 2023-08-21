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

#include <core/memoryManager/Overload.h>
#include <renderer/renderingAPI/platform/openGL/GLRenderingAPI.h>

namespace RAL {
    RenderingAPI* Renderer::renderingAPI = nullptr;
    size_t Renderer::rendererCount = 0;

    Renderer::~Renderer()
    {
        // TODO: thread safety
        rendererCount--;
        if (rendererCount == 0) {
            delete renderingAPI;
            renderingAPI = nullptr;
        }
    }

    Renderer::Renderer() : m_window(nullptr) {
        // TODO: thread safety
        if (renderingAPI == nullptr && rendererCount == 0) {
            // TODO: change to different API
            renderingAPI = new GLRenderingAPI;
        }
        rendererCount++;
    };

    void Renderer::setWindow(Window *window) {
        if(m_window == nullptr){
            m_window = window;
            renderingAPI->setWindow(window);
            renderingAPI->init();
            return;
        }

        RAL_LOG_ERROR("Window is not nullptr");
    }
} // RAL
