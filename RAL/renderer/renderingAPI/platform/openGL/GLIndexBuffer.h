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
#ifndef RAL_PROJECT_GLINDEXBUFFER_H
#define RAL_PROJECT_GLINDEXBUFFER_H

#include <renderer/renderingAPI/buffers/IndexBuffer.h>
#include <renderer/renderingAPI/platform/openGL/GLIndexable.h>

namespace RAL
{
    class GLIndexBuffer : public virtual IndexBuffer, public virtual GLIndexable
    {
    public:
        ~GLIndexBuffer() override;

        GLIndexBuffer();

        void setData(unsigned int *indices,unsigned int size,DrawUsage usage) override;

        void bind() const override;

        void unbind() const override;

    private:
    };
} // RAL

#endif //!RAL_PROJECT_GLINDEXBUFFER_H
