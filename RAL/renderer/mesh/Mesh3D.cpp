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
#include "../../core/utility/Logger.h"

namespace RAL{

    void Mesh3D::openRalms() {
        if(nOfTriangles() || nOfVertices()){
            RAL_LOG_INFO("Can only open with empty mesh");
        }
        else {
            //TODO: switch to File

            uint32_t size;
            void *buffer;

            // TODO: switch to FileIO
            FILE *file = fopen(getPath().c_str(), "rb");

            //.ral3d has this structure:
            /*****************************************************************************/
            //number of verticies followed by them
            fread(&size, sizeof(uint32_t), 1, file);

            buffer = new Vertex[size];
            fread(buffer, sizeof(Vertex), size, file);

            //todo: something less dumb
            //      we already have an array so find a way to stuff it into the vector
            for (int i = 0; i < size; i++) {
                m_vertices.push_back(reinterpret_cast<Vertex *>(buffer)[i]);
                m_vertexDependencies.push_back(0);
            }
            delete[] reinterpret_cast<Vertex *>(buffer);
            /********************************************************************************/
            //number of vertex triangles followed by them
            fread(&size, sizeof(uint32_t), 1, file);

            buffer = new vertexTriangle[size];
            fread(buffer, sizeof(vertexTriangle), size, file);

            //todo: same here
            for (int i = 0; i < size; i++) {
                m_triangles.push_back(reinterpret_cast<vertexTriangle *>(buffer)[i]);
                m_vertexDependencies[m_triangles[i].indexA]++;
                m_vertexDependencies[m_triangles[i].indexB]++;
                m_vertexDependencies[m_triangles[i].indexC]++;
            }
            delete[] reinterpret_cast<vertexTriangle *>(buffer);
            /********************************************************************************/
            fclose(file);
        }
    }

    void Mesh3D::addVertex(float x, float y, float z) {
        m_vertices.push_back({x,y,z});
        m_vertexDependencies.push_back(0);
    }

    void Mesh3D::addVertexTriangle(uint32_t indexA, uint32_t indexB, uint32_t indexC) {
        m_triangles.push_back({indexA, indexB, indexC});
        m_vertexDependencies[indexA]++;
        m_vertexDependencies[indexB]++;
        m_vertexDependencies[indexC]++;
    }

    void Mesh3D::removeVertex(uint32_t index) {
        removeVertex(beginVertex() + index);
    }

    void Mesh3D::removeVertices(uint32_t beginIndex, uint32_t endIndex) {
        removeVertices(beginVertex() + beginIndex, beginVertex() + endIndex);
    }

    void Mesh3D::removeVertexTriangle(uint32_t index) {
        removeVertexTriangle(beginTriangle() + index);
    }

    void Mesh3D::removeVertexTriangles(uint32_t beginIndex, uint32_t endIndex) {
        removeVertexTriangles(beginTriangle() + beginIndex, beginTriangle() + endIndex);
    }

    void Mesh3D::addVertex(Mesh3D::Vertex vertex) {
        m_vertices.push_back(vertex);
        m_vertexDependencies.push_back(0);
    }

    void Mesh3D::addVertexTriangle(Mesh3D::vertexTriangle triangle) {
        m_triangles.push_back(triangle);
        m_vertexDependencies[triangle.indexA]++;
        m_vertexDependencies[triangle.indexB]++;
        m_vertexDependencies[triangle.indexC]++;
    }

    void Mesh3D::saveRalms() {
        //TODO: switch to File

        uint32_t size;

        // TODO: switch to FileIO
        FILE* file = fopen(getPath().c_str(), "wb");

        //.ral3d has this structure:
        /*****************************************************************************/
        //number of verticies followed by them
        size = m_vertices.size();
        fwrite(&size, sizeof(uint32_t), 1, file);

        fwrite(m_vertices.data(), sizeof(Vertex), size, file);
        /********************************************************************************/
        //number of vertex triangles followed by them
        size = m_triangles.size();
        fwrite(&size, sizeof(uint32_t), 1, file);

        fread(m_triangles.data(), sizeof(vertexTriangle), size, file);
        /********************************************************************************/
        fclose(file);
    }

    std::vector<Mesh3D::Vertex>::iterator Mesh3D::beginVertex() {
        return m_vertices.begin();
    }

    std::vector<Mesh3D::Vertex>::iterator Mesh3D::endVertex() {
        return m_vertices.end();
    }

    std::vector<Mesh3D::vertexTriangle>::iterator Mesh3D::beginTriangle() {
        return m_triangles.begin();
    }

    std::vector<Mesh3D::vertexTriangle>::iterator Mesh3D::endTriangle() {
        return m_triangles.end();
    }

    size_t Mesh3D::nOfVertices() {
        return m_vertices.size();
    }

    size_t Mesh3D::nOfTriangles() {
        return m_triangles.size();
    }

    void Mesh3D::removeVertex(std::vector<Vertex>::iterator iterator) {
        if(iterator > endVertex()){
            iterator = endVertex();
        }
        if(iterator < beginVertex()){
            iterator = beginVertex();
        }
        auto tempIndex = iterator - beginVertex();
        if(m_vertexDependencies[tempIndex]){
            RAL_LOG_ERROR("Can't remove vertex because it is used by %d triangles", m_vertexDependencies[tempIndex]);
        }
        else{
            m_vertices.erase(iterator);
            auto tempIt = m_vertexDependencies.begin();
            m_vertexDependencies.erase(tempIt + tempIndex);
        }
    }

    void
    Mesh3D::removeVertices(std::vector<Mesh3D::Vertex>::iterator begin, std::vector<Mesh3D::Vertex>::iterator end) {
        if(begin > end){
            std::swap(begin, end);
        }
        if(begin < beginVertex()){
            begin = beginVertex();
        }
        if(end > endVertex()){
            end = endVertex();
        }
        m_vertices.erase(begin, end);
    }

    void Mesh3D::removeVertexTriangle(std::vector<vertexTriangle>::iterator iterator) {
        if(iterator > endTriangle()){
            iterator = endTriangle();
        }
        else if(iterator < beginTriangle()){
            iterator = beginTriangle();
        }
        m_vertexDependencies[iterator->indexA]--;
        m_vertexDependencies[iterator->indexB]--;
        m_vertexDependencies[iterator->indexC]--;
        m_triangles.erase(iterator);
    }

    void Mesh3D::removeVertexTriangles(std::vector<Mesh3D::vertexTriangle>::iterator begin,
                                       std::vector<Mesh3D::vertexTriangle>::iterator end) {
        if(begin > end){
            std::swap(begin, end);
        }
        if(begin < beginTriangle()){
            begin = beginTriangle();
        }
        if(end > endTriangle()){
            end = endTriangle();
        }
        m_triangles.erase(begin, end);
    }

    Mesh3D::Mesh3D() = default;

    Mesh3D::~Mesh3D() = default;
}

