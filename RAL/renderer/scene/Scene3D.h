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

namespace RAL {
    class Scene3D {
    public:
        Scene3D();
        ~Scene3D();

        void loadTxtScene(const std::string& scenePath);
        void loadTxtObject(const Win32::Win32FileTxt& file);

        void loadBinScene(const std::string& scenePath);
        void loadBinObjects(FILE* file);

        void saveBinScene(const std::string& scenePath);
        void saveBinObjects(FILE* file);

    private:

        std::vector<Object3D> m_objects;
        std::vector<Mesh3D> m_meshes;
    };
} // RAL

#endif //!RAL_PROJECT_SCENE_H
