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


#include "MemoryManager.h"
#include <core/utility/Asserts.h>

namespace RAL {
    void MemoryManager::init() {
        RAL_ASSERTRV(m_memory == nullptr, "Memory manager is already initialized!");
    }

    void MemoryManager::release() {
        RAL_ASSERTRV(m_memory != nullptr, "Memory manager is not initialized!");
        m_memory = nullptr;
    }

    void *MemoryManager::alloc_size(const size_t size){
        RAL_ASSERTR(m_memory != nullptr, nullptr, "Memory manager is not initialized!");
        RAL_ASSERTR(size > 0, nullptr, "Allocating 0 bytes is not allowed!");
        return m_memory->getBlock(size);
    }

    void *MemoryManager::reallocate(void *mem, const size_t size) const {
        RAL_ASSERT(m_memory != nullptr, "Memory manager is not initialized!");
        RAL_ASSERT(mem != nullptr, "Reallocating nullptr is not allowed!");
        RAL_ASSERT(size > 0, "Allocating 0 bytes is not allowed!");
        return m_memory->reallocBlock(mem, size);
    }

    MemoryManager::MemoryManager(Memory* mem) : m_memory(mem) {}

    MemoryManager::~MemoryManager()
    {
        if(m_memory != nullptr)
            release();
    }

    void MemoryManager::update() {}

    void MemoryManager::release(void *adr) {
        RAL_ASSERT(m_memory != nullptr, "Memory manager is not initialized!");
        RAL_ASSERT(adr != nullptr, "Releasing nullptr is not allowed!");
        m_memory->freeBlock(adr);
    }
} // RAL