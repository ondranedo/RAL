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

#include "Material.h"

namespace RAL{

    void Material::setTexture(Texture *texture) {
        m_texture = texture;
    }

    Texture *Material::getTexture() {
        return m_texture;
    }

    void Material::setPath(std::string path) {
        m_path = path;
    }

    void Material::openRalmt(std::string path) {
        setPath(path);
        openRalmt();
    }

    void Material::openRalmt() {

        //todo: fileIO
        FILE* file = fopen(m_path.c_str(), "rb");
        size_t tempSize;
        void* buffer;

        //ralmt structure:
        //length of c string
        fread(&tempSize, sizeof(size_t), 1, file);

        //c string texture path
        buffer = new char[tempSize];
        fread(buffer, sizeof(char), tempSize, file);
        setPath(reinterpret_cast<char*>(buffer));
        delete[] reinterpret_cast<char*>(buffer);

        fclose(file);
    }

    std::string Material::getPath() {
        return m_path;
    }

    std::string Material::getTexturePath() {
        return m_texturePath;
    }

    Material::~Material() = default;

    Material::Material() = default;
}