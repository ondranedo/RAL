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

#ifndef RAL_PROJECT_MEMORY_H
#define RAL_PROJECT_MEMORY_H
#include <core/memoryManager/Overload.h>

#include <cstdint>
#include <core/baseClass/baseComponent.h>

namespace RAL {
    class Memory : public BaseComponent {
    public:
        Memory();
        virtual ~Memory();

        // Unaligned memory
        [[nodiscard]] virtual void*getBlock(size_t bytes) = 0;
        virtual void freeBlock(void *block) = 0;
        [[nodiscard]] virtual void *reallocBlock(void *block, size_t newSize) = 0;
        virtual size_t getBlockSize(void *block) = 0;

        // Aligned memory
        [[nodiscard]] virtual void*getAlignedBlock(size_t bytes, size_t ali) = 0;
        virtual void freeAlignedBlock(void *block) = 0;
        [[nodiscard]] virtual void *reallocAlignedBlock(void *block, size_t newSize, size_t ali) = 0;


        [[nodiscard]] size_t getBlocks() const;
        [[nodiscard]] size_t getAllocatedOnHeap() const;
        [[nodiscard]] size_t getAlignedBlocks() const;

    protected:
        size_t m_nOfBytesOnHeap;
        size_t m_nOfBlocks;
        size_t m_nOfAlignedBlocks; // TODO: unknown size
        // TODO: add debug memory tracing
    };
} // RAL

#endif //!RAL_PROJECT_MEMORY_H
