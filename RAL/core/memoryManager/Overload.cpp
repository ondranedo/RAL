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


#include "Overload.h"
#include <core/utility/Logger.h>
#include <core/utility/Asserts.h>
#include <core/memoryManager/MemoryManager.h>

namespace RAL {
    namespace global {
        static RAL::MemoryManager* _memManager = nullptr;

        void setMemoryManager(RAL::MemoryManager* memManager)
        {
            _memManager = memManager;
        }
    };
};


[[nodiscard]] __declspec(allocator) void* operator new(size_t size) noexcept {
    RAL_ASSERTR(RAL::global::_memManager != nullptr, malloc(size), "Memory manager is not initialized! using malloc");
    return RAL::global::_memManager->alloc_size(size);
}

void operator delete(void* block, size_t size) noexcept {
    RAL_ASSERTR(RAL::global::_memManager != nullptr, free(block), "Memory manager is not initialized! using free");

    RAL::global::_memManager ->release(block);
    //free(block);
}
void operator delete(void* block) noexcept {
    RAL_ASSERTR(RAL::global::_memManager != nullptr, free(block), "Memory manager is not initialized! using free");
    RAL::global::_memManager ->release(block);
    //free(block);
}