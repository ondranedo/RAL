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

#ifndef RAL_PROJECT_WINDOWSPEC_H
#define RAL_PROJECT_WINDOWSPEC_H

#include <core/memoryManager/Overload.h>
#include <string>

// todo: icon path


/**
 *  block = 64 bit
 *  block[1]:
 *      n0..n63 - title
 *  block[2]:
 *      n0..n15 - width
 *      n16..n31 - height
 *      n33 - created
 */
#define RAL_WINDOW_SPEC_TITLE_SIZE 64

namespace RAL {
    struct WindowSpec {
        using dataBlock = uint64_t;
        char m_title[RAL_WINDOW_SPEC_TITLE_SIZE]; // 64 char for title
        dataBlock m_width : 16; // in pixels
        dataBlock m_height: 16; // in pixels
        dataBlock m_created : 1; // 0 - not created, 1 - created
        WindowSpec();
    };
} // RAL

#endif //!RAL_PROJECT_WINDOWSPEC_H
