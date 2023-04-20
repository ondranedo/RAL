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

        Texture();
        ~Texture();

        [[nodiscard]] uint16_t getWidth() const;
        [[nodiscard]] uint16_t getHeight() const;
        [[nodiscard]] uint8_t getNOfChannels() const;
        [[nodiscard]] size_t getSize() const;
        uint8_t* getImage();

        void stbiLoadTexture(const std::string& path);
        void stbiLoadFlippedTexture(const std::string& path);

    private:
        uint8_t* m_image{};
        int32_t m_height{};
        int32_t m_width{};
        int32_t m_colorChannels{};
    };
}

#endif //RAL_PROJECT_TEXTURE_H
