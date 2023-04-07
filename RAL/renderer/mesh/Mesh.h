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

#ifndef RAL_PROJECT_MESH_H
#define RAL_PROJECT_MESH_H

#include <string>
#include <vector>

namespace RAL {
    class Mesh {

        //todo: potentially make a factory for use in model creator
        //      .obj or other foreign file support
    public:
        Mesh();
        ~Mesh();

        void openRalms(const std::string& path);

        std::string getPath();

    private:
        struct Vertex{
            float x;
            float y;
            float z;
        };
        struct vertexTriangle{
            uint32_t indexA;
            uint32_t indexB;
            uint32_t indexC;
        };
        std::string m_path;
        std::vector<Vertex> m_vertices;
        std::vector<vertexTriangle> m_triangles;
    };
} // RAL

#endif //RAL_PROJECT_MESH_H
