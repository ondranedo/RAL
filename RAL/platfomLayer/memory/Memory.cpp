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


#include "Memory.h"

#include <core/utility/Asserts.h>

namespace RAL {
    Memory::Memory(): m_nOfBytesOnHeap(0), m_nOfBlocks(0), m_nOfAlignedBlocks(0)
    {
    }

    size_t Memory::getBlocks() const {
        return m_nOfBytesOnHeap;
    }

    size_t Memory::getAllocatedOnHeap() const {
        return m_nOfBytesOnHeap;
    }

    size_t Memory::getAlignedBlocks() const {
        return m_nOfAlignedBlocks;
    }

    Memory::~Memory()
    {

    }

    bool Memory::checkMemoryLeak() {
        if(m_nOfBytesOnHeap != 0 || m_nOfBlocks != 0 || m_nOfAlignedBlocks != 0) {
            RAL_ASSERT(m_nOfBytesOnHeap == 0 && m_nOfBlocks == 0,
                       "Memory leak on heap detected - %d byte%s and %d block%s not freed",
                       m_nOfBytesOnHeap,m_nOfBytesOnHeap>1?"s":"",
                       m_nOfBlocks,m_nOfBlocks>1?"s":"");
            RAL_ASSERT(m_nOfAlignedBlocks == 0, "Memory leak on aligned heap detected -  %d blocks not freed", m_nOfAlignedBlocks);
            return true;
        }

        return false;
    }
} // RAL