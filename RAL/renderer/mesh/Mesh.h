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

        //todo: potentially make a factory for use in model creator
        //      .obj or other foreign file support
    public:
        Mesh();
        ~Mesh();

        void openRalms(const std::string& path);

        void addVertex(float x, float y, float z);
        void addVertex(Vertex vertex);
        void addVertexTriangle(uint32_t indexA, uint32_t indexB, uint32_t indexC);
        void addVertexTriangle(vertexTriangle triangle);
        void removeVertex(uint32_t index);
        void removeVertices(uint32_t beginIndex, uint32_t endIndex);
        void removeVertexTriangle(uint32_t index);
        void removeVertexTriangles(uint32_t beginIndex, uint32_t endIndex);

        std::string getPath();

    private:
        std::string m_path;
        std::vector<Vertex> m_vertices;
        std::vector<vertexTriangle> m_triangles;
    };
} // RAL

#endif //RAL_PROJECT_MESH_H
