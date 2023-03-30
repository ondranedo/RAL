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


#ifndef RAL_PROJECT_CORE_H
#define RAL_PROJECT_CORE_H

/*#define RAL_WINDOWS_USE_WINMAIN*/

#ifdef RAL_WINDOWS
#include <platfomLayer/windows/memory/Win32Memory.h>
#define RAL_PLATFORM_MEMORY(name) RAL::Win32::Win32Memory name
#else
#error "Unknown platform"
#endif

#endif //!RAL_PROJECT_CORE_H