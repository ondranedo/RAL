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
#include "Renderer2D.h"
#include <core/utility/Asserts.h>

namespace RAL {
    void Renderer2D::render()
    {
        setData();
    }

    void Renderer2D::renderLoop()
    {
        RAL_ASSERT(m_Window != nullptr, "Window is not selected");
        if(m_Data.vertecies.size() == 0 || m_Data.indecies.size() == 0) RAL_LOG_WARNING("Data not set");
        render();
    }

    void Renderer2D::setWindow(Window *window)
    {
        m_Window = window;
    }

    void Renderer2D::setData()
    {
        /*TODO: Scene scene = Scene::getScene();
            *Get indecies and vertecies from scene*
                RendererAPI::setVertexBuffer(...);
                RendererAPI::setIndexBuffer(...);
         */
    }

} // RAL