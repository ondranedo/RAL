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

#include <core/memoryManager/Overload.h>
#include <cstdint>
#include <vector>
#include <string>
#include <renderer/renderingAPI/buffers/IndexBuffer.h>
#include <renderer/renderingAPI/buffers/VertexBuffer.h>

#include <platfomLayer/window/Window.h>
#include <renderer/renderingAPI/ProgramData.h>

namespace RAL
{
    // RenderingAPI is an abstract class that defines the interface for all rendering APIs.
    // It is used by the Renderer class to draw the scene to the screen.
    class RenderingAPI
    {
    public:
        RenderingAPI();
        virtual ~RenderingAPI();

        // Clears the screen with the clear colour
        // this function is called before each frame is drawn
        virtual void clear() = 0;

        // Can be used to set the clear colour, each value is in range 0-255.
        // Each frame will be cleared to this colour.
        void clearColour(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        // Can be used to set the clear colour, each value is in range 0-255.
        // Each frame will be cleared to this colour. Alpha value will be set to 0xFF.
        void clearColour(uint8_t r, uint8_t g, uint8_t b);

        // Can be used to set the clear colour to a hex value
        // you can use alpha value by using 0xRRGGBBAA, where AA is the alpha value
        // if you don't want to use alpha value, use 0xRRGGBB, where AA will be set to 0xFF
        void clearColour(uint32_t hex);

        // Crucial functions that must be called
        // before calling init, the window must be set using setWindow,
        // otherwise the engine will crash.
        virtual void init() = 0;

        // Release function is called when the engine is shutting down
        // it should release all resources that were allocated by the rendering API
        virtual void release() = 0;

        // draw function is called every frame, it should draw the scene to the screen
        // one draw call can draw multiple objects, but it can use only one shader.
        virtual void draw() = 0;

        // Bind functions are used to bind the buffers to the rendering API.
        // In other words, it sends the data from the buffers to the GPU.
        virtual void bind(const IndexBuffer& indexBuffer) = 0;

        // Bind functions are used to bind the buffers to the rendering API.
        // In other words, it sends the data from the buffers to the GPU.
        virtual void bind(const VertexBuffer& vertexBuffer) = 0;

        // Bounds the shader to the rendering API, there can be only one shader bound at a time.
        // Shader must be compiled before it can be bound. You have to call compileShader function.
        // Rendering API looks into the shader database to find the shader. If the shader is not found, it will crash.
        virtual void setProgram(uint16_t program) = 0;

        // This function is used to compile a shader, id of the shader is unique and is used to bind the shader.
        virtual void compileProgram(uint16_t id, const std::string& vertex, const std::string& fragment) = 0;

        // Send data to the shader that is currently bound, the data is sent to the uniform variable.
        // The data is sent to the shader that is currently bound.
        virtual void sendProgramData(const ProgramData& data) = 0;

        // Send data and custom data to the shader that is currently bound, the data is sent to the uniform variable.
        // The data is sent to the shader that is currently bound.
        virtual void sendProgramData(const ProgramData& data, const CustomProgramData& custom_data) = 0;

        // SetWindow function is used to set the window that will be drawn to.
        // This function must be called before init is called. When we change the window,
        // we must call clearWindow and then setWindow again.
        void setWindow(Window* window);

        // This function is called when the window is changed. It should release all resources
        // and stop drawing to the old window.
        void clearWindow();

    private:
        virtual void setWindowToDraw() = 0;
    protected:
        Window* m_window;
        std::array<uint8_t, 4> m_clearColour;
    };
} // RAL

#endif //!RAL_PROJECT_RENDERINGAPI_H
