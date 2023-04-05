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
        int8_t switcher = 0;

        while (auto tempLine = file.readLine()){
            switch (switcher) {
                case 0:
                    tempEntity.name = tempLine.value();
                    break;
                case 1:
                    //open mesh file
                    //find if has been loaded yet
                    //stuff contents into Mesh on heap
                    //save pointer in tempEntity
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
