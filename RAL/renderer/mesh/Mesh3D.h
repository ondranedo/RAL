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

        void openRalms() override;
        void saveRalms() override;

        // TODO: Use move semantics to avoid copying,
        //       const _&, _&& for move semantics; where `_` is a type
        void addVertex(float x, float y, float z);
        void addVertex(Vertex vertex);
        void addVertexTriangle(uint32_t indexA, uint32_t indexB, uint32_t indexC);
        void addVertexTriangle(vertexTriangle triangle);

        void removeVertex(uint32_t index);
        void removeVertex(std::vector<Vertex>::iterator iterator);
        void removeVertices(uint32_t beginIndex, uint32_t endIndex);
        void removeVertices(std::vector<Vertex>::iterator begin, std::vector<Vertex>::iterator end);

        void removeVertexTriangle(uint32_t index);
        void removeVertexTriangle(std::vector<vertexTriangle>::iterator iterator);
        void removeVertexTriangles(uint32_t beginIndex, uint32_t endIndex);
        void removeVertexTriangles(std::vector<vertexTriangle>::iterator begin, std::vector<vertexTriangle>::iterator end);

        std::vector<Vertex>::iterator beginVertex();
        std::vector<Vertex>::iterator endVertex();
        std::vector<vertexTriangle>::iterator beginTriangle();
        std::vector<vertexTriangle>::iterator endTriangle();

        size_t nOfVertices();
        size_t nOfTriangles();
    private:

        std::vector<Vertex> m_vertices;
        std::vector<uint16_t> m_vertexDependencies;
        std::vector<vertexTriangle> m_triangles;
    };
}

#endif //RAL_PROJECT_MESH3D_H
