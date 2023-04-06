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
#include "Scene.h"
#include "../../platfomLayer/windows/file/Win32FileTxt.h"
#include "../../core/utility/Logger.h"

namespace RAL {

    Scene::Scene() {

    }

    Scene::~Scene() {

    }

    void Scene::loadBinScene() {

    }

    void Scene::saveBinScene() {

    }

    //is subject to change
    //currently loads five-line entries without separation and in an exact format
    //entity name
    //path to its mesh
    //x offset
    //y offset
    //z offset
    void Scene::loadTxtScene(const std::string& scenePath) {

        Win32::Win32FileTxt file;
        file.RAL::Win32::Win32File::open(scenePath, File::Mode::Read);

        Entity tempEntity;
        Mesh* tempMesh;
        int8_t switcher = 0;
        FILE* tempFile;
        uint32_t tempSize;
        void* buffer;

        while (auto tempLine = file.readLine()){
            switch (switcher) {
                case 0:
                    for(auto & entity : m_entities){
                        if(entity.name == tempLine){
                            RAL_LOG_INFO("Entity %s already in scene; won't be added", entity.name.c_str());
                            for(int i = 0; i < 4; i++){
                                file.readLine();
                            }
                            switcher--;
                            break;
                        }
                    }
                    tempEntity.name = tempLine.value();
                    break;
                case 1:
                    //TODO: switch to File
                    //      potentially move meshes to another files / classes
                    //      i.e Mesh* openMesh(path)
                    //      ONDRANEDO CODE REVIEW
                    tempFile = fopen(tempLine->c_str(), "r");
                    tempMesh = new Mesh;

                    //.ralms has this structure:
                    /*****************************************************************************/
                    //length of c string (max 255) followed by name <- used for optimization
                    fread(&tempSize, sizeof(uint8_t), 1, tempFile);

                    buffer = new char[tempSize];
                    fread(buffer, sizeof(char), tempSize, tempFile);

                    tempMesh->name = reinterpret_cast<char*>(buffer);
                    for(auto & entity : m_entities){
                        if(entity.m_mesh->name == tempMesh->name){
                            delete tempMesh;
                            tempMesh = nullptr;
                            tempEntity.m_mesh = entity.m_mesh;
                            break;
                        }
                    }

                    delete[] reinterpret_cast<char*>(buffer);
                    /*********************************************************************/
                    //number of verticies followed by them
                    if(tempMesh){
                        fread(&tempSize, sizeof(uint32_t), 1, tempFile);

                        buffer = new Vertex[tempSize];
                        fread(buffer, sizeof(Vertex), tempSize, tempFile);

                        //todo: data into vector
                        tempMesh->m_vertices.push_back(reinterpret_cast<Vertex*>(buffer)[0]);
                    }
                    /********************************************************************************/
                    //number of vertex triangles followed by them

                    /********************************************************************************/
                    fclose(tempFile);
                    break;
                case 2:
                    tempEntity.m_pos.x = std::stoi(tempLine.value());
                    break;
                case 3:
                    tempEntity.m_pos.y = std::stoi(tempLine.value());
                    break;
                case 4:
                    tempEntity.m_pos.z = std::stoi(tempLine.value());
                    break;
            }
            switcher++;

            if(switcher == 5){
                m_entities.push_back(tempEntity);
                switcher = 0;
            }
        }
        file.RAL::Win32::Win32File::close();
    }

} // RAL
