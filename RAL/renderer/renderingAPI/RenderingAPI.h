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

namespace RAL
{
    class RenderingAPI
    {
    public:
        RenderingAPI();
        virtual ~RenderingAPI();

        virtual void clear() = 0;
        virtual void clearColour(uint8_t r, uint8_t g, uint8_t b, uint8_t a) = 0;

        virtual void init() = 0;
        virtual void release() = 0;

        virtual void draw() = 0;

        virtual void bind(const IndeBuffer& indexBuffer) = 0;
        virtual void bind(const VertexBuffer& vertexBuffer) = 0;

        virtual void unbind(const IndexBuffer& indexBuffer) = 0;
        virtual void unbind(const VertexBuffer& vertexBuffer) = 0;
    };
} // RAL

#endif //!RAL_PROJECT_RENDERINGAPI_H
