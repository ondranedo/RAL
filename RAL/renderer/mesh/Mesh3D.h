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

#ifndef RAL_PROJECT_MESH3D_H
#define RAL_PROJECT_MESH3D_H

#include "Mesh.h"
#include <vector>

namespace RAL{
    class Mesh3D : public Mesh{
        // consider using glm::vec3 instead of Vertex
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
        Mesh3D();
        ~Mesh3D();

        void openRalms(const std::string& path) override;

        // TODO: Use move semantics to avoid copying,
        //       const _&, _&& for move semantics; where `_` is a type
        void addVertex(float x, float y, float z);
        void addVertex(Vertex vertex);
        void addVertexTriangle(uint32_t indexA, uint32_t indexB, uint32_t indexC);
        void addVertexTriangle(vertexTriangle triangle);

        // TODO: index may be confusing, consider using iterator
        void removeVertex(uint32_t index);
        void removeVertices(uint32_t beginIndex, uint32_t endIndex);
        void removeVertexTriangle(uint32_t index);
        void removeVertexTriangles(uint32_t beginIndex, uint32_t endIndex);


        // TODO: add more methods for getting the number of vertices and triangles
        // TODO: add iterator begin and end methods for easy iteration
        //       over triangles
    private:

        // TODO:
        std::vector<Vertex> m_vertices;
        std::vector<vertexTriangle> m_triangles;
    };
}

#endif //RAL_PROJECT_MESH3D_H
