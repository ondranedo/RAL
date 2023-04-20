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
#define STB_IMAGE_IMPLEMENTATION
#include <vendor/stb/stb_image.h>

namespace RAL{

    uint16_t Texture::getWidth() const {
        return m_width;
    }

    uint16_t Texture::getHeight() const {
        return m_height;
    }

    size_t Texture::getSize() const {
        return getWidth() * getHeight() * getNOfChannels();
    }

    Texture::~Texture(){
        stbi_image_free(m_image);
    }

    uint8_t Texture::getNOfChannels() const {
        return m_colorChannels;
    }

    void Texture::stbiLoadTexture(const std::string& path) {
        m_image = stbi_load(path.c_str(), &m_width, &m_height, &m_colorChannels, 0);
    }

    void Texture::stbiLoadFlippedTexture(const std::string &path) {
        stbi_set_flip_vertically_on_load(true);
        stbiLoadTexture(path);
        stbi_set_flip_vertically_on_load(false);
    }

    uint8_t *Texture::getImage() {
        return m_image;
    }

    Texture::Texture() = default;
}