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

namespace RAL
{
    class VertexBuffer : public virtual Buffer
    {
    public:
        virtual ~VertexBuffer() = default;

    };
};
#endif //!RAL_PROJECT_VERTEXBUFFER_H