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


#include "MemoryFactory.h"
#include <platfomLayer/windows/memory/Win32Memory.h>
#include <core/utility/Asserts.h>

namespace RAL {
    MemoryFactory::MemoryFactory() : BaseFactory<Memory>(1){}
    Memory *MemoryFactory::create() {
#ifdef RAL_WINDOWS
        return createPass(new Win32::Win32Memory);
#endif
        RAL_ASSERTR(false, nullptr, "Unknown platform when creating memory");
    }

} // RAL