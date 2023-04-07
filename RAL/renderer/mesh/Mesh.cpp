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

#include "Mesh.h"

namespace RAL{

    Mesh::Mesh(const std::string& path) {
        //TODO: switch to File
        //      ONDRANEDO CODE REVIEW

        uint32_t size;
        void* buffer;
        FILE* file = fopen(path.c_str(), "rb");

        m_path = path;

        //.ralms has this structure:
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

    std::string Mesh::getPath() {
        return m_path;
    }

    Mesh::~Mesh() = default;
}

