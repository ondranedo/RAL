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
 */
#define RAL_WINDOW_SPEC_TITLE_SIZE 64

namespace RAL {
    using dataBlock = uint64_t;

    enum class WindowRatio : dataBlock {
        RATIO_16_9,
        RATIO_4_3,
        RATIO_1_1
    };

    float WindowRatioValue(WindowRatio ratio);

    struct WindowSpec {
        char title[RAL_WINDOW_SPEC_TITLE_SIZE]; // 64 char for title
        dataBlock width : 16; // in pixels
        WindowRatio ratio : 16; // ratio
        WindowSpec();
    };
} // RAL

#endif //!RAL_PROJECT_WINDOWSPEC_H
