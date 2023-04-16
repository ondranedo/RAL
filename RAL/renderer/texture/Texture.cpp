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

#include "Texture.h"

namespace RAL{

    uint16_t Texture::getWidth() {
        return m_image->data()->size();
    }

    uint16_t Texture::getHeight() {
        return m_image->size();
    }

    size_t Texture::getSize() {
        return getWidth() * getHeight() * sizeof(Pixel);
    }
//todo: check for leaks; still find it difficult to work with objects
    Texture::~Texture(){
        for(auto i : *m_image){
            i.clear();
        }
        m_image->clear();
        delete m_image;
    }

    Texture::Texture() = default;
}