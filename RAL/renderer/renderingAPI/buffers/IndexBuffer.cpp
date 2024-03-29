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
#include "IndexBuffer.h"

namespace RAL
{
    void IndexBuffer::setData(unsigned int *ptr, unsigned int count) {
        m_data = ptr;
        m_size = count * sizeof(unsigned int);
    }

    uint32_t IndexBuffer::getIndeciesCount() const {
        return m_size / sizeof(unsigned int);
    }

    IndexBuffer::IndexBuffer(unsigned int *ptr, unsigned int count) {
        setData(ptr, count);
    }

    IndexBuffer::IndexBuffer() = default;

    IndexBuffer::~IndexBuffer() = default;
} // RAL