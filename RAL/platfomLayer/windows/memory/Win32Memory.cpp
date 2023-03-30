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

#ifdef RAL_WINDOWS
#include "Win32Memory.h"

#include <core/utility/Logger.h>
#include <core/utility/Asserts.h>
#include <windows.h>
#include <malloc.h>


namespace RAL::Win32{

    void Win32Memory::init() {

    }

    void Win32Memory::release() {

    }

    void Win32Memory::update() {

    }

    void *Win32Memory::getBlock(size_t bytes) {
        RAL_ASSERTR(bytes > 0, nullptr, "Can't allocate 0 bytes");
        auto adr = malloc(bytes);
        RAL_ASSERTR(adr != nullptr, nullptr,"Failed to allocate memory of size [%lu], probably not enough memory", bytes);
        m_nOfBlocks++;
        m_nOfBytesOnHeap+= bytes;
        return adr;
    }

    void Win32Memory::freeBlock(void *block) {
        RAL_ASSERTRV(block != nullptr,"Block is nullptr, can't free");
        m_nOfBytesOnHeap-= getBlockSize(block);
        free(block);
        m_nOfBlocks--;
    }

    void *Win32Memory::reallocBlock(void *block, size_t newSize) {
        RAL_ASSERTR(block != nullptr, block, "Block is nullptr, can't reallocate");
        RAL_ASSERTR(newSize > 0, block, "Can't reallocate 0 bytes");
        auto oldSize = getBlockSize(block);
        auto adr = realloc(block, newSize);
        if(oldSize == newSize)
        {
            RAL_LOG_WARNING("Reallocating block of size [%lu] to size [%lu] is not needed", oldSize, newSize);
            return adr;
        }
        RAL_ASSERTR(adr != nullptr, block,"Failed to reallocate memory of size [%lu], probably not enough memory", newSize);
        m_nOfBlocks++;
        m_nOfBytesOnHeap+= newSize - oldSize;
        return adr;
    }

    size_t Win32Memory::getBlockSize(void *block) {
        RAL_ASSERTR(block != nullptr, 0, "Block is nullptr, can't get size");
        auto size =  _msize(block);
        RAL_ASSERTR(size != (size_t)-1,0, "Block is not allocated by this memory manager");
        return size;
    }

    void *Win32Memory::getAlignedBlock(size_t bytes, size_t ali) {
        RAL_ASSERTR(bytes > 0,nullptr, "Can't allocate 0 bytes");
        RAL_ASSERTR(ali % 2 == 0,nullptr, "Alignment must be power of 2");

        auto adr = _aligned_malloc(bytes, ali);
        RAL_ASSERTR(adr != nullptr, nullptr, "Failed to allocate memory of size [%lu], not enough memory or bad alignment [%lu]", bytes, ali);
        m_nOfAlignedBlocks++;
        return adr;
    }

    void Win32Memory::freeAlignedBlock(void *block) {
        RAL_ASSERTRV(block != nullptr, "Block is nullptr, can't free");
        m_nOfAlignedBlocks--;
        _aligned_free(block);
    }

    void *Win32Memory::reallocAlignedBlock(void *block, size_t newSize, size_t ali) {
        RAL_ASSERTR(block != nullptr,block, "Block is nullptr, can't reallocate");
        RAL_ASSERTR(newSize > 0, block, "Can't reallocate 0 bytes");
        RAL_ASSERTR(ali % 2 == 0, block,"Alignment must be power of 2");
        auto newAdr = _aligned_realloc(block, newSize, ali);
        RAL_ASSERTR(newAdr != nullptr, block, "Failed to reallocate memory of size [%lu], not enough memory or bad alignment [%lu]", newSize, ali);
        return newAdr;
    }

    /*
    size_t Win32Memory::getAlignedBlockSize(void *block) {
        size_t size = _aligned_msize(block);
        RAL_ASSERT(size != (size-1), "Block is not allocated by this memory manager");
        return size;
    }*/
} // RAL
#endif //!RAL_WINDOWS
