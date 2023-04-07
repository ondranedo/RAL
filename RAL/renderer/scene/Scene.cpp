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
                    tempEntity.m_mesh = nullptr;

                    // optimization: if mesh was used, point to the already loaded one
                    for(auto & entity : m_entities){
                        if(entity.m_mesh->getPath() == tempLine.value()){
                            tempEntity.m_mesh = entity.m_mesh;
                            break;
                        }
                    }

                    if(!tempEntity.m_mesh){
                        tempEntity.m_mesh = new Mesh(tempLine.value());
                    }
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
