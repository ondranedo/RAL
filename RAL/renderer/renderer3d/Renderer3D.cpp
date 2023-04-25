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
#include "Renderer3D.h"

namespace RAL {
    void Renderer3D::init() {
    }

    void Renderer3D::release() {

    }

    void Renderer3D::update() {

    }

    void Renderer3D::renderLoop() {

    }

    void Renderer3D::setScene(Scene3D *scene) {
        if(scene == nullptr)
            m_activeScene = scene;
        else
        {
            RAL_LOG_ERROR("Scene is not nullptr");
        }
    }

    void Renderer3D::clearScene() {
        m_activeScene = nullptr;
    }
} // RAL