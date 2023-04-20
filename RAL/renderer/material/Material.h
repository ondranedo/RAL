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

#ifndef RAL_PROJECT_MATERIAL_H
#define RAL_PROJECT_MATERIAL_H
#include "../texture/Texture.h"

namespace RAL{
    class Material{
    public:
        Material();
        ~Material();

        void openRalmt(std::string path);
        void openRalmt();
        void saveRalmt(std::string path);
        void saveRalmt();

        void setTexture(Texture* texture);
        void setTexturePath(std::string path);
        void setPath(std::string path);
        void setMirrorFlag(bool val);

        Texture* getTexture();
        std::string getPath();
        std::string getTexturePath();
        [[nodiscard]] bool getMirrorFlag() const;

    private:
        Texture* m_texture{};
        std::string m_texturePath;
        std::string m_path;
        bool m_isTextureMirrored{};
    };
}

#endif //RAL_PROJECT_MATERIAL_H
