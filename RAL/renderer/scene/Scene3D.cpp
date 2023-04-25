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
        int32_t tempInt;
        float tempFloat;
        PhysicalProperties tempProperties;

        //number of objects
        fread(&nOfObjects, sizeof(size_t), 1, file);

        for(size_t i = 0; i < nOfObjects; i++){

            addObject(tempObject);

            //length of c string
            fread(&tempSize, sizeof(size_t), 1, file);

            //c string name
            buffer = new char[tempSize];
            fread(buffer, sizeof(char), tempSize, file);
            endObject().base()->setName(reinterpret_cast<char*>(buffer));
            delete[] reinterpret_cast<char*>(buffer);

            //mesh index
            fread(&tempSize, sizeof(size_t), 1, file);
            endObject().base()->setMesh(beginMesh().base() + tempSize);

            //material index
            fread(&tempSize, sizeof(size_t), 1, file);
            endObject().base()->setMaterial(beginMaterial().base() + tempSize);

            //position of object
            fread(&tempInt, sizeof(int32_t), 1, file);
            endObject().base()->setXPos(tempInt);
            fread(&tempInt, sizeof(int32_t), 1, file);
            endObject().base()->setYPos(tempInt);
            fread(&tempInt, sizeof(int32_t), 1, file);
            endObject().base()->setZPos(tempInt);

            //rotation of object
            fread(&tempFloat, sizeof(float), 1, file);
            endObject().base()->setXRot(tempFloat);
            fread(&tempFloat, sizeof(float), 1, file);
            endObject().base()->setYRot(tempFloat);
            fread(&tempFloat, sizeof(float), 1, file);
            endObject().base()->setZRot(tempFloat);

            //bounding box scale
            fread(&tempFloat, sizeof(float), 1, file);
            endObject().base()->setXBoxScale(tempFloat);
            fread(&tempFloat, sizeof(float), 1, file);
            endObject().base()->setYBoxScale(tempFloat);
            fread(&tempFloat, sizeof(float), 1, file);
            endObject().base()->setZBoxScale(tempFloat);

            //physical properties
            fread(&tempProperties, sizeof(PhysicalProperties), 1, file);
            //todo: something better? just add a setPhysicalProperties?
            endObject().base()->getPhysicalProperties()->setXVel(tempProperties.getXVel());
            endObject().base()->getPhysicalProperties()->setYVel(tempProperties.getYVel());
            endObject().base()->getPhysicalProperties()->setZVel(tempProperties.getZVel());
            endObject().base()->getPhysicalProperties()->setXAcc(tempProperties.getXAcc());
            endObject().base()->getPhysicalProperties()->setYAcc(tempProperties.getYAcc());
            endObject().base()->getPhysicalProperties()->setZAcc(tempProperties.getZAcc());
            endObject().base()->getPhysicalProperties()->setWeight(tempProperties.getWeight());
        }
    }

    void Scene3D::loadBinScene(const std::string& scenePath) {
        //TODO: switch to File

        FILE* file = fopen(scenePath.c_str(), "rb");

        loadBinMeshes(file);
        loadBinMaterials(file);
        loadBinObjects(file);
        loadBinCameras(file);

        fclose(file);
        loadTextures();
        setActiveCamera("mainCamera");
        if(!getActiveCamera()){
            setActiveCamera(0);
        }
    }

    void Scene3D::saveBinScene(const std::string& scenePath) {
        //TODO: switch to File

        FILE* file = fopen(scenePath.c_str(), "wb");

        saveBinMeshes(file);
        saveBinMaterials(file);
        saveBinObjects(file);
        saveBinCameras(file);

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
        loadTextures();
        setActiveCamera("mainCamera");
        if(!getActiveCamera()){
            setActiveCamera(0);
        }
    }

    void Scene3D::saveBinObjects(FILE *file) {

        size_t tempSize;
        int32_t tempInt;
        float tempFloat;

        //number of objects
        tempSize = m_objects.size();
        fwrite(&tempSize, sizeof(size_t), 1, file);

        for(auto & object : m_objects){
            //length of c string
            tempSize = object.getName().size() + 1;
            fwrite(&tempSize, sizeof(size_t), 1, file);

            //c string name
            fwrite(object.getName().c_str(), sizeof(char), tempSize, file);

            //mesh index
            tempSize = object.getMesh() - beginMesh().base();
            fwrite(&tempSize, sizeof(size_t), 1, file);

            //material index
            tempSize = object.getMaterial() - beginMaterial().base();
            fwrite(&tempSize, sizeof(size_t), 1, file);

            //position of object
            tempInt = object.getXPos();
            fwrite(&tempInt, sizeof(int32_t), 1, file);
            tempInt = object.getYPos();
            fwrite(&tempInt, sizeof(int32_t), 1, file);
            tempInt = object.getZPos();
            fwrite(&tempInt, sizeof(int32_t), 1, file);

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

            //physical properties
            fwrite(object.getPhysicalProperties(), sizeof(PhysicalProperties), 1, file);
        }
    }

    void Scene3D::loadTxtObject(const Win32::Win32FileTxt& file) {

        std::string line;
        Object3D tempObject;
        Mesh3D tempMesh;
        Material tempMaterial;

        //1 - name
        line = file.readLine().value();
        for(auto & object : m_objects){
            if(object.getName() == line){
                RAL_LOG_INFO("Entity %s already in scene; won't be added", object.getName().c_str());
                for(int i = 0; i < 11; i++){
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
            addMesh(tempMesh);
            tempObject.setMesh(endMesh().base());
            tempObject.getMesh()->Mesh::openRalms(line);
        }

        //3 - material
        line = file.readLine().value();
        tempObject.setMaterial(nullptr);

        // optimization: if material was used, point to the already loaded one
        for(auto & material : m_materials){
            if(material.getPath() == line){
                tempObject.setMaterial(&material);
                break;
            }
        }

        if(!tempObject.getMaterial()){
            addMaterial(tempMaterial);
            tempObject.setMaterial(endMaterial().base());
            tempObject.getMaterial()->openRalmt(line);
        }

        //4, 5, 6 - position
        tempObject.setXPos(std::stoi(file.readLine().value()));
        tempObject.setYPos(std::stoi(file.readLine().value()));
        tempObject.setZPos(std::stoi(file.readLine().value()));

        //7, 8, 9 - rotation
        tempObject.setXRot(std::stof(file.readLine().value()));
        tempObject.setYRot(std::stof(file.readLine().value()));
        tempObject.setZRot(std::stof(file.readLine().value()));

        //10, 11, 12 - bounding box scale
        tempObject.setXBoxScale(std::stof(file.readLine().value()));
        tempObject.setYBoxScale(std::stof(file.readLine().value()));
        tempObject.setZBoxScale(std::stof(file.readLine().value()));

        //total: 12 lines -> need to skip 11
        addObject(tempObject);
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

    void Scene3D::addObject(Object3D object) {
        for(auto & m_object : m_objects){
            if(object.getName() == m_object.getName()){
                RAL_LOG_ERROR("Object %s already in scene, won't be added", object.getName().c_str());
                return;
            }
        }
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

    void Scene3D::addCamera(Camera3D camera) {
        for(auto & m_camera : m_cameras){
            if(m_camera.getName() == camera.getName()){
                RAL_LOG_ERROR("Camera %s already in scene, won't be added", camera.getName().c_str());
                return;
            }
        }
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
        RAL_LOG_ERROR("Camera %s not found", name.c_str());
    }

    Camera3D *Scene3D::getCamera(const std::string& name) {
        for(auto i = beginCamera(); i < endCamera(); i++){
            if(i->getName() == name){
                return i.base();
            }
        }
        RAL_LOG_ERROR("Camera %s not found", name.c_str());
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
        addCamera(tempCamera);
    }

    void Scene3D::loadBinMeshes(FILE *file) {

        size_t meshCount;
        void* buffer;
        size_t tempSize;
        Mesh3D tempMesh;

        //number of meshes
        fread(&meshCount, sizeof(size_t), 1, file);

        for(size_t i = 0; i < meshCount; i++){
            addMesh(tempMesh);

            //length of c string
            fread(&tempSize, sizeof(size_t), 1, file);

            //c string path
            buffer = new char[tempSize];
            fread(buffer, sizeof(char), tempSize, file);
            endMesh().base()->Mesh::openRalms(reinterpret_cast<char*>(buffer));
            delete[] reinterpret_cast<char*>(buffer);
        }
    }

    void Scene3D::addMesh(Mesh3D mesh) {
        for(auto & m_mesh : m_meshes){
            if(m_mesh.getPath() == mesh.getPath()){
                RAL_LOG_ERROR("Mesh with the path %s already in scene, won't be added", mesh.getPath().c_str());
                return;
            }
        }
        m_meshes.push_back(mesh);
    }

    void Scene3D::saveBinMeshes(FILE *file) {

        size_t tempSize;

        //number of meshes
        tempSize = getMeshCount();
        fwrite(&tempSize, sizeof(size_t), 1, file);

        for(auto & mesh : m_meshes){

            //length of c string
            tempSize = mesh.getPath().size();
            fwrite(&tempSize, sizeof(size_t), 1, file);

            //c string path
            fwrite(mesh.getPath().c_str(), sizeof(char), tempSize, file);
        }
    }

    void Scene3D::saveBinCameras(FILE *file) {

        size_t tempSize;
        int32_t tempInt;
        float tempFloat;
        Camera3D::Projection tempProjection;

        //number of cameras
        tempSize = getCameraCount();
        fwrite(&tempSize, sizeof(size_t), 1, file);

        for(auto & camera : m_cameras){

            //length of c string
            tempSize = camera.getName().size() + 1;
            fwrite(&tempSize, sizeof(size_t), 1, file);

            //c string name
            fwrite(camera.getName().c_str(), sizeof(char), tempSize, file);

            //position of camera
            tempInt = camera.getXPos();
            fwrite(&tempInt, sizeof(int32_t), 1, file);
            tempInt = camera.getYPos();
            fwrite(&tempInt, sizeof(int32_t), 1, file);
            tempInt = camera.getZPos();
            fwrite(&tempInt, sizeof(int32_t), 1, file);

            //rotation of camera
            tempFloat = camera.getXRot();
            fwrite(&tempFloat, sizeof(float), 1, file);
            tempFloat = camera.getYRot();
            fwrite(&tempFloat, sizeof(float), 1, file);
            tempFloat = camera.getZRot();
            fwrite(&tempFloat, sizeof(float), 1, file);

            //width
            tempInt = camera.getWidth();
            fwrite(&tempInt, sizeof(int16_t), 1, file);

            //projection
            tempProjection = camera.getProjection();
            fwrite(&tempProjection, sizeof(Camera3D::Projection), 1, file);
        }
    }

    void Scene3D::loadBinCameras(FILE *file) {

        size_t nOfCameras;
        size_t tempSize;
        void* buffer;
        Camera3D tempCamera;
        int32_t tempInt;
        float tempFloat;
        Camera3D::Projection tempProjection;

        //number of cameras
        fread(&nOfCameras, sizeof(size_t), 1, file);

        for(size_t i = 0; i < nOfCameras; i++){

            addCamera(tempCamera);

            //length of c string
            fread(&tempSize, sizeof(size_t), 1, file);

            //c string name
            buffer = new char[tempSize];
            fread(buffer, sizeof(char), tempSize, file);
            endCamera().base()->setName(reinterpret_cast<char*>(buffer));
            delete[] reinterpret_cast<char*>(buffer);

            //position of camera
            fread(&tempInt, sizeof(int32_t), 1, file);
            endCamera().base()->setXPos(tempInt);
            fread(&tempInt, sizeof(int32_t), 1, file);
            endCamera().base()->setYPos(tempInt);
            fread(&tempInt, sizeof(int32_t), 1, file);
            endCamera().base()->setZPos(tempInt);

            //rotation of camera
            fread(&tempFloat, sizeof(float), 1, file);
            endCamera().base()->setXRot(tempFloat);
            fread(&tempFloat, sizeof(float), 1, file);
            endCamera().base()->setYRot(tempFloat);
            fread(&tempFloat, sizeof(float), 1, file);
            endCamera().base()->setZRot(tempFloat);

            //width
            fread(&tempInt, sizeof(int16_t), 1, file);
            endCamera().base()->setWidth(tempInt);

            //projection
            fread(&tempProjection, sizeof(Camera3D::Projection), 1, file);
            endCamera().base()->setProjection(tempProjection);
        }
    }

    uint16_t Scene3D::getCameraCount() {
        return m_cameras.size();
    }

    void Scene3D::addMaterial(Material material) {
        for(auto & m_material : m_materials){
            if(material.getPath() == m_material.getPath()){
                RAL_LOG_ERROR("Material with the path %s already in scene, won't be added", material.getPath().c_str());
                return;
            }
        }
        m_materials.push_back(material);
    }

    void Scene3D::saveBinMaterials(FILE *file) {

        size_t tempSize;

        //number of materials
        tempSize = getMaterialCount();
        fwrite(&tempSize, sizeof(size_t), 1, file);

        for(auto & material : m_materials){

            //length of c string
            tempSize = material.getPath().size();
            fwrite(&tempSize, sizeof(size_t), 1, file);

            //c string path
            fwrite(material.getPath().c_str(), sizeof(char), tempSize, file);
        }
    }

    void Scene3D::loadBinMaterials(FILE *file) {

        size_t materialCount;
        void* buffer;
        size_t tempSize;
        Material tempMaterial;

        //number of materials
        fread(&materialCount, sizeof(size_t), 1, file);

        for(size_t i = 0; i < materialCount; i++){
            addMaterial(tempMaterial);

            //length of c string
            fread(&tempSize, sizeof(size_t), 1, file);

            //c string path
            buffer = new char[tempSize];
            fread(buffer, sizeof(char), tempSize, file);
            endMaterial().base()->openRalmt(reinterpret_cast<char*>(buffer));
            delete[] reinterpret_cast<char*>(buffer);
        }
    }

    void Scene3D::loadTextures() {

        //todo: way for the user to load mirrored textures
        Texture tempTexture;

        for(auto i = beginMaterial(); i < endMaterial(); i++){
            if(!i->getTexture()){
                m_textures.push_back(tempTexture);
                i->setTexture(endTexture().base());
                if(i->getMirrorFlag()){
                    i->getTexture()->stbiLoadFlippedTexture(i->getTexturePath());
                }
                else{
                    i->getTexture()->stbiLoadTexture(i->getTexturePath());
                }
                for(auto j = i + 1; j < endMaterial(); j++){
                    if(i->getTexturePath() == j->getTexturePath()){
                        j->setTexture(i->getTexture());
                    }
                }
            }
        }
    }

    Material *Scene3D::getMaterial(const std::string &path) {
        for(auto i = beginMaterial(); i < endMaterial(); i++){
            if(i->getPath() == path){
                return i.base();
            }
        }
        RAL_LOG_ERROR("Material with the path %s not found", path.c_str());
        return nullptr;
    }

    Camera3D *Scene3D::getActiveCamera() {
        return m_activeCamera;
    }

    void Scene3D::setActiveCamera(const std::string &name) {
        for(auto i = beginCamera(); i < endCamera(); i++){
            if(i->getName() == name){
                setActiveCamera(i);
                return;
            }
        }
        RAL_LOG_ERROR("Camera %s not found", name.c_str());
    }

    void Scene3D::setActiveCamera(uint16_t index) {
        setActiveCamera(beginCamera() + index);
    }

    void Scene3D::setActiveCamera(std::vector<Camera3D>::iterator iterator) {
        if(iterator > endCamera()){
            iterator = endCamera();
        }
        if(iterator < beginCamera()){
            iterator = beginCamera();
        }
        m_activeCamera = iterator.base();
    }
} // RAL
