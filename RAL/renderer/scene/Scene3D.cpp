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
#include "Scene3D.h"
#include "../../platfomLayer/windows/file/Win32FileTxt.h"
#include "../../core/utility/Logger.h"

//todo: CODE CLEANUP
namespace RAL {

    Scene3D::Scene3D() = default;

    Scene3D::~Scene3D() = default;

    void Scene3D::loadBinScene(const std::string& scenePath) {
        //TODO: switch to File

        FILE* file = fopen(scenePath.c_str(), "rb");
        size_t tempSize;
        size_t nOfObjects;
        int32_t tempPos;
        std::string tempString;
        void* buffer;
        Object3D tempObject;

        //number of entities
        fread(&nOfObjects, sizeof(size_t), 1, file);

        for(int i = 0; i < nOfObjects; i++){
            //length of c string
            fread(&tempSize, sizeof(size_t), 1, file);

            //c string name
            buffer = new char[tempSize];
            fread(buffer, sizeof(char), tempSize, file);
            tempObject.setName(reinterpret_cast<char*>(buffer));
            delete[] reinterpret_cast<char*>(buffer);

            //length of c string
            fread(&tempSize, sizeof(size_t), 1, file);

            //c string mesh path
            buffer = new char[tempSize];
            fread(buffer, sizeof(char), tempSize, file);
            tempString = reinterpret_cast<char*>(buffer);
            delete[] reinterpret_cast<char*>(buffer);

            tempObject.setMesh(nullptr);
            //todo: better way of optimising
            //optimization: if mesh was used, point to the already loaded one
            for(auto & mesh : m_meshes){
                if(mesh.getPath() == tempString){
                    tempObject.setMesh(&mesh);
                    break;
                }
            }

            if(!tempObject.getMesh()){
                tempObject.setMesh(new Mesh3D);
                tempObject.getMesh()->openRalms(tempString);
                m_meshes.push_back(*tempObject.getMesh());
            }

            //position of object
            fread(&tempPos, sizeof(int32_t), 1, file);
            tempObject.setXPos(tempPos);
            fread(&tempPos, sizeof(int32_t), 1, file);
            tempObject.setYPos(tempPos);
            fread(&tempPos, sizeof(int32_t), 1, file);
            tempObject.setZPos(tempPos);

            m_objects.push_back(tempObject);
        }

        fclose(file);
    }

    void Scene3D::saveBinScene(const std::string& scenePath) {
        //TODO: switch to File

        FILE* file = fopen(scenePath.c_str(), "wb");
        size_t pathSize;
        size_t nameSize;
        size_t nOfEntities;
        int32_t tempPos;

        //number of entities
        nOfEntities = m_objects.size();
        fwrite(&nOfEntities, sizeof(size_t), 1, file);

        for(auto & object : m_objects){
            //length of c string
            nameSize = object.getName().size() + 1;
            fwrite(&nameSize, sizeof(size_t), 1, file);

            //c string name
            fwrite(object.getName().c_str(), sizeof(char), nameSize, file);

            //length of c string
            pathSize = object.getMesh()->getPath().size() + 1;
            fwrite(&pathSize, sizeof(size_t), 1, file);

            //c string mesh path
            fwrite(object.getMesh()->getPath().c_str(), sizeof(char), pathSize, file);

            //position of object
            tempPos = object.getXPos();
            fwrite(&tempPos, sizeof(int32_t), 1, file);
            tempPos = object.getYPos();
            fwrite(&tempPos, sizeof(int32_t), 1, file);
            tempPos = object.getZPos();
            fwrite(&tempPos, sizeof(int32_t), 1, file);
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
    void Scene3D::loadTxtScene(const std::string& scenePath) {

        Win32::Win32FileTxt file;
        file.RAL::Win32::Win32File::open(scenePath, File::Mode::Read);

        Object3D tempObject;
        int8_t switcher = 0;

        //there is memory leak potential if the scene file doesn't follow the strict guidelines
        while (auto tempLine = file.readLine()){
            switch (switcher) {
                case 0:
                    for(auto & object : m_objects){
                        if(object.getName() == tempLine){
                            RAL_LOG_INFO("Entity %s already in scene; won't be added", object.getName().c_str());
                            for(int i = 0; i < 4; i++){
                                file.readLine();
                            }
                            switcher--;
                            break;
                        }
                    }
                    tempObject.setName(tempLine.value());
                    break;
                case 1:
                    tempObject.setMesh(nullptr);

                    // optimization: if mesh was used, point to the already loaded one
                    for(auto & mesh : m_meshes){
                        if(mesh.getPath() == tempLine.value()){
                            tempObject.setMesh(&mesh);
                            break;
                        }
                    }

                    if(!tempObject.getMesh()){
                        tempObject.setMesh(new Mesh3D);
                        tempObject.getMesh()->openRalms(tempLine.value());
                        m_meshes.push_back(*tempObject.getMesh());
                    }
                    break;
                case 2:
                    tempObject.setXPos(std::stoi(tempLine.value()));
                    break;
                case 3:
                    tempObject.setYPos(std::stoi(tempLine.value()));
                    break;
                case 4:
                    tempObject.setZPos(std::stoi(tempLine.value()));
                    break;
            }
            switcher++;

            if(switcher == 5){
                m_objects.push_back(tempObject);
                switcher = 0;
            }
        }
        file.RAL::Win32::Win32File::close();
    }

} // RAL
