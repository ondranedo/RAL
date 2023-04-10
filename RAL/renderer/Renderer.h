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

// TODO: Remove this, when scene is implemented
#include <renderer/renderingAPI/buffers/VertexBuffer.h>
#include <renderer/renderingAPI/buffers/IndexBuffer.h>
#include <renderer/renderingAPI/buffers/BufferLayout.h>
#include <renderer/renderingAPI/RenderingAPI.h>

namespace RAL {
    class Renderer : public BaseComponent {
    public:
        enum class RendererAPI {
            OpenGL
        };

        struct RenderSpec {
            uint16_t width;
            uint16_t height;
            RenderSpec();
        };
    public:
        explicit Renderer(const RendererAPI &rendererAPI = RendererAPI::OpenGL);
        virtual ~Renderer();

        void setToWindow(Window *window);
        void detachWindow();
        void setRenderSpec(const RenderSpec& spec);

        virtual void renderLoop() = 0;
        virtual void addData(VertexBuffer* vertex, IndexBuffer* index) = 0;

    protected:
        RendererAPI m_rendererAPI;
        RenderSpec m_renderSpec;
        Window* m_window;
        RenderingAPI* m_renderingAPI;
    };
} // RAL

#endif //!RAL_PROJECT_RENDERER_H
