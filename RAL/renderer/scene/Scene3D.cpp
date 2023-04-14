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
#include "../../core/utility/Logger.h"

namespace RAL {

    Scene3D::Scene3D() = default;

    Scene3D::~Scene3D() = default;

    void Scene3D::loadBinObjects(FILE *file) {

        size_t nOfObjects;
        size_t tempSize;
        void* buffer;
        Object3D tempObject;
        std::string tempString;
        int32_t tempPos;
        float tempFloat;

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
                tempObject.getMesh()->Mesh::openRalms(tempString);
                m_meshes.push_back(*tempObject.getMesh());
            }

            //position of object
            fread(&tempPos, sizeof(int32_t), 1, file);
            tempObject.setXPos(tempPos);
            fread(&tempPos, sizeof(int32_t), 1, file);
            tempObject.setYPos(tempPos);
            fread(&tempPos, sizeof(int32_t), 1, file);
            tempObject.setZPos(tempPos);

            //rotation of object
            fread(&tempFloat, sizeof(float), 1, file);
            tempObject.setXRot(tempFloat);
            fread(&tempFloat, sizeof(float), 1, file);
            tempObject.setYRot(tempFloat);
            fread(&tempFloat, sizeof(float), 1, file);
            tempObject.setZRot(tempFloat);

            //bounding box scale
            fread(&tempFloat, sizeof(float), 1, file);
            tempObject.setXBoxScale(tempFloat);
            fread(&tempFloat, sizeof(float), 1, file);
            tempObject.setYBoxScale(tempFloat);
            fread(&tempFloat, sizeof(float), 1, file);
            tempObject.setZBoxScale(tempFloat);

            m_objects.push_back(tempObject);
        }
    }

    void Scene3D::loadBinScene(const std::string& scenePath) {
        //TODO: switch to File

        FILE* file = fopen(scenePath.c_str(), "rb");

        loadBinObjects(file);

        fclose(file);
    }

    void Scene3D::saveBinScene(const std::string& scenePath) {
        //TODO: switch to File

        FILE* file = fopen(scenePath.c_str(), "wb");
        saveBinObjects(file);

        fclose(file);
    }

    //is subject to change
    //currently loads entries in an exact format, where every parameter is on a different line
    //entity type
    //entity parameters
    //WILL BREAK IF FILE DOESN'T FOLLOW THESE RULES
    //there is memory leak potential if the scene file doesn't follow the strict guidelines
    void Scene3D::loadTxtScene(const std::string& scenePath) {

        Win32::Win32FileTxt file;
        file.RAL::Win32::Win32File::open(scenePath, File::Mode::Read);

        while (auto tempLine = file.readLine()){
            if(tempLine == "object"){
                loadTxtObject(file);
            }
        }
        file.RAL::Win32::Win32File::close();
    }

    void Scene3D::saveBinObjects(FILE *file) {

        size_t tempSize;
        int32_t tempPos;
        float tempFloat;

        //number of entities
        tempSize = m_objects.size();
        fwrite(&tempSize, sizeof(size_t), 1, file);

        for(auto & object : m_objects){
            //length of c string
            tempSize = object.getName().size() + 1;
            fwrite(&tempSize, sizeof(size_t), 1, file);

            //c string name
            fwrite(object.getName().c_str(), sizeof(char), tempSize, file);

            //length of c string
            tempSize = object.getMesh()->getPath().size() + 1;
            fwrite(&tempSize, sizeof(size_t), 1, file);

            //c string mesh path
            fwrite(object.getMesh()->getPath().c_str(), sizeof(char), tempSize, file);

            //position of object
            tempPos = object.getXPos();
            fwrite(&tempPos, sizeof(int32_t), 1, file);
            tempPos = object.getYPos();
            fwrite(&tempPos, sizeof(int32_t), 1, file);
            tempPos = object.getZPos();
            fwrite(&tempPos, sizeof(int32_t), 1, file);

            //rotation of object
            tempFloat = object.getXRot();
            fwrite(&tempFloat, sizeof(float), 1, file);
            tempFloat = object.getYRot();
            fwrite(&tempFloat, sizeof(float), 1, file);
            tempFloat = object.getZRot();
            fwrite(&tempFloat, sizeof(float), 1, file);

            //bounding box scale
            tempFloat = object.getXBoxScale();
            fwrite(&tempFloat, sizeof(float), 1, file);
            tempFloat = object.getYBoxScale();
            fwrite(&tempFloat, sizeof(float), 1, file);
            tempFloat = object.getZBoxScale();
            fwrite(&tempFloat, sizeof(float), 1, file);
        }
    }

    void Scene3D::loadTxtObject(const Win32::Win32FileTxt& file) {

        std::string line;
        Object3D tempObject;

        //name
        line = file.readLine().value();
        for(auto & object : m_objects){
            if(object.getName() == line){
                RAL_LOG_INFO("Entity %s already in scene; won't be added", object.getName().c_str());
                for(int i = 0; i < 4; i++){
                    file.readLine();
                }
                return;
            }
        }
        tempObject.setName(line);

        //mesh
        line = file.readLine().value();
        tempObject.setMesh(nullptr);

        // optimization: if mesh was used, point to the already loaded one
        for(auto & mesh : m_meshes){
            if(mesh.getPath() == line){
                tempObject.setMesh(&mesh);
                break;
            }
        }

        if(!tempObject.getMesh()){
            tempObject.setMesh(new Mesh3D);
            tempObject.getMesh()->Mesh::openRalms(line);
            m_meshes.push_back(*tempObject.getMesh());
        }

        //position
        tempObject.setXPos(std::stoi(file.readLine().value()));
        tempObject.setYPos(std::stoi(file.readLine().value()));
        tempObject.setZPos(std::stoi(file.readLine().value()));

        //rotation
        tempObject.setXRot(std::stof(file.readLine().value()));
        tempObject.setYRot(std::stof(file.readLine().value()));
        tempObject.setZRot(std::stof(file.readLine().value()));

        //bounding box scale
        tempObject.setXBoxScale(std::stof(file.readLine().value()));
        tempObject.setYBoxScale(std::stof(file.readLine().value()));
        tempObject.setZBoxScale(std::stof(file.readLine().value()));

        m_objects.push_back(tempObject);
    }

} // RAL