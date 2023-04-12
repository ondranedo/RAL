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

#include "Mesh3D.h"

namespace RAL{

    void Mesh3D::openRalms(const std::string& path) {
        //TODO: switch to File
        //      ONDRANEDO CODE REVIEW

        uint32_t size;
        void* buffer;
        FILE* file = fopen(path.c_str(), "rb");

        m_path = path;

        //.ral3d has this structure:
        /*****************************************************************************/
        //number of verticies followed by them
        fread(&size, sizeof(uint32_t), 1, file);

        buffer = new Vertex[size];
        fread(buffer, sizeof(Vertex), size, file);

        //todo: something less dumb
        //      we already have an array so find a way to stuff it into the vector
        for(int i = 0; i < size; i++){
            m_vertices.push_back(reinterpret_cast<Vertex*>(buffer)[i]);
        }
        delete[] reinterpret_cast<Vertex*>(buffer);
        /********************************************************************************/
        //number of vertex triangles followed by them
        fread(&size, sizeof(uint32_t), 1, file);

        buffer = new vertexTriangle[size];
        fread(buffer, sizeof(vertexTriangle), size, file);

        //todo: same here
        for(int i = 0; i < size; i++){
            m_triangles.push_back(reinterpret_cast<vertexTriangle*>(buffer)[i]);
        }
        delete[] reinterpret_cast<vertexTriangle*>(buffer);
        /********************************************************************************/
        fclose(file);
    }

    void Mesh3D::addVertex(float x, float y, float z) {
        m_vertices.push_back({x,y,z});
    }

    void Mesh3D::addVertexTriangle(uint32_t indexA, uint32_t indexB, uint32_t indexC) {
        m_triangles.push_back({indexA, indexB, indexC});
    }

    void Mesh3D::removeVertex(uint32_t index) {
        if(index >= m_vertices.size()){
            m_vertices.pop_back();
        } else{
            //todo: make faster??? maybe?
            m_vertices[index] = m_vertices[m_vertices.size() - 1];
            m_vertices.pop_back();
        }
    }

    void Mesh3D::removeVertices(uint32_t beginIndex, uint32_t endIndex) {
        for(uint32_t i = beginIndex; i <= endIndex; i++){
            removeVertex(i);
        }
    }

    void Mesh3D::removeVertexTriangle(uint32_t index) {
        if(index >= m_triangles.size()){
            m_triangles.pop_back();
        } else{
            //todo: make faster??? maybe?
            m_triangles[index] = m_triangles[m_triangles.size() - 1];
            m_triangles.pop_back();
        }
    }

    void Mesh3D::removeVertexTriangles(uint32_t beginIndex, uint32_t endIndex) {
        for(uint32_t i = beginIndex; i <= endIndex; i++){
            removeVertexTriangle(i);
        }
    }

    void Mesh3D::addVertex(Mesh3D::Vertex vertex) {
        m_vertices.push_back(vertex);
    }

    void Mesh3D::addVertexTriangle(Mesh3D::vertexTriangle triangle) {
        m_triangles.push_back(triangle);
    }

    Mesh3D::Mesh3D() = default;

    Mesh3D::~Mesh3D() = default;
}

