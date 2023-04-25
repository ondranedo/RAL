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
#ifndef RAL_PROJECT_RENDERER_H
#define RAL_PROJECT_RENDERER_H

#include <platfomLayer/window/Window.h>
#include <renderer/renderingAPI/RenderingAPI.h>
namespace RAL {
    class Renderer : public BaseComponent {
    public:
        virtual ~Renderer();
        Renderer();

        virtual void setWindow(Window* window);
        virtual void renderLoop() = 0;

    private:
        Window* m_window;
        static RenderingAPI* renderingAPI;
        static size_t rendererCount;
    };
} // RAL

#endif //!RAL_PROJECT_RENDERER_H
