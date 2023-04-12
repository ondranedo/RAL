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
#ifndef RAL_PROJECT_VERTEXBUFFER_H
#define RAL_PROJECT_VERTEXBUFFER_H

#include <renderer/renderingAPI/buffers/Buffer.h>
#include <renderer/renderingAPI/buffers/VertexBufferLayout.h>

namespace RAL
{
    // Vertex buffer is a buffer that stores vertex data
    // It is used to store data that is used to draw objects
    // data is transferred to GPU memory. Very important thing
    // is that vertex buffer holds layout of data that is stored
    // in it. Layout is used to tell GPU (shaders) how to interpret data
    // that is stored in vertex buffer.
    class VertexBuffer final : public Buffer
    {
    public:
        VertexBuffer(void* ptr, size_t size);
        VertexBuffer(void* ptr, size_t size, VertexBufferLayout &&layout);
        VertexBuffer();
        ~VertexBuffer() override;
        // Sets data to vertex buffer
        // [ptr] is pointer to data
        // [size] is size of data in bytes!
        void setData(void* ptr, size_t size);

        // Sets layout of data that is stored in vertex buffer
        // very important thing is that layout must be set
        void setLayout(const VertexBufferLayout &layout);
        void setLayout(VertexBufferLayout &&layout);
        [[nodiscard]] const VertexBufferLayout& getLayout() const;
    protected:
        VertexBufferLayout m_layout;
    };
};
#endif //!RAL_PROJECT_VERTEXBUFFER_H