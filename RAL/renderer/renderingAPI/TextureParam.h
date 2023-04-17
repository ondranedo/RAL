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

#ifndef RAL_PROJECT_TEXTUREPARAM_H
#define RAL_PROJECT_TEXTUREPARAM_H

#include <cstdint>

#define RAL_TEXTURE_MAX_WIDTH  1<<15
#define RAL_TEXTURE_MAX_HEIGHT 1<<15
#define RAL_TEXTURE_MAX_ID     1<<16

namespace RAL {
    using TextureStructBlock = uint32_t;
    enum class TextureWrapping : TextureStructBlock {
        REPEAT,
        MIRRORED_REPEAT,
        CLAMP_TO_EDGE
    };

    enum class TextureFiltering : TextureStructBlock {
        NEAREST,
        LINEAR
    };

    enum class TextureChannels : TextureStructBlock {
        ONE,
        TWO,
        THREE,
        FOUR
    };

    struct TextureParam {
        TextureStructBlock width : 15;
        TextureStructBlock height : 15;
        TextureChannels    channels : 2; // 00 - 1; 01 - 2; 10 - 3; 11 - 4
        TextureStructBlock id : 16;
        TextureWrapping    wrappingParam : 8;
        TextureFiltering   filteringParam : 8;
        void*              data;

        TextureParam();
    };

} // RAL

#endif //RAL_PROJECT_TEXTUREPARAM_H
