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
#ifndef RAL_PROJECT_SCENE_H
#define RAL_PROJECT_SCENE_H

#include <vector>
#include <string>
#include "../entity/Object3D.h"
#include "../../platfomLayer/windows/file/Win32FileTxt.h"
#include "../entity/Camera3D.h"

//maybe load all assests used in the scene first
//each object will then have indexes to the mesh/material vector

namespace RAL {
    class Scene3D {
    public:
        Scene3D();
        ~Scene3D();

        void loadTxtScene(const std::string& scenePath);
        void loadTxtObject(const Win32::Win32FileTxt& file);
        void loadTxtCamera(const Win32::Win32FileTxt& file);

        void loadBinScene(const std::string& scenePath);
        void loadBinObjects(FILE* file);
        void loadBinMeshes(FILE* file);
        void loadBinMaterials(FILE* file);
        void loadBinCameras(FILE* file);

        void loadTextures();

        void saveBinScene(const std::string& scenePath);
        void saveBinObjects(FILE* file);
        void saveBinMeshes(FILE* file);
        void saveBinMaterials(FILE* file);
        void saveBinCameras(FILE* file);

//TODO: some O(1) or less than O(n) solution for getting at least objects
        void addObject(Object3D object);
        void deleteObject(std::vector<Object3D>::iterator iterator);
        void deleteObject(int32_t index);
        void deleteObject(const std::string& name);
        Object3D* getObject(const std::string& name);
        uint32_t getObjectCount();
        std::vector<Object3D>::iterator beginObject();
        std::vector<Object3D>::iterator endObject();

        void addMesh(Mesh3D mesh);
        Mesh3D* getMesh(const std::string& path);
        uint32_t getMeshCount();
        std::vector<Mesh3D>::iterator beginMesh();
        std::vector<Mesh3D>::iterator endMesh();

        void addCamera(Camera3D camera);
        void deleteCamera(uint16_t index);
        void deleteCamera(std::vector<Camera3D>::iterator iterator);
        void deleteCamera(const std::string& name);
        Camera3D* getCamera(const std::string& name);
        uint16_t getCameraCount();
        std::vector<Camera3D>::iterator beginCamera();
        std::vector<Camera3D>::iterator endCamera();
        Camera3D* getActiveCamera();
        void setActiveCamera(uint16_t index);
        void setActiveCamera(std::vector<Camera3D>::iterator iterator);
        void setActiveCamera(const std::string& name);

        void addMaterial(Material material);
        Material* getMaterial(const std::string& path);
        uint32_t getMaterialCount();
        std::vector<Material>::iterator beginMaterial();
        std::vector<Material>::iterator endMaterial();

        uint32_t getTextureCount();
        std::vector<Texture>::iterator beginTexture();
        std::vector<Texture>::iterator endTexture();

    private:
//TODO: shaders
        std::vector<Object3D> m_objects;
        std::vector<Mesh3D> m_meshes;
        std::vector<Material> m_materials;
        std::vector<Texture> m_textures;
        std::vector<Camera3D> m_cameras;
        Camera3D* m_activeCamera{};
    };
} // RAL

#endif //!RAL_PROJECT_SCENE_H
