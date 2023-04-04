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

namespace RAL {
    class Scene {
    public:
        Scene();
        ~Scene();

        void loadTxtScene(const std::string& name);
        void loadBinScene();
        void saveBinScene();

    private:
        struct Vertex{
            float x;
            float y;
            float z;
        };
        struct vertexTriangle{
            uint32_t a;
            uint32_t b;
            uint32_t c;
        };
        struct Mesh{
            std::vector<Vertex> m_vertices;
            std::vector<vertexTriangle> m_triangles;
        };

        struct intPos{
            int32_t x;
            int32_t y;
            int32_t z;
        };

        struct Entity{
            Mesh* m_mesh;
            std::string name;
            intPos m_pos;
        };
        std::vector<Entity> m_entities;
    };
} // RAL

#endif //!RAL_PROJECT_SCENE_H
