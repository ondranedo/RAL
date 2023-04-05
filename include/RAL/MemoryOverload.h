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

// Last version of this file: 2023-04-05_20:17

/*
 *  This file is used to overload new and delete operators.
 *  It is used to track memory leaks. Should be included
 *  in every file that uses new and delete operators.
 *  Include if using std library headers that use new and delete,
 *  f.e std::string, std::vector, std::map, etc.
 */



#ifndef RAL_PROJECT_OVERLOAD_H
#define RAL_PROJECT_OVERLOAD_H

#include <cstdint>

extern void* operator new(size_t size);
extern void operator delete(void* block, size_t size) noexcept;
extern void operator delete(void* blck) noexcept;

#endif //!RAL_PROJECT_OVERLOAD_H
