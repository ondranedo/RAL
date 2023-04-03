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

#include <vendor/glad/include/glad/glad.h>
#include <renderer/renderingAPI/VertexBuffer.h>

namespace RAL
{
    class GLVertexBuffer : public VertexBuffer
    {
    public:
        ~GLVertexBuffer() override;
        explicit GLVertexBuffer(const void* vertices);
        void bindVB() override;
        void unbindVB() override;
    protected:
        unsigned int m_VB{};
    };
};
#endif //!RAL_PROJECT_GLVERTEXBUFFER_H