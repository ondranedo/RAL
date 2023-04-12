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
#ifndef RAL_PROJECT_INDEXBUFFER_H
#define RAL_PROJECT_INDEXBUFFER_H

#include <renderer/renderingAPI/buffers/Buffer.h>

namespace RAL
{
    // Index buffer class, used for storing indecies of vertices
    // one of the most important buffers together with vertex buffer.
    // Index buffer is used for drawing triangles, quads, lines etc.
    // Has to be bound before every draw call.
    class IndexBuffer final : public Buffer
    {
    public:
        ~IndexBuffer() override;

        // Sets data to index buffer, it is very important to set data
        // before binding index buffer and setting it as !unsigned int!
        // [count] is number of indecies, not size in bytes!
        void setData(unsigned int *ptr, unsigned int count);

        [[nodiscard]] uint32_t getIndeciesCount() const;
    };
} // RAL

#endif //!RAL_PROJECT_INDEXBUFFER_H
