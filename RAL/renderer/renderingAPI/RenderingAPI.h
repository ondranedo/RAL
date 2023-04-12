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
#ifndef RAL_PROJECT_RENDERINGAPI_H
#define RAL_PROJECT_RENDERINGAPI_H

#include <cstdint>
#include <renderer/renderingAPI/buffers/IndexBuffer.h>
#include <renderer/renderingAPI/buffers/VertexBuffer.h>

#include <platfomLayer/window/Window.h>

namespace RAL
{
    // RenderingAPI is an abstract class that defines the interface for all rendering APIs.
    // It is used by the Renderer class to draw the scene to the screen.
    class RenderingAPI
    {
    public:
        RenderingAPI();
        virtual ~RenderingAPI();

        virtual void clear() = 0;
        void clearColour(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        void clearColour(uint8_t r, uint8_t g, uint8_t b);
        // can be used to set the clear colour to a hex value
        // you can use alpha value by using 0xRRGGBBAA, where AA is the alpha value
        // if you don't want to use alpha value, use 0xRRGGBB, where AA will be set to 0xFF
        void clearColour(uint32_t hex);

        virtual void init() = 0;
        virtual void release() = 0;

        virtual void draw() = 0;

        virtual void bind(const IndexBuffer& indexBuffer) = 0;
        virtual void bind(const VertexBuffer& vertexBuffer) = 0;

        void setWindow(Window* window);
        void clearWindow();

    private:
        virtual void setWindowToDraw() = 0;
    protected:
        Window* m_window;
        std::array<uint8_t, 4> m_clearColour;
    };
} // RAL

#endif //!RAL_PROJECT_RENDERINGAPI_H
