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
#include "VertexBuffer.h"
#include <core/utility/Logger.h>
namespace RAL{
    VertexBuffer::VertexBuffer() : m_layout() {}
    VertexBuffer::~VertexBuffer() = default;

    void VertexBuffer::setLayout(const VertexBufferLayout &layout) {
        m_layout = layout;
    }

    void VertexBuffer::setLayout(VertexBufferLayout &&layout) {
        m_layout = std::move(layout);
    }

    void VertexBuffer::setData(void *ptr, const size_t size) {
        m_data = ptr;
        m_size = size;
    }

    const VertexBufferLayout &VertexBuffer::getLayout() const {
        return m_layout;
    }

};