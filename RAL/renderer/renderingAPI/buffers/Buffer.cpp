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

namespace RAL {
    void Buffer::setDrawUsage(Buffer::DrawUsage usage) {
        m_usage = usage;
    }

    Buffer::DrawUsage Buffer::getDrawUsage() const {
        return m_usage;
    }

    Buffer::Buffer() : m_usage(DrawUsage::STATIC){

    }

    Buffer::~Buffer() = default;
} // RAL
