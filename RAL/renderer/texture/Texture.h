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

#ifndef RAL_PROJECT_TEXTURE_H
#define RAL_PROJECT_TEXTURE_H

#include <vector>
#include <string>

namespace RAL{
    class Texture{
    public:
        struct Pixel{
            uint8_t m_red;
            uint8_t m_green;
            uint8_t m_blue;
            uint8_t m_alpha;
        };

        Texture();
        ~Texture();

        uint16_t getWidth();
        uint16_t getHeight();
        size_t getSize();

    private:
        std::vector<std::vector<Pixel>>* m_image{};
    };
}

#endif //RAL_PROJECT_TEXTURE_H
