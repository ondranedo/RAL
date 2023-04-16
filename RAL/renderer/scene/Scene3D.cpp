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
            else if(tempLine == "camera"){
                loadTxtCamera(file);
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

        //1 - name
        line = file.readLine().value();
        for(auto & object : m_objects){
            if(object.getName() == line){
                RAL_LOG_INFO("Entity %s already in scene; won't be added", object.getName().c_str());
                for(int i = 0; i < 10; i++){
                    file.readLine();
                }
                return;
            }
        }
        tempObject.setName(line);

        //2 - mesh
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

        //3, 4, 5 - position
        tempObject.setXPos(std::stoi(file.readLine().value()));
        tempObject.setYPos(std::stoi(file.readLine().value()));
        tempObject.setZPos(std::stoi(file.readLine().value()));

        //6, 7, 8 - rotation
        tempObject.setXRot(std::stof(file.readLine().value()));
        tempObject.setYRot(std::stof(file.readLine().value()));
        tempObject.setZRot(std::stof(file.readLine().value()));

        //9, 10, 11 - bounding box scale
        tempObject.setXBoxScale(std::stof(file.readLine().value()));
        tempObject.setYBoxScale(std::stof(file.readLine().value()));
        tempObject.setZBoxScale(std::stof(file.readLine().value()));

        //total: 11 lines -> need to skip 10
        m_objects.push_back(tempObject);
    }

    std::vector<Object3D>::iterator Scene3D::beginObject() {
        return m_objects.begin();
    }

    std::vector<Object3D>::iterator Scene3D::endObject() {
        return m_objects.end();
    }

    uint32_t Scene3D::getObjectCount() {
        return m_objects.size();
    }

    std::vector<Mesh3D>::iterator Scene3D::beginMesh() {
        return m_meshes.begin();
    }

    std::vector<Mesh3D>::iterator Scene3D::endMesh() {
        return m_meshes.end();
    }

    uint32_t Scene3D::getMeshCount() {
        return m_meshes.size();
    }

    std::vector<Texture>::iterator Scene3D::beginTexture() {
        return m_textures.begin();
    }

    std::vector<Texture>::iterator Scene3D::endTexture() {
        return m_textures.end();
    }

    uint32_t Scene3D::getTextureCount() {
        return m_textures.size();
    }

    std::vector<Material>::iterator Scene3D::beginMaterial() {
        return m_materials.begin();
    }

    std::vector<Material>::iterator Scene3D::endMaterial() {
        return m_materials.end();
    }

    uint32_t Scene3D::getMaterialCount() {
        return m_materials.size();
    }

    void Scene3D::addObject(const Object3D& object) {
        m_objects.push_back(object);
    }

    void Scene3D::deleteObject(std::vector<Object3D>::iterator iterator) {
        if(iterator > endObject()){
            iterator = endObject();
        }
        if(iterator < beginObject()){
            iterator = beginObject();
        }
        m_objects.erase(iterator);
    }

    void Scene3D::deleteObject(int32_t index) {
        deleteObject(beginObject() + index);
    }

    void Scene3D::deleteObject(const std::string& name) {
        for(auto i = beginObject(); i < endObject(); i++){
            if(i->getName() == name){
                deleteObject(i);
                return;
            }
        }
        RAL_LOG_ERROR("Object %s not found", name.c_str());
    }

    Object3D *Scene3D::getObject(const std::string& name) {
        for(auto i = beginObject(); i < endObject(); i++){
            if(i->getName() == name){
                return i.base();
            }
        }
        RAL_LOG_ERROR("Object %s not found", name.c_str());
        return nullptr;
    }

    Mesh3D *Scene3D::getMesh(const std::string& path) {
        for(auto i = beginMesh(); i < endMesh(); i++){
            if(i->getPath() == path){
                return i.base();
            }
        }
        RAL_LOG_ERROR("Mesh with the path %s not found", path.c_str());
        return nullptr;
    }

    void Scene3D::addCamera(const Camera3D& camera) {
        m_cameras.push_back(camera);
    }

    void Scene3D::deleteCamera(std::vector<Camera3D>::iterator iterator) {
        if(iterator > endCamera()){
            iterator = endCamera();
        }
        if(iterator < beginCamera()){
            iterator = beginCamera();
        }
        m_cameras.erase(iterator);
    }

    void Scene3D::deleteCamera(uint16_t index) {
        deleteCamera(beginCamera() + index);
    }

    void Scene3D::deleteCamera(const std::string& name) {
        for(auto i = beginCamera(); i < endCamera(); i++){
            if(i->getName() == name){
                deleteCamera(i);
                return;
            }
        }
        RAL_LOG_ERROR("Object %s not found", name.c_str());
    }

    Camera3D *Scene3D::getCamera(const std::string& name) {
        for(auto i = beginCamera(); i < endCamera(); i++){
            if(i->getName() == name){
                return i.base();
            }
        }
        RAL_LOG_ERROR("Object %s not found", name.c_str());
        return nullptr;
    }

    std::vector<Camera3D>::iterator Scene3D::beginCamera() {
        return m_cameras.begin();
    }

    std::vector<Camera3D>::iterator Scene3D::endCamera() {
        return m_cameras.end();
    }

    void Scene3D::loadTxtCamera(const Win32::Win32FileTxt &file) {

        std::string line;
        Camera3D tempCamera;

        //1 - name
        line = file.readLine().value();
        for(auto & camera : m_cameras){
            if(camera.getName() == line){
                RAL_LOG_INFO("Camera %s already in scene; won't be added", camera.getName().c_str());
                for(int i = 0; i < 8; i++){
                    file.readLine();
                }
                return;
            }
        }
        tempCamera.setName(line);

        //2 - projection
        line = file.readLine().value();
        if(line == "Orthographic"){
            tempCamera.setProjection(Camera3D::Projection::Orthographic);
        }
        else if(line == "Oblique"){
            tempCamera.setProjection(Camera3D::Projection::Oblique);
        }
        else{
            tempCamera.setProjection(Camera3D::Projection::Perspective);
        }

        //3 - width
        tempCamera.setWidth(std::stoi(file.readLine().value()));

        //4, 5, 6 - position
        tempCamera.setXPos(std::stoi(file.readLine().value()));
        tempCamera.setYPos(std::stoi(file.readLine().value()));
        tempCamera.setZPos(std::stoi(file.readLine().value()));

        //7, 8, 9 - rotation
        tempCamera.setXRot(std::stof(file.readLine().value()));
        tempCamera.setYRot(std::stof(file.readLine().value()));
        tempCamera.setZRot(std::stof(file.readLine().value()));

        //total: 9 lines -> need to skip 8
        m_cameras.push_back(tempCamera);
    }

} // RAL
