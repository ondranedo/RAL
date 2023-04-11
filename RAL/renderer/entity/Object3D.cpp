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

#include "Object3D.h"

namespace RAL{


    Object3D::Object3D() = default;

    Object3D::~Object3D() = default;

    Mesh3D *Object3D::getMesh() {
        return m_mesh;
    }

    void Object3D::setMesh(Mesh3D *mesh) {
        m_mesh = mesh;
    }

    void Object3D::setMesh(const std::string& path) {
        if(path.find("ral3d") != std::string::npos){
            m_mesh->openRalms(path);
        }
        else{
            m_mesh = nullptr;
        }
    }
}