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
#ifndef RAL_PROJECT_GLVERTEXBUFFER_H
#define RAL_PROJECT_GLVERTEXBUFFER_H

#include <renderer/renderingAPI/buffers/VertexBuffer.h>
#include <renderer/renderingAPI/platform/openGL/GLIndexable.h>

namespace RAL
{
    class GLVertexBuffer final : public virtual VertexBuffer, public virtual GLIndexable
    {
    public:
        ~GLVertexBuffer() override;

        explicit GLVertexBuffer(float *vertices,unsigned int size,DrawUsage usage);

        void bind() const override;

        void unbind() const override;

    };
};
#endif //!RAL_PROJECT_GLVERTEXBUFFER_H