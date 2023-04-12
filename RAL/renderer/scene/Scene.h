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

// TODO: rename Scene to Level
namespace RAL {
    class Scene {
    public:
        Scene();
        ~Scene();

        void loadTxtScene(const std::string& scenePath);
        void loadBinScene();
        void saveBinScene();

    private:
        // TODO: use glm::vec3 instead of intPos
        struct intPos{
            int32_t x;
            int32_t y;
            int32_t z;
        };

        // TODO: move to separate file, custom entity class
        struct Entity{
            Mesh* m_mesh;
            std::string name;
            intPos m_pos;
        };
        std::vector<Entity> m_entities;

        // TODO: Add coordinate system, skybox, lights, etc.
    };
} // RAL

#endif //!RAL_PROJECT_SCENE_H
