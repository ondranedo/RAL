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

#ifndef RAL_PROJECT_WIN32MEMORY_H
#define RAL_PROJECT_WIN32MEMORY_H
#ifdef  RAL_WINDOWS

#include <platfomLayer/memory/Memory.h>

#ifdef RAL_DEBUG
#define RAL_WIN32_MEMORY_GUARD_ONE 0xB0
#endif

namespace RAL::Win32 {
    class Win32Memory final : public Memory {
    public:
        void init() override;
        void release() override;
        void update() override;

        void *getBlock(size_t bytes) override;
        void freeBlock(void *block) override;
        void *reallocBlock(void *block, size_t newSize) override;
        size_t getBlockSize(void *block) override;

        void *getAlignedBlock(size_t bytes, size_t alli) override;
        void freeAlignedBlock(void *block) override;
        void *reallocAlignedBlock(void *block, size_t newSize, size_t alli) override;
    };
} // RAL

#endif //!RAL_WINDOWS
#endif //!RAL_PROJECT_WIN32MEMORY_H
