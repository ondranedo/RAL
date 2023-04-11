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

    void Scene::loadBinScene(const std::string& scenePath) {
        //TODO: switch to File

        FILE* file = fopen(scenePath.c_str(), "rb");
        size_t tempSize;
        size_t nOfEntities;
        std::string tempString;
        void* buffer;
        Entity tempEntity;

        //number of entities
        fread(&nOfEntities, sizeof(size_t), 1, file);

        for(int i = 0; i < nOfEntities; i++){
            //length of c string
            fread(&tempSize, sizeof(size_t), 1, file);

            //c string name
            buffer = new char[tempSize];
            fread(buffer, sizeof(char), tempSize, file);
            tempEntity.m_name = reinterpret_cast<char*>(buffer);
            delete[] reinterpret_cast<char*>(buffer);

            //length of c string
            fread(&tempSize, sizeof(size_t), 1, file);

            //c string mesh path
            buffer = new char[tempSize];
            fread(buffer, sizeof(char), tempSize, file);
            tempString = reinterpret_cast<char*>(buffer);
            delete[] reinterpret_cast<char*>(buffer);

            tempEntity.m_mesh = nullptr;

            // optimization: if mesh was used, point to the already loaded one
            for(auto & entity : m_entities){
                if(entity.m_mesh->getPath() == tempString){
                    tempEntity.m_mesh = entity.m_mesh;
                    break;
                }
            }

            if(!tempEntity.m_mesh){
                tempEntity.m_mesh = new Mesh;
                tempEntity.m_mesh->openRalms(tempString);
            }

            //position of object
            fread(&tempEntity.m_xPos, sizeof(int32_t), 1, file);
            fread(&tempEntity.m_yPos, sizeof(int32_t), 1, file);
            fread(&tempEntity.m_zPos, sizeof(int32_t), 1, file);
            m_entities.push_back(tempEntity);
        }

        fclose(file);
    }

    void Scene::saveBinScene(const std::string& scenePath) {
        //TODO: switch to File

        FILE* file = fopen(scenePath.c_str(), "wb");
        size_t pathSize;
        size_t nameSize;
        size_t nOfEntities;

        //number of entities
        nOfEntities = m_entities.size();
        fwrite(&nOfEntities, sizeof(size_t), 1, file);

        for(auto & entity : m_entities){
            //length of c string
            nameSize = entity.m_name.size() + 1;
            fwrite(&nameSize, sizeof(size_t), 1, file);

            //c string name
            fwrite(entity.m_name.c_str(), sizeof(char), nameSize, file);

            //length of c string
            pathSize = entity.m_mesh->getPath().size() + 1;
            fwrite(&pathSize, sizeof(size_t), 1, file);

            //c string mesh path
            fwrite(entity.m_mesh->getPath().c_str(), sizeof(char), pathSize, file);

            //position of object
            fwrite(&entity.m_xPos, sizeof(int32_t), 1, file);
            fwrite(&entity.m_yPos, sizeof(int32_t), 1, file);
            fwrite(&entity.m_zPos, sizeof(int32_t), 1, file);
        }

        fclose(file);
    }

    //is subject to change
    //currently loads five-line entries without separation and in an exact format
    //entity name\n
    //path to its mesh\n
    //x offset\n
    //y offset\n
    //z offset\n
    void Scene::loadTxtScene(const std::string& scenePath) {

        Win32::Win32FileTxt file;
        file.RAL::Win32::Win32File::open(scenePath, File::Mode::Read);

        Entity tempEntity;
        int8_t switcher = 0;

        //there is memory leak potential if the scene file doesn't follow the strict guidelines
        while (auto tempLine = file.readLine()){
            switch (switcher) {
                case 0:
                    for(auto & entity : m_entities){
                        if(entity.m_name == tempLine){
                            RAL_LOG_INFO("Entity %s already in scene; won't be added", entity.m_name.c_str());
                            for(int i = 0; i < 4; i++){
                                file.readLine();
                            }
                            switcher--;
                            break;
                        }
                    }
                    tempEntity.m_name = tempLine.value();
                    break;
                case 1:
                    tempEntity.m_mesh = nullptr;

                    // optimization: if mesh was used, point to the already loaded one
                    for(auto & entity : m_entities){
                        if(entity.m_mesh->getPath() == tempLine.value()){
                            tempEntity.m_mesh = entity.m_mesh;
                            break;
                        }
                    }

                    if(!tempEntity.m_mesh){
                        tempEntity.m_mesh = new Mesh;
                        tempEntity.m_mesh->openRalms(tempLine.value());
                    }
                    break;
                case 2:
                    tempEntity.m_xPos = std::stoi(tempLine.value());
                    break;
                case 3:
                    tempEntity.m_yPos = std::stoi(tempLine.value());
                    break;
                case 4:
                    tempEntity.m_zPos = std::stoi(tempLine.value());
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
