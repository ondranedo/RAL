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

#include "TextureParam.h"

namespace RAL {
    TextureParam::TextureParam() :
    width(0),height(0),channels(TextrueChannels::THREE), id(0),
    wrappingParam(TextureWrapping::REPEAT), filteringParam(TextureFiltering::NEAREST), data(nullptr)
    {}
} // RAL