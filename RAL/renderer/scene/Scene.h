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
#ifndef RAL_PROJECT_SCENE_H
#define RAL_PROJECT_SCENE_H

#include <vector>
#include <string>
#include "../entity/Object3D.h"

namespace RAL {
    class Scene {
    public:
        Scene();
        ~Scene();

        void loadTxtScene(const std::string& scenePath);
        void loadBinScene(const std::string& scenePath);
        void saveBinScene(const std::string& scenePath);

    private:

        struct Entity{
            Mesh* m_mesh;
            std::string m_name;
            int32_t m_xPos;
            int32_t m_yPos;
            int32_t m_zPos;
        };
        std::vector<Entity> m_entities;
    };
} // RAL

#endif //!RAL_PROJECT_SCENE_H
