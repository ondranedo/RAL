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
#include <cstdint>
#include <string>
#include "renderer/mesh/Mesh.h"

namespace RAL {
    class Scene {
    public:
        Scene();
        ~Scene();

        void loadTxtScene(const std::string& scenePath);
        void loadBinScene(const std::string& scenePath);
        void saveBinScene(const std::string& scenePath);

    private:
        struct intPos{
            int32_t x;
            int32_t y;
            int32_t z;
        };

        struct Entity{
            Mesh* m_mesh;
            std::string m_name;
            intPos m_pos;
        };
        std::vector<Entity> m_entities;
    };
} // RAL

#endif //!RAL_PROJECT_SCENE_H
