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

#include "Entity3D.h"

namespace RAL{

    Entity3D::Entity3D() = default;

    Entity3D::~Entity3D() = default;

    int32_t Entity3D::getZPos() const {
        return m_zPos;
    }

    void Entity3D::setZPos(int32_t value) {
        m_zPos = value;
    }
}
