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


#include "WindowSpec.h"
#include <core/utility/Logger.h>

namespace RAL {
    WindowSpec::WindowSpec():
            title("untitled window"),
            width(800),
            ratio(WindowRatio::RATIO_16_9)
    {
    }

    float WindowRatioValue(WindowRatio ratio) {
        switch (ratio) {
            case WindowRatio::RATIO_16_9:
                return 16.0f / 9.0f;
            case WindowRatio::RATIO_4_3:
                return 4.0f / 3.0f;
            case WindowRatio::RATIO_1_1:
                return 1.0f;
        }
        RAL_LOG_ERROR("Unknown window ratio!");
        return 1.0f;
    }
} // RAL