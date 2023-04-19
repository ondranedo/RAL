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
#include "../../platfomLayer/windows/file/Win32FileTxt.h"

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
        if(m_vertexDependencies[iterator - beginVertex()]){
            RAL_LOG_ERROR("Can't remove vertex because it is used by %d triangles", m_vertexDependencies[iterator - beginVertex()]);
        }
        else{
            m_vertices.erase(iterator);
            m_vertexDependencies.erase(m_vertexDependencies.begin() + (iterator - beginVertex()));
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
        for(auto i = begin; i <= end; i++){
            if(m_vertexDependencies[i - beginVertex()]){
                RAL_LOG_ERROR("Can't remove vertex #%d because it is used by %d triangles", i - beginVertex() ,m_vertexDependencies[i - beginVertex()]);
            }
            else{
                m_vertices.erase(i);
                m_vertexDependencies.erase(m_vertexDependencies.begin() + (i - beginVertex()));
            }
        }
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
        for(auto it = begin; it <= end; it++){
            m_vertexDependencies[it->indexA]--;
            m_vertexDependencies[it->indexB]--;
            m_vertexDependencies[it->indexC]--;
        }
        m_triangles.erase(begin, end);
    }

    void Mesh3D::openObj() {
        Win32::Win32FileTxt file;
        file.RAL::Win32::Win32File::open(getPath(), File::Mode::Read);
        size_t index;
        Vertex tempVertex{};
        vertexTriangle tempTriangle{};

        while(auto line = file.readLine()){
            if(line->starts_with('#')){
                //nothing - ignoring comments off the bat should increase loading speed
            }
            else if(line->starts_with('v')){
                //loading a vertex
                index = 1;
                tempVertex.x = std::stof(line->substr(index), &index);
                tempVertex.y = std::stof(line->substr(index), &index);
                tempVertex.z = std::stof(line->substr(index), &index);
                // ^this converts a portion of the string after index to a float and
                // stores the index after the last part of the number
                addVertex(tempVertex);
            }
            else if(line->starts_with('f')){
                //loading a triangle
                index = 1;
                tempTriangle.indexA = std::stoi(line->substr(index), &index);
                tempTriangle.indexB = std::stoi(line->substr(index), &index);
                tempTriangle.indexC = std::stoi(line->substr(index), &index);
                addVertexTriangle(tempTriangle);
            }
            //todo: potentially more .obj support (normals, texture points)
            //      multiple polygon face support (convex checks)
        }

        file.RAL::Win32::Win32File::close();
    }

    void Mesh3D::openObj(std::string path) {
        setPath(path);
        openObj();
    }

    Mesh3D::Mesh3D() = default;

    Mesh3D::~Mesh3D() = default;
}

