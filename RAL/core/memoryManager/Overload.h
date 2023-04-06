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


#ifndef RAL_PROJECT_OVERLOAD_H
#define RAL_PROJECT_OVERLOAD_H

#include <cstdint>

[[nodiscard]] __declspec(allocator) void* operator new(size_t size) noexcept;
extern void operator delete(void* block, size_t size) noexcept;
extern void operator delete(void* block) noexcept;

namespace RAL {
    class MemoryManager;
    namespace global {
        extern void setMemoryManager(MemoryManager* memManager);
    };
};


#endif //!RAL_PROJECT_OVERLOAD_H