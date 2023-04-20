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
#include "Buffer.h"

#include <core/utility/Logger.h>

namespace RAL {
    void Buffer::setDrawUsage(Buffer::Usage usage) {
        m_usage = usage;
    }

    Buffer::Usage Buffer::getDrawUsage() const {
        return m_usage;
    }

    Buffer::Buffer() : m_usage(Usage::STATIC), m_data(nullptr), m_size(0) {}

    const void *Buffer::getData() const {
        if(m_data)
            return m_data;
        RAL_LOG_WARNING("Vertex buffer data is null");
        return nullptr;
    }

    size_t Buffer::getSize() const {
        if(m_data)
            return m_size;
        RAL_LOG_WARNING("Vertex buffer size is 0");
        return 0;
    }

    void Buffer::clear() {
        m_data = nullptr;
        m_size = 0;
    }

    Buffer::~Buffer() = default;
} // RAL
