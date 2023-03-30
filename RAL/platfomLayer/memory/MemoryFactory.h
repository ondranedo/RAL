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


#ifndef RAL_PROJECT_MEMORYFACTORY_H
#define RAL_PROJECT_MEMORYFACTORY_H
#include <core/memoryManager/Overload.h>

#include <core/baseClass/BaseFactory.h>
#include <platfomLayer/memory/Memory.h>

namespace RAL {
    class MemoryFactory : public BaseFactory<Memory> {
    public:
        MemoryFactory();
        Memory *create() override;
    };
} // RAL

#endif //!RAL_PROJECT_MEMORYFACTORY_H
