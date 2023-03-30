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

#ifndef RAL_PROJECT_MEMORYMANAGER_H
#define RAL_PROJECT_MEMORYMANAGER_H
#include <core/memoryManager/Overload.h>

#include <core/baseClass/BaseComponent.h>
#include <core/utility/Asserts.h>
#include <cinttypes>
#include <cstdlib>

#include <platfomLayer/memory/Memory.h>
#include <platfomLayer/memory/MemoryFactory.h>

namespace RAL {
    class MemoryManager final : public BaseComponent {
    public:
        MemoryManager(Memory* memory);
        ~MemoryManager();
        void init() override;
        void release() override;
        void update() override;

        // Is in allocator
        [[nodiscard]] void* alloc_size(size_t size);
        template<typename T, typename... Args> [[nodiscard]] T* alloc(Args... args);
        template<typename T> void release(T* adr);
        void release(void* adr);
        [[nodiscard]] void* reallocate(void* mem, size_t size) const;
        //^Is in allocator

    private:
        Memory* m_memory;
    };

    template<typename T, typename... Args>
    T* MemoryManager::alloc(Args... args) {
        RAL_ASSERT(m_memory != nullptr, "Memory manager is not initialized!");
        T *adr = (T *) m_memory->getBlock(sizeof(T));
        new(adr) T(args...);
        return adr;
    }

    template<typename T>
    void MemoryManager::release(T *adr) {
        RAL_ASSERT(m_memory != nullptr, "Memory manager is not initialized!");
        RAL_ASSERT(adr != nullptr, "Releasing nullptr is not allowed!");
        adr->~T();
        m_memory->freeBlock(adr);
    }
} // RAL

#endif //!RAL_PROJECT_MEMORYMANAGER_H
